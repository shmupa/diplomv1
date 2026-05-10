#pragma once
#include <cmath>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

public ref class Material
{
public:
    String^ Name;
    double Lambda;
    double ro;
    double C;
    double Alpha;
    double L;
    double T0;
    int NodesCount;
    double EndTime;

    Material(String^ name, double lambda, double density, double specificHeat, double alpha)
    {
        Name = name;
        Lambda = lambda;
        ro = density;
        C = specificHeat;
        Alpha = alpha;
        L = 1.0;
        T0 = 20.0;
        NodesCount = 512;
        EndTime = 660.0;
    }

    Material()
    {
        Name = "Сталь";
        Lambda = 33;
        ro = 7710;
        C = 496;
        Alpha = 15.536;
        L = 1.0;
        T0 = 20.0;
        NodesCount = 512;
        EndTime = 660.0;
    }

    double GetThermalDiffusivity()
    {
        return Lambda / (ro * C);
    }

    static Material^ CreateSteel()
    {
        return gcnew Material("Сталь", 33, 7710, 496, 15.536);
    }
};

public ref class RodSegment
{
public:
    Material^ Mat;
    double Length;
    int NodesCount;

    RodSegment(Material^ mat, double length, int nodesCount)
    {
        Mat = mat;
        Length = length;
        NodesCount = nodesCount;
    }
};

enum class BoundaryConditionType
{
    FirstKind,
    SecondKind,
    ThirdKind
};

public ref class BoundaryCondition
{
public:
    BoundaryConditionType Type;
    String^ Description;
    double Value1;
    double Value2;

    BoundaryCondition(BoundaryConditionType type, double value1)
    {
        Type = type;
        Value1 = value1;
        Value2 = 0.0;

        if (type == BoundaryConditionType::FirstKind)
            Description = "1 род: T = " + Value1.ToString("F2") + " C";
        else
            Description = "ГУ";
    }

    BoundaryCondition(BoundaryConditionType type, double value1, bool)
    {
        Type = type;
        Value1 = value1;
        Value2 = 0.0;

        if (type == BoundaryConditionType::SecondKind)
            Description = "2 род: q = " + Value1.ToString("F2") + " Вт/м^2";
        else
            Description = "ГУ";
    }

    BoundaryCondition(BoundaryConditionType type, double value1, double value2)
    {
        Type = type;
        Value1 = value1;
        Value2 = value2;

        if (type == BoundaryConditionType::ThirdKind)
            Description = "3 род: alpha = " + Value1.ToString("F2") + ", Tср = " + Value2.ToString("F2") + " C";
        else
            Description = "ГУ";
    }

    virtual String^ ToString() override
    {
        return Description;
    }
};

public ref class Node
{
public:
    int Index;
    double X;
    double T;
    Material^ CurrentMaterial;
    int SegmentIndex;

    Node(int index, double x, double temperature)
    {
        Index = index;
        X = x;
        T = temperature;
        CurrentMaterial = nullptr;
        SegmentIndex = -1;
    }

    Node(int index, double x, double temperature, Material^ material, int segmentIndex)
    {
        Index = index;
        X = x;
        T = temperature;
        CurrentMaterial = material;
        SegmentIndex = segmentIndex;
    }

    void SetTemperature(double temperature)
    {
        T = temperature;
    }
};

public ref class Solution
{
private:
    array<Node^>^ nodes;
    List<RodSegment^>^ segments;
    BoundaryCondition^ leftBoundary;
    BoundaryCondition^ rightBoundary;
    double initialTemperature;
    double endTime;
    double userTau;
    bool useUserTau;

    double lastTau;
    double lastH;
    double lastElapsedMs;
    int lastTimeSteps;
    int lastNodeCount;
    int jacobiIter;
    int lastCNIterations;

private:
    void unified_mesh()
    {
        if (segments == nullptr || segments->Count == 0)
            throw gcnew Exception("Не задано ни одного материала.");

        List<Node^>^ nodeList = gcnew List<Node^>();
        int globalIndex = 0;
        double xOffset = 0.0;

        //левый граничный узел первого сегмента
        RodSegment^ firstSeg = segments[0];
        nodeList->Add(gcnew Node(globalIndex++, 0.0, initialTemperature, firstSeg->Mat, 0));

        for (int s = 0; s < segments->Count; s++) {
            RodSegment^ seg = segments[s];
            double h = seg->Length / (seg->NodesCount + 1.0);
            for (int i = 1; i <= seg->NodesCount; i++) {
                double x = xOffset + i * h;
                nodeList->Add(gcnew Node(globalIndex++, x, initialTemperature, seg->Mat, s));
            }
            xOffset += seg->Length;
            //узел контакта между сегментами
            if (s < segments->Count - 1) {
                Material^ nextMat = segments[s + 1]->Mat;
                nodeList->Add(gcnew Node(globalIndex++, xOffset, initialTemperature, nextMat, s + 1));
            }
        }
        //правый граничный узел
        RodSegment^ lastSeg = segments[segments->Count - 1];
        nodeList->Add(gcnew Node(globalIndex++, xOffset, initialTemperature, lastSeg->Mat, segments->Count - 1));
        nodes = nodeList->ToArray();
        lastNodeCount = nodes->Length;
    }

    double leftdistance(int i)
    {
        return nodes[i]->X - nodes[i - 1]->X;
    }

    double rightdistance(int i)
    {
        return nodes[i + 1]->X - nodes[i]->X;
    }

    double lambdabetween(Material^ leftMat, Material^ rightMat)
    {
        if (leftMat == nullptr || rightMat == nullptr)
            throw gcnew Exception("Материал в узле не задан.");

        if (Math::Abs(leftMat->Lambda - rightMat->Lambda) < 1e-12)
            return leftMat->Lambda;

        return 2.0 * leftMat->Lambda * rightMat->Lambda / (leftMat->Lambda + rightMat->Lambda);
    }

    double CalculateExplicitTimeStep()
    {
        if (nodes == nullptr || nodes->Length < 3)
            throw gcnew Exception("Сетка не построена.");

        double minTau = Double::MaxValue;

        for (int i = 1; i < nodes->Length - 1; i++)
        {
            double dxL = leftdistance(i);
            double dxR = rightdistance(i);
            double dxMin = Math::Min(dxL, dxR);

            Material^ mat = nodes[i]->CurrentMaterial;
            double a = mat->Lambda / (mat->ro * mat->C);

            double tauLocal = 0.5 * dxMin * dxMin / a;
            if (tauLocal < minTau)
                minTau = tauLocal;
        }

        return minTau;
    }

    void Implicitcoeffnode(
        int i,
        double tau,
        double% aL,
        double% aP,
        double% aR,
        double% rhs)
    {
        Material^ leftMat = nodes[i - 1]->CurrentMaterial;
        Material^ centerMat = nodes[i]->CurrentMaterial;
        Material^ rightMat = nodes[i + 1]->CurrentMaterial;

        double dxL = leftdistance(i);
        double dxR = rightdistance(i);

        double lambdaL = lambdabetween(leftMat, centerMat);
        double lambdaR = lambdabetween(centerMat, rightMat);

        double controlVolume = 0.5 * (dxL + dxR);
        double rhoC = centerMat->ro * centerMat->C;

        aL = tau * lambdaL / (rhoC * controlVolume * dxL);
        aR = tau * lambdaR / (rhoC * controlVolume * dxR);
        aP = 1.0 + aL + aR;
        rhs = nodes[i]->T;
    }

    void ImplicitBC(
        array<double>^ al,
        array<double>^ ap,
        array<double>^ ar,
        array<double>^ b)
    {
        int last = nodes->Length - 1;

        //левое ГУ
        {
            Material^ mat0 = nodes[0]->CurrentMaterial;
            double dx = nodes[1]->X - nodes[0]->X;

            switch (leftBoundary->Type)
            {
            case BoundaryConditionType::FirstKind:
                al[0] = 0.0;
                ar[0] = 0.0;
                ap[0] = 1.0;
                b[0] = leftBoundary->Value1;
                break;

            case BoundaryConditionType::SecondKind:
                al[0] = 0.0;
                ar[0] = mat0->Lambda / dx;
                ap[0] = mat0->Lambda / dx;
                b[0] = leftBoundary->Value1;
                break;

            case BoundaryConditionType::ThirdKind:
                al[0] = 0.0;
                ar[0] = mat0->Lambda / dx;
                ap[0] = mat0->Lambda / dx + leftBoundary->Value1;
                b[0] = leftBoundary->Value1 * leftBoundary->Value2;
                break;
            }
        }

        //правое ГУ
        {
            Material^ matN = nodes[last]->CurrentMaterial;
            double dx = nodes[last]->X - nodes[last - 1]->X;

            switch (rightBoundary->Type)
            {
            case BoundaryConditionType::FirstKind:
                al[last] = 0.0;
                ar[last] = 0.0;
                ap[last] = 1.0;
                b[last] = rightBoundary->Value1;
                break;

            case BoundaryConditionType::SecondKind:
                al[last] = matN->Lambda / dx;
                ar[last] = 0.0;
                ap[last] = matN->Lambda / dx;
                b[last] = rightBoundary->Value1;
                break;

            case BoundaryConditionType::ThirdKind:
                al[last] = matN->Lambda / dx;
                ar[last] = 0.0;
                ap[last] = matN->Lambda / dx + rightBoundary->Value1;
                b[last] = rightBoundary->Value1 * rightBoundary->Value2;
                break;
            }
        }
    }

    void BCExplicit(array<double>^ TT)
    {
        int last = nodes->Length - 1;

        //левое ГУ
        {
            Material^ mat0 = nodes[0]->CurrentMaterial;
            double dx = nodes[1]->X - nodes[0]->X;

            switch (leftBoundary->Type)
            {
            case BoundaryConditionType::FirstKind:
                TT[0] = leftBoundary->Value1;
                break;

            case BoundaryConditionType::SecondKind:
                TT[0] = nodes[1]->T + leftBoundary->Value1 * dx / mat0->Lambda;
                break;

            case BoundaryConditionType::ThirdKind:
                TT[0] = (mat0->Lambda * nodes[1]->T + leftBoundary->Value1 * dx * leftBoundary->Value2)
                    / (mat0->Lambda + leftBoundary->Value1 * dx);
                break;

            default:
                throw gcnew Exception("Неподдерживаемый тип левого граничного условия.");
            }
        }

        //правое ГУ
        {
            Material^ matN = nodes[last]->CurrentMaterial;
            double dx = nodes[last]->X - nodes[last - 1]->X;

            switch (rightBoundary->Type)
            {
            case BoundaryConditionType::FirstKind:
                TT[last] = rightBoundary->Value1;
                break;

            case BoundaryConditionType::SecondKind:
                TT[last] = nodes[last - 1]->T + rightBoundary->Value1 * dx / matN->Lambda;
                break;

            case BoundaryConditionType::ThirdKind:
                TT[last] = (matN->Lambda * nodes[last - 1]->T + rightBoundary->Value1 * dx * rightBoundary->Value2)
                    / (matN->Lambda + rightBoundary->Value1 * dx);
                break;

            default:
                throw gcnew Exception("Неподдерживаемый тип правого граничного условия.");
            }
        }
    }

public:  Solution(List<RodSegment^>^ segs, BoundaryCondition^ leftBC, BoundaryCondition^ rightBC, double t0, double endT)
{
    segments = segs;
    leftBoundary = leftBC;
    rightBoundary = rightBC;
    initialTemperature = t0;
    endTime = endT;
    nodes = nullptr;
    lastTau = 0.0;
    lastH = 0.0;
    lastElapsedMs = 0.0;
    lastTimeSteps = 0;
    lastNodeCount = 0;
    jacobiIter = 0;
    lastCNIterations = 0;
    userTau = 0.0;
    useUserTau = false;
}

      array<Node^>^ GetAllNodes()
      {
          return nodes;
      }

      property double LastTau
      {
          double get() { return lastTau; }
      }
      property double LastH
      {
          double get() { return lastH; }
      }

      property double LastElapsedMs
      {
          double get() { return lastElapsedMs; }
      }
      property int LastTimeSteps
      {
          int get() { return lastTimeSteps; }
      }

      property int LastNodeCount
      {
          int get() { return lastNodeCount; }
      }

      property int JacobiIter
      {
          int get() { return jacobiIter; }
      }

      property int LastCNIterations
      {
          int get() { return lastCNIterations; }
      }

      String^ GetSolutionInfo()
      {
          double totalLength = 0.0;
          int totalNodes = 0;
          for each (RodSegment ^ seg in segments)
          {
              totalLength += seg->Length;
              totalNodes += seg->NodesCount;
          }

          return String::Format(
              "Сегментов: {0}\nОбщая длина: {1:F3} м\nОбщее число внутренних узлов: {2}\nНачальная температура: {3:F2}\nВремя расчета: {4:F2}",
              segments->Count, totalLength, totalNodes, initialTemperature, endTime);
      }

      void SetUserTau(double tau)
      {
          if (tau <= 0.0)
              throw gcnew Exception("Шаг по времени tau должен быть положительным.");

          userTau = tau;
          useUserTau = true;
      }

      void CalculateExplicitScheme() {
          unified_mesh();
          DateTime startTime = DateTime::Now;
          int size = nodes->Length;
          array<double>^ TT = gcnew array<double>(size);

          for (int i = 0; i < size; i++)
              TT[i] = nodes[i]->T;
          double stableTau = CalculateExplicitTimeStep();
          double tau = useUserTau ? userTau : stableTau;
          lastTau = tau;
          if (segments != nullptr && segments->Count > 0)
              lastH = segments[0]->Length / (segments[0]->NodesCount + 1.0);
          else
              lastH = 0.0;
          double time = 0.0;
          int timeSteps = 0;

          while (time < endTime)
          {
              double currentTau = tau;
              if (time + currentTau > endTime)
                  currentTau = endTime - time;

              BCExplicit(TT);

              for (int i = 1; i < size - 1; i++)
              {
                  Material^ leftMat = nodes[i - 1]->CurrentMaterial;
                  Material^ centerMat = nodes[i]->CurrentMaterial;
                  Material^ rightMat = nodes[i + 1]->CurrentMaterial;
                  double dxL = leftdistance(i);
                  double dxR = rightdistance(i);
                  double lambdaL = lambdabetween(leftMat, centerMat);
                  double lambdaR = lambdabetween(centerMat, rightMat);
                  double fluxL = lambdaL * (nodes[i - 1]->T - nodes[i]->T) / dxL;
                  double fluxR = lambdaR * (nodes[i + 1]->T - nodes[i]->T) / dxR;
                  double controlVolume = 0.5 * (dxL + dxR);
                  double rhoC = centerMat->ro * centerMat->C;

                  TT[i] = nodes[i]->T + currentTau * (fluxL + fluxR) / (rhoC * controlVolume);
              }

              for (int i = 0; i < size; i++)
                  nodes[i]->SetTemperature(TT[i]);

              time += currentTau;
              timeSteps++;
          }
          lastTimeSteps = timeSteps;
          lastElapsedMs = (DateTime::Now - startTime).TotalMilliseconds;
      }

      void CalculateImplicitScheme() {
          unified_mesh();
          DateTime startTime = DateTime::Now;
          int size = nodes->Length;
          int last = size - 1;
          array<double>^ T = gcnew array<double>(size);
          array<double>^ TT = gcnew array<double>(size);
          array<double>^ T1 = gcnew array<double>(size);
          array<double>^ ap = gcnew array<double>(size);
          array<double>^ ar = gcnew array<double>(size);
          array<double>^ al = gcnew array<double>(size);
          array<double>^ b = gcnew array<double>(size);

          for (int i = 0; i < size; i++)
          {
              T[i] = nodes[i]->T;
              TT[i] = nodes[i]->T;
              T1[i] = nodes[i]->T;
          }
          double stableTau = CalculateExplicitTimeStep();
          double tau = useUserTau ? userTau : stableTau;
          lastTau = tau;
          if (segments != nullptr && segments->Count > 0)
              lastH = segments[0]->Length / (segments[0]->NodesCount + 1.0);
          else
              lastH = 0.0;
          double time = 0.0;
          int timeSteps = 0;
          int totalJacobiIterations = 0;

          while (time < endTime)
          {
              double currentTau = tau;
              if (time + currentTau > endTime)
                  currentTau = endTime - time;

              time += currentTau;
              timeSteps++;

              for (int i = 1; i < last; i++)
              {
                  double aL, aP, aR, rhs;
                  Implicitcoeffnode(i, currentTau, aL, aP, aR, rhs);

                  al[i] = aL;
                  ap[i] = aP;
                  ar[i] = aR;
                  b[i] = rhs;
              }

              ImplicitBC(al, ap, ar, b);
              const double eps = 1e-9;
              const int max_iter = 50000;
              int iter = 0;
              double dTmax = eps + 1.0;
              while (dTmax > eps && iter < max_iter) {
                  dTmax = 0.0;
                  T1[0] = (b[0] + ar[0] * TT[1]) / ap[0];
                  for (int i = 1; i < last; i++) {
                      T1[i] = (b[i] + ar[i] * TT[i + 1] + al[i] * TT[i - 1]) / ap[i];
                  }

                  T1[last] = (b[last] + al[last] * TT[last - 1]) / ap[last];

                  for (int i = 0; i < size; i++) {
                      double diff = Math::Abs(T1[i] - TT[i]);
                      if (diff > dTmax)
                          dTmax = diff;
                  }

                  for (int i = 0; i < size; i++)
                      TT[i] = T1[i];

                  iter++;
              }

              totalJacobiIterations += iter;

              for (int i = 0; i < size; i++) {
                  T[i] = TT[i];
                  nodes[i]->SetTemperature(T[i]);
              }
          }

              lastTimeSteps = timeSteps;
              jacobiIter = totalJacobiIterations;
              lastElapsedMs = (DateTime::Now - startTime).TotalMilliseconds;
}

    void CalculateCNScheme() {
        unified_mesh();
        DateTime startTime = DateTime::Now;
        int size = nodes->Length;
        int last = size - 1;

        array<double>^ T = gcnew array<double>(size);
        array<double>^ T_new = gcnew array<double>(size);
        array<double>^ T_old = gcnew array<double>(size);
        array<double>^ b = gcnew array<double>(size);

        for (int i = 0; i < size; i++) {
            T[i] = nodes[i]->T;
            T_new[i] = nodes[i]->T;
            T_old[i] = nodes[i]->T;
        }
        double stableTau = CalculateExplicitTimeStep();
        double tau = useUserTau ? userTau : stableTau;
        lastTau = tau;
        if (segments != nullptr && segments->Count > 0)
            lastH = segments[0]->Length / (segments[0]->NodesCount + 1.0);
        else
            lastH = 0.0;
        double time = 0.0;
        int timeSteps = 0;
        int totalIterations = 0;

        while (time < endTime) {
            double currentTau = tau;
            if (time + currentTau > endTime)
                currentTau = endTime - time;

            time += currentTau;
            timeSteps++;

            //правая часть
            switch (leftBoundary->Type) {
            case BoundaryConditionType::FirstKind:
                b[0] = leftBoundary->Value1;
                break;
            case BoundaryConditionType::SecondKind:
                b[0] = leftBoundary->Value1;
                break;
            case BoundaryConditionType::ThirdKind:
                b[0] = leftBoundary->Value1 * leftBoundary->Value2;
                break;
            }

            for (int i = 1; i < last; i++) {
                Material^ leftMat = nodes[i - 1]->CurrentMaterial;
                Material^ centerMat = nodes[i]->CurrentMaterial;
                Material^ rightMat = nodes[i + 1]->CurrentMaterial;
                double dxL = leftdistance(i);
                double dxR = rightdistance(i);
                double lambdaL = lambdabetween(leftMat, centerMat);
                double lambdaR = lambdabetween(centerMat, rightMat);
                double controlVolume = 0.5 * (dxL + dxR);
                double rhoC = centerMat->ro * centerMat->C;
                double gammaL = currentTau * lambdaL / (2.0 * rhoC * controlVolume * dxL);
                double gammaR = currentTau * lambdaR / (2.0 * rhoC * controlVolume * dxR);
                b[i] = (1.0 - gammaL - gammaR) * T[i] + gammaL * T[i - 1] + gammaR * T[i + 1];
            }

            switch (rightBoundary->Type)
            {
            case BoundaryConditionType::FirstKind:
                b[last] = rightBoundary->Value1;
                break;
            case BoundaryConditionType::SecondKind:
                b[last] = rightBoundary->Value1;
                break;
            case BoundaryConditionType::ThirdKind:
                b[last] = rightBoundary->Value1 * rightBoundary->Value2;
                break;
            }

            for (int i = 0; i < size; i++)
            {
                T_new[i] = T[i];
                T_old[i] = T[i];
            }

            const double eps = 1e-8;
            const int max_iter = 50000;
            int iter = 0;
            double dTmax = eps + 1.0;

            while (dTmax > eps && iter < max_iter)
            {
                dTmax = 0.0;

                {
                    Material^ mat0 = nodes[0]->CurrentMaterial;
                    double dx = nodes[1]->X - nodes[0]->X;

                    switch (leftBoundary->Type)
                    {
                    case BoundaryConditionType::FirstKind:
                        T_new[0] = b[0];
                        break;
                    case BoundaryConditionType::SecondKind:
                        T_new[0] = (b[0] + (mat0->Lambda / dx) * T_old[1]) / (mat0->Lambda / dx);
                        break;
                    case BoundaryConditionType::ThirdKind:
                        T_new[0] = (b[0] + (mat0->Lambda / dx) * T_old[1]) /
                            (mat0->Lambda / dx + leftBoundary->Value1);
                        break;
                    }
                }

                for (int i = 1; i < last; i++)
                {
                    Material^ leftMat = nodes[i - 1]->CurrentMaterial;
                    Material^ centerMat = nodes[i]->CurrentMaterial;
                    Material^ rightMat = nodes[i + 1]->CurrentMaterial;

                    double dxL = leftdistance(i);
                    double dxR = rightdistance(i);

                    double lambdaL = lambdabetween(leftMat, centerMat);
                    double lambdaR = lambdabetween(centerMat, rightMat);

                    double controlVolume = 0.5 * (dxL + dxR);
                    double rhoC = centerMat->ro * centerMat->C;

                    double gammaL = currentTau * lambdaL / (2.0 * rhoC * controlVolume * dxL);
                    double gammaR = currentTau * lambdaR / (2.0 * rhoC * controlVolume * dxR);

                    T_new[i] = (b[i] + gammaL * T_old[i - 1] + gammaR * T_old[i + 1]) / (1.0 + gammaL + gammaR);
                }
                {
                    Material^ matN = nodes[last]->CurrentMaterial;
                    double dx = nodes[last]->X - nodes[last - 1]->X;

                    switch (rightBoundary->Type) {
                    case BoundaryConditionType::FirstKind:
                        T_new[last] = b[last];
                        break;
                    case BoundaryConditionType::SecondKind:
                        T_new[last] = (b[last] + (matN->Lambda / dx) * T_old[last - 1]) / (matN->Lambda / dx);
                        break;
                    case BoundaryConditionType::ThirdKind:
                        T_new[last] = (b[last] + (matN->Lambda / dx) * T_old[last - 1]) / (matN->Lambda / dx + rightBoundary->Value1);
                        break;
                    }
                }

                for (int i = 0; i < size; i++) {
                    double diff = Math::Abs(T_new[i] - T_old[i]);
                    if (diff > dTmax)
                        dTmax = diff;
                }
                for (int i = 0; i < size; i++)
                    T_old[i] = T_new[i];
                iter++;
            }
            totalIterations += iter;
            for (int i = 0; i < size; i++)  {
                T[i] = T_new[i];
                nodes[i]->SetTemperature(T[i]);
            }
        }

        lastTimeSteps = timeSteps;
        lastCNIterations = totalIterations;
        lastElapsedMs = (DateTime::Now - startTime).TotalMilliseconds;
    }

    void SaveToCSV(String^ filename)
    {
        try
        {
            if (nodes == nullptr || nodes->Length == 0)
                throw gcnew Exception("Нет рассчитанных данных для сохранения.");
            StreamWriter^ sw = gcnew StreamWriter(filename, false, System::Text::Encoding::UTF8);
            sw->WriteLine("X;Explicit");
            for (int i = 0; i < nodes->Length; i++) {
                sw->WriteLine(String::Format("{0:F6};{1:F6}", nodes[i]->X, nodes[i]->T));
            }
            sw->Close();
        }
        catch (Exception^ ex)
        {
            throw gcnew Exception("Ошибка сохранения CSV: " + ex->Message);
        }
    }
};