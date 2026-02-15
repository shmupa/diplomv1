#pragma once

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
        T0 = 20;
        NodesCount = 100;
        EndTime = 660;
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

enum class BoundaryConditionType {
    FirstKind,
    SecondKind,
    ThirdKind,
    FourthKind
};

public ref class BoundaryCondition
{
public:
    BoundaryConditionType Type;
    String^ Description;
    double Value1;
    double Value2;
    Material^ ContactMaterial;

    BoundaryCondition(BoundaryConditionType type, double temperature)
    {
        Type = type;
        Value1 = temperature;
        Value2 = 0.0;
        ContactMaterial = nullptr;
        Description = "1 род: T = " + Value1.ToString("F1") + "C";
    }

    BoundaryCondition(BoundaryConditionType type, double heatFlux, bool isSecondKind)
    {
        Type = type;
        Value1 = heatFlux;
        Value2 = 0.0;
        ContactMaterial = nullptr;
        Description = "2 род: q = " + Value1.ToString("F1") + " Вт/м^2";
    }

    BoundaryCondition(BoundaryConditionType type, double heatTransferCoeff, double environmentTemp)
    {
        Type = type;
        Value1 = heatTransferCoeff;
        Value2 = environmentTemp;
        ContactMaterial = nullptr;
        Description = "3 род: alpha = " + Value1.ToString("F1") + ", Tср = " + Value2.ToString("F1") + "C";
    }

    BoundaryCondition(BoundaryConditionType type, double contactTemp, Material^ contactMaterial)
    {
        Type = type;
        Value1 = contactTemp;
        Value2 = 0.0;
        ContactMaterial = contactMaterial;
        Description = "4 род: Tконт = " + Value1.ToString("F1") + "C (" + contactMaterial->Name + ")";
    }

    BoundaryCondition()
    {
        Type = BoundaryConditionType::FirstKind;
        Value1 = 20.0;
        Value2 = 0.0;
        ContactMaterial = nullptr;
        Description = "1 род: T = 20.0";
    }

    virtual String^ ToString() override
    {
        return Description;
    }
};

public ref class CompositeRod
{
public:
    Material^ MainMaterial;
    Material^ LeftContactMaterial;
    Material^ RightContactMaterial;
    double L;
    double ContactLength;

    CompositeRod(Material^ mainMat, Material^ leftContact, Material^ rightContact, double length, double contactLen)
    {
        MainMaterial = mainMat;
        LeftContactMaterial = leftContact;
        RightContactMaterial = rightContact;
        L = length;
        ContactLength = contactLen;
    }
};

public ref class Node
{
public:
    int Index;
    double X;
    double T;
    Material^ CurrentMaterial;

    Node(int index, double x, double temperature)
    {
        Index = index;
        X = x;
        T = temperature;
        CurrentMaterial = nullptr;
    }

    Node(int index, double x, double temperature, Material^ material)
    {
        Index = index;
        X = x;
        T = temperature;
        CurrentMaterial = material;
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
    Material^ material;
    BoundaryCondition^ leftBoundary;
    BoundaryCondition^ rightBoundary;
    CompositeRod^ compositeRod;

    void InitializeNodes()
    {
        nodes = gcnew array<Node^>(NodesCount + 2);
        double h = L / (NodesCount + 1);
        for (int i = 0; i <= NodesCount + 1; i++)
        {
            nodes[i] = gcnew Node(i, i * h, T0);
        }
    }

    void ApplyBoundaryCondition(BoundaryCondition^ bc, array<double>^ TT, int index, double h, bool isLeft)
    {
        switch (bc->Type)
        {
        case BoundaryConditionType::FirstKind:
            TT[index] = bc->Value1;
            break;
        case BoundaryConditionType::SecondKind:
            if (isLeft)
                TT[index] = nodes[index + 1]->T - bc->Value1 * h / material->Lambda;
            else
                TT[index] = nodes[index - 1]->T + bc->Value1 * h / material->Lambda;
            break;
        case BoundaryConditionType::ThirdKind:
            if (isLeft)
                TT[index] = (material->Lambda * nodes[1]->T + bc->Value1 * h * bc->Value2)
                / (material->Lambda + bc->Value1 * h);
            else
                TT[index] = (material->Lambda * nodes[NodesCount]->T + bc->Value1 * h * bc->Value2)
                / (material->Lambda + bc->Value1 * h);
            break;
        }
    }

    double CalculateTimeStep()
    {
        double h = L / (NodesCount + 1);
        double minAlpha = material->GetThermalDiffusivity();

        if (compositeRod != nullptr && compositeRod->LeftContactMaterial != nullptr)
            minAlpha = Math::Min(minAlpha, compositeRod->LeftContactMaterial->GetThermalDiffusivity());
        if (compositeRod != nullptr && compositeRod->RightContactMaterial != nullptr)
            minAlpha = Math::Min(minAlpha, compositeRod->RightContactMaterial->GetThermalDiffusivity());

        return 0.3 * h * h / minAlpha;
    }

    void ApplyCompositeBoundaryConditions(array<double>^ TT, double h, double tau)
    {
        ApplyBoundaryCondition(leftBoundary, TT, 0, h, true);
        ApplyBoundaryCondition(rightBoundary, TT, NodesCount + 1, h, false);
    }

public:
    property double L{
        double get() { return material->L; }
        void set(double value) { material->L = value; }
    }

    property double T0{
        double get() { return material->T0; }
        void set(double value) { material->T0 = value; }
    }

    property int NodesCount{
        int get() { return material->NodesCount; }
        void set(int value) { material->NodesCount = value; }
    }

    property double EndTime{
        double get() { return material->EndTime; }
        void set(double value) { material->EndTime = value; }
    }

    property Material^ CurrentMaterial{
        Material ^ get() { return material; }
        void set(Material ^ value) { material = value; }
    }

    property BoundaryCondition^ LeftBoundary{
        BoundaryCondition ^ get() { return leftBoundary; }
        void set(BoundaryCondition ^ value) { leftBoundary = value; }
    }

    property BoundaryCondition^ RightBoundary{
        BoundaryCondition ^ get() { return rightBoundary; }
        void set(BoundaryCondition ^ value) { rightBoundary = value; }
    }

    property CompositeRod^ Rod{
        CompositeRod ^ get() { return compositeRod; }
        void set(CompositeRod ^ value) { compositeRod = value; }
    }

    Solution(Material^ mat, BoundaryCondition^ leftBC, BoundaryCondition^ rightBC)
    {
        material = mat;
        leftBoundary = leftBC;
        rightBoundary = rightBC;
        compositeRod = nullptr;
    }

    Solution(Material^ mat, BoundaryCondition^ leftBC, BoundaryCondition^ rightBC, CompositeRod^ rod)
    {
        material = mat;
        leftBoundary = leftBC;
        rightBoundary = rightBC;
        compositeRod = rod;
    }

    Solution(Material^ mat)
    {
        material = mat;
        leftBoundary = gcnew BoundaryCondition(BoundaryConditionType::ThirdKind, 25.0, 200.0);
        rightBoundary = gcnew BoundaryCondition(BoundaryConditionType::FirstKind, 20.0);
        compositeRod = nullptr;
    }

    void CalculateExplicitScheme()
    {
        InitializeNodes();

        double h = L / (NodesCount + 1);
        double a = material->GetThermalDiffusivity();
        double tau = 0.5 * h * h / a;

        array<double>^ TT = gcnew array<double>(NodesCount + 2);

        for (int i = 0; i <= NodesCount + 1; i++)
        {
            TT[i] = nodes[i]->T;
        }

        double time = 0;

        while (time < EndTime)
        {
            time += tau;

            ApplyBoundaryCondition(leftBoundary, TT, 0, h, true);
            ApplyBoundaryCondition(rightBoundary, TT, NodesCount + 1, h, false);

            for (int i = 1; i <= NodesCount; i++)
            {
                TT[i] = nodes[i]->T + a * tau / (h * h) *
                    (nodes[i + 1]->T - 2 * nodes[i]->T + nodes[i - 1]->T);
            }

            for (int i = 0; i <= NodesCount + 1; i++)
            {
                nodes[i]->SetTemperature(TT[i]);
            }
        }
    }

    void CalculateImplicitScheme()
    {
        InitializeNodes();

        double h = L / (NodesCount + 1);
        double a = material->GetThermalDiffusivity();
        double tau = 0.5 * h * h / a;

        array<double>^ T = gcnew array<double>(NodesCount + 2);
        array<double>^ TT = gcnew array<double>(NodesCount + 2);
        array<double>^ T1 = gcnew array<double>(NodesCount + 2);

        array<double>^ ap = gcnew array<double>(NodesCount + 2);
        array<double>^ ar = gcnew array<double>(NodesCount + 2);
        array<double>^ al = gcnew array<double>(NodesCount + 2);
        array<double>^ b = gcnew array<double>(NodesCount + 2);

        for (int i = 0; i <= NodesCount + 1; i++)
        {
            T[i] = nodes[i]->T;
            TT[i] = nodes[i]->T;
            T1[i] = nodes[i]->T;
        }

        double time = 0;
        while (time < EndTime)
        {
            time += tau;

            for (int i = 1; i <= NodesCount; i++)
            {
                ar[i] = (a * tau) / (h * h);
                al[i] = (a * tau) / (h * h);
                ap[i] = 1 + al[i] + ar[i];
                b[i] = T[i];
            }

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
                ar[0] = 1.0;
                ap[0] = 1.0;
                b[0] = leftBoundary->Value1 * h / material->Lambda;
                break;

            case BoundaryConditionType::ThirdKind:
                al[0] = 0.0;
                ar[0] = material->Lambda / h;
                ap[0] = material->Lambda / h + leftBoundary->Value1;
                b[0] = leftBoundary->Value1 * leftBoundary->Value2;
                break;
            }

            switch (rightBoundary->Type)
            {
            case BoundaryConditionType::FirstKind:
                al[NodesCount + 1] = 0.0;
                ar[NodesCount + 1] = 0.0;
                ap[NodesCount + 1] = 1.0;
                b[NodesCount + 1] = rightBoundary->Value1;
                break;

            case BoundaryConditionType::SecondKind:
                al[NodesCount + 1] = 1.0;
                ar[NodesCount + 1] = 0.0;
                ap[NodesCount + 1] = 1.0;
                b[NodesCount + 1] = rightBoundary->Value1 * h / material->Lambda;
                break;

            case BoundaryConditionType::ThirdKind:
                al[NodesCount + 1] = material->Lambda / h;
                ar[NodesCount + 1] = 0.0;
                ap[NodesCount + 1] = material->Lambda / h + rightBoundary->Value1;
                b[NodesCount + 1] = rightBoundary->Value1 * rightBoundary->Value2;
                break;
            }

            double dTmax;
            const double eps = 1e-9;
            int k = 0;
            const int max_iter = 1000;
            dTmax = eps + 1;

            while (dTmax > eps && k < max_iter)
            {
                dTmax = 0.0;
                
                T1[0] = (b[0] + ar[0] * TT[1]) / ap[0];
                
                for (int i = 1; i <= NodesCount; i++)
                {
                    T1[i] = (b[i] + ar[i] * TT[i + 1] + al[i] * TT[i - 1]) / ap[i];
                }
                
                T1[NodesCount + 1] = (b[NodesCount + 1] + al[NodesCount + 1] * TT[NodesCount]) / ap[NodesCount + 1];
                
                for (int i = 0; i <= NodesCount + 1; i++)
                {
                    dTmax += Math::Pow((T1[i] - TT[i]), 2);
                }
                for (int i = 0; i <= NodesCount + 1; i++)
                {
                    TT[i] = T1[i];
                }
                k++;
            }
            for (int i = 0; i <= NodesCount + 1; i++)
            {
                T[i] = TT[i];
                nodes[i]->SetTemperature(T[i]);
            }
            for (int i = 1; i <= NodesCount; i++)
            {
                b[i] = T[i];
            }
        }
    }
    void SaveToCSV(String^ filename)
    {
        try
        {
            StreamWriter^ sw = gcnew StreamWriter(filename, false, System::Text::Encoding::UTF8);
            sw->WriteLine("X;Temperature_Explicit;Temperature_Implicit");
            array<Node^>^ currentNodes = GetAllNodes();
            CalculateExplicitScheme();
            array<Node^>^ nodes_explicit = GetAllNodes();
            for (int i = 0; i < nodes->Length; i++)
            {
                nodes[i]->SetTemperature(currentNodes[i]->T);
            }
            CalculateImplicitScheme();
            array<Node^>^ nodes_implicit = GetAllNodes();
            for (int i = 0; i < nodes->Length; i++)
            {
                nodes[i]->SetTemperature(currentNodes[i]->T);
            }
            for (int i = 0; i < nodes_explicit->Length; i++)
            {
                double temp_explicit = nodes_explicit[i]->T;
                double temp_implicit = (i < nodes_implicit->Length) ? nodes_implicit[i]->T : 0;

                sw->WriteLine(String::Format("{0:F6};{1:F6};{2:F6}",
                    nodes_explicit[i]->X, temp_explicit, temp_implicit));
            }

            sw->Close();
        }
        catch (Exception^ ex)
        {
            throw gcnew Exception("Ошибка сохранения CSV: " + ex->Message);
        }
    }

    void CalculateCompositeRod()
    {
        if (compositeRod == nullptr)
        {
            CalculateExplicitScheme();
            return;
        }

        int totalNodes = NodesCount + 2;
        nodes = gcnew array<Node^>(totalNodes);

        double h = L / (NodesCount + 1);
        double contactNodes = (int)(compositeRod->ContactLength / h);

        for (int i = 0; i < totalNodes; i++)
        {
            double x = i * h;
            Material^ currentMaterial = compositeRod->MainMaterial;

            if (i < contactNodes && compositeRod->LeftContactMaterial != nullptr)
                currentMaterial = compositeRod->LeftContactMaterial;
            else if (i > totalNodes - contactNodes - 1 && compositeRod->RightContactMaterial != nullptr)
                currentMaterial = compositeRod->RightContactMaterial;

            nodes[i] = gcnew Node(i, x, T0, currentMaterial);
        }

        double tau = CalculateTimeStep();
        double time = 0;

        array<double>^ TT = gcnew array<double>(totalNodes);
        for (int i = 0; i < totalNodes; i++)
            TT[i] = nodes[i]->T;

        while (time < EndTime)
        {
            time += tau;

            ApplyCompositeBoundaryConditions(TT, h, tau);

            for (int i = 1; i <= NodesCount; i++)
            {
                Material^ leftMat = nodes[i - 1]->CurrentMaterial;
                Material^ centerMat = nodes[i]->CurrentMaterial;
                Material^ rightMat = nodes[i + 1]->CurrentMaterial;

                double lambda_left = 2.0 * leftMat->Lambda * centerMat->Lambda /
                    (leftMat->Lambda + centerMat->Lambda);
                double lambda_right = 2.0 * centerMat->Lambda * rightMat->Lambda /
                    (centerMat->Lambda + rightMat->Lambda);

                double a_left = lambda_left / (centerMat->ro * centerMat->C);
                double a_right = lambda_right / (centerMat->ro * centerMat->C);

                TT[i] = nodes[i]->T + tau / (h * h) * (
                    a_right * (nodes[i + 1]->T - nodes[i]->T) -
                    a_left * (nodes[i]->T - nodes[i - 1]->T)
                    );
            }

            for (int i = 0; i < totalNodes; i++)
                nodes[i]->SetTemperature(TT[i]);
        }
    }

    array<Node^>^ GetAllNodes()
    {
        return nodes;
    }

    String^ GetSolutionInfo()
    {
        return String::Format(
            "Материал: {0}\nДлина: {1:F3} м\nНачальная температура: {2:F1}\n"
            "Количество узлов: {3}\nВремя расчета: {4:F1} с\n"
            "Левое ГУ: {5}\nПравое ГУ: {6}",
            material->Name, L, T0, NodesCount, EndTime,
            leftBoundary->ToString(), rightBoundary->ToString());
    }
};