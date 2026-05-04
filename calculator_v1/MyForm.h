#pragma once
#include "CalculatorEngine.h"

using namespace System::Diagnostics;
namespace calculatorv1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Windows::Forms::DataVisualization::Charting;
    using namespace System::IO;

      ref class MyForm : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::GroupBox^ groupLeftgu;
        System::Windows::Forms::ComboBox^ comboLeftTypegu;
        System::Windows::Forms::TextBox^ textboxleft1;
        System::Windows::Forms::TextBox^ textboxleft2;
        System::Windows::Forms::Label^ labelLeft_koeff;
        System::Windows::Forms::Label^ labelLeft_tcp;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::GroupBox^ groupBox1;
        List<GroupBox^>^ materialBoxes;
        Panel^ materialButtonsPanel;
        Button^ btnAddMaterialDynamic;
        Button^ btnDeleteMaterialDynamic;





        System::Windows::Forms::Label^ label_t_nach;

        System::Windows::Forms::Label^ label_t_vr;





        System::Windows::Forms::TextBox^ textBox6;

        System::Windows::Forms::TextBox^ textBox8;
        System::Windows::Forms::Button^ button_raschet;
        System::Windows::Forms::Label^ label_result;
        System::Windows::Forms::GroupBox^ groupBox2;
        System::Windows::Forms::Label^ labelRight_tcp;
        System::Windows::Forms::Label^ labelRight_koeff;
        System::Windows::Forms::TextBox^ textboxright2;
        System::Windows::Forms::TextBox^ textboxright1;
        System::Windows::Forms::ComboBox^ comboRightTypegu;
        System::Windows::Forms::DataVisualization::Charting::Chart^ chart;

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label3;

    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::GroupBox^ shema_grb;

    private: System::Windows::Forms::CheckBox^ yavn_chb;
    private: System::Windows::Forms::CheckBox^ neyavn_chb;











    private: System::Windows::Forms::GroupBox^ groupBox3;









    private: System::Windows::Forms::Label^ label7;



    private: System::Windows::Forms::Label^ label9;






           Solution^ solution;
           Solution^ explicitSolution;
           Solution^ implicitSolution;
           Solution^ cnSolution;
    private: System::Windows::Forms::GroupBox^ groupBox5;
    private: System::Windows::Forms::TextBox^ Tmax;
    private: System::Windows::Forms::TextBox^ Xmax;
    private: System::Windows::Forms::TextBox^ Xmin;
    private: System::Windows::Forms::TextBox^ Tmin;
    private: System::Windows::Forms::CheckBox^ kn_chb;



    private: System::Windows::Forms::TextBox^ textBox_debug;
    private: System::Windows::Forms::Button^ button_ochistka;

    private: System::Windows::Forms::TextBox^ textBoxtau;

    private: System::Windows::Forms::Label^ labeltau;
    private: System::Windows::Forms::FlowLayoutPanel^ flowMaterials;
    public:
        MyForm(void)
        {
            InitializeComponent();
            InitializeData();
        }

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
            System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->groupLeftgu = (gcnew System::Windows::Forms::GroupBox());
            this->labelLeft_tcp = (gcnew System::Windows::Forms::Label());
            this->labelLeft_koeff = (gcnew System::Windows::Forms::Label());
            this->textboxleft2 = (gcnew System::Windows::Forms::TextBox());
            this->textboxleft1 = (gcnew System::Windows::Forms::TextBox());
            this->comboLeftTypegu = (gcnew System::Windows::Forms::ComboBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->textBoxtau = (gcnew System::Windows::Forms::TextBox());
            this->labeltau = (gcnew System::Windows::Forms::Label());
            this->textBox8 = (gcnew System::Windows::Forms::TextBox());
            this->textBox6 = (gcnew System::Windows::Forms::TextBox());
            this->label_t_vr = (gcnew System::Windows::Forms::Label());
            this->label_t_nach = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->button_raschet = (gcnew System::Windows::Forms::Button());
            this->label_result = (gcnew System::Windows::Forms::Label());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->labelRight_tcp = (gcnew System::Windows::Forms::Label());
            this->labelRight_koeff = (gcnew System::Windows::Forms::Label());
            this->textboxright2 = (gcnew System::Windows::Forms::TextBox());
            this->textboxright1 = (gcnew System::Windows::Forms::TextBox());
            this->comboRightTypegu = (gcnew System::Windows::Forms::ComboBox());
            this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->shema_grb = (gcnew System::Windows::Forms::GroupBox());
            this->kn_chb = (gcnew System::Windows::Forms::CheckBox());
            this->neyavn_chb = (gcnew System::Windows::Forms::CheckBox());
            this->yavn_chb = (gcnew System::Windows::Forms::CheckBox());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->flowMaterials = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
            this->button_ochistka = (gcnew System::Windows::Forms::Button());
            this->Xmax = (gcnew System::Windows::Forms::TextBox());
            this->Xmin = (gcnew System::Windows::Forms::TextBox());
            this->Tmin = (gcnew System::Windows::Forms::TextBox());
            this->Tmax = (gcnew System::Windows::Forms::TextBox());
            this->textBox_debug = (gcnew System::Windows::Forms::TextBox());
            this->groupLeftgu->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
            this->shema_grb->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->groupBox5->SuspendLayout();
            this->SuspendLayout();
            // 
            // groupLeftgu
            // 
            this->groupLeftgu->BackColor = System::Drawing::SystemColors::Window;
            this->groupLeftgu->Controls->Add(this->labelLeft_tcp);
            this->groupLeftgu->Controls->Add(this->labelLeft_koeff);
            this->groupLeftgu->Controls->Add(this->textboxleft2);
            this->groupLeftgu->Controls->Add(this->textboxleft1);
            this->groupLeftgu->Controls->Add(this->comboLeftTypegu);
            this->groupLeftgu->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupLeftgu->Location = System::Drawing::Point(12, 23);
            this->groupLeftgu->Name = L"groupLeftgu";
            this->groupLeftgu->Size = System::Drawing::Size(312, 175);
            this->groupLeftgu->TabIndex = 0;
            this->groupLeftgu->TabStop = false;
            this->groupLeftgu->Text = L"Левое граничное условие";
            // 
            // labelLeft_tcp
            // 
            this->labelLeft_tcp->AutoSize = true;
            this->labelLeft_tcp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->labelLeft_tcp->Location = System::Drawing::Point(6, 113);
            this->labelLeft_tcp->Name = L"labelLeft_tcp";
            this->labelLeft_tcp->Size = System::Drawing::Size(139, 16);
            this->labelLeft_tcp->TabIndex = 5;
            this->labelLeft_tcp->Text = L"Температура среды";
            // 
            // labelLeft_koeff
            // 
            this->labelLeft_koeff->AutoSize = true;
            this->labelLeft_koeff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->labelLeft_koeff->Location = System::Drawing::Point(6, 85);
            this->labelLeft_koeff->Name = L"labelLeft_koeff";
            this->labelLeft_koeff->Size = System::Drawing::Size(136, 16);
            this->labelLeft_koeff->TabIndex = 4;
            this->labelLeft_koeff->Text = L"Коэф. теплообмена";
            // 
            // textboxleft2
            // 
            this->textboxleft2->BackColor = System::Drawing::SystemColors::Control;
            this->textboxleft2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textboxleft2->Location = System::Drawing::Point(185, 113);
            this->textboxleft2->Name = L"textboxleft2";
            this->textboxleft2->Size = System::Drawing::Size(101, 22);
            this->textboxleft2->TabIndex = 3;
            // 
            // textboxleft1
            // 
            this->textboxleft1->BackColor = System::Drawing::SystemColors::Control;
            this->textboxleft1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textboxleft1->Location = System::Drawing::Point(185, 85);
            this->textboxleft1->Name = L"textboxleft1";
            this->textboxleft1->Size = System::Drawing::Size(101, 22);
            this->textboxleft1->TabIndex = 2;
            // 
            // comboLeftTypegu
            // 
            this->comboLeftTypegu->BackColor = System::Drawing::SystemColors::Control;
            this->comboLeftTypegu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->comboLeftTypegu->ForeColor = System::Drawing::SystemColors::WindowText;
            this->comboLeftTypegu->FormattingEnabled = true;
            this->comboLeftTypegu->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
                L"I род (постоянная температура)", L"II род (тепловой поток)",
                    L"III род (конвекция)"
            });
            this->comboLeftTypegu->Location = System::Drawing::Point(6, 32);
            this->comboLeftTypegu->Name = L"comboLeftTypegu";
            this->comboLeftTypegu->Size = System::Drawing::Size(228, 24);
            this->comboLeftTypegu->TabIndex = 1;
            this->comboLeftTypegu->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboLeftTypegu_SelectedIndexChanged);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label2->Location = System::Drawing::Point(330, 23);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(258, 22);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Модель теплопроводности";
            // 
            // groupBox1
            // 
            this->groupBox1->BackColor = System::Drawing::SystemColors::Window;
            this->groupBox1->Controls->Add(this->textBoxtau);
            this->groupBox1->Controls->Add(this->labeltau);
            this->groupBox1->Controls->Add(this->textBox8);
            this->groupBox1->Controls->Add(this->textBox6);
            this->groupBox1->Controls->Add(this->label_t_vr);
            this->groupBox1->Controls->Add(this->label_t_nach);
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox1->Location = System::Drawing::Point(334, 594);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(282, 125);
            this->groupBox1->TabIndex = 2;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Общие параметры";
            // 
            // textBoxtau
            // 
            this->textBoxtau->BackColor = System::Drawing::SystemColors::Control;
            this->textBoxtau->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBoxtau->Location = System::Drawing::Point(166, 88);
            this->textBoxtau->Name = L"textBoxtau";
            this->textBoxtau->Size = System::Drawing::Size(93, 22);
            this->textBoxtau->TabIndex = 17;
            this->textBoxtau->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxtau_TextChanged);
            // 
            // labeltau
            // 
            this->labeltau->AutoSize = true;
            this->labeltau->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->labeltau->Location = System::Drawing::Point(16, 91);
            this->labeltau->Name = L"labeltau";
            this->labeltau->Size = System::Drawing::Size(139, 16);
            this->labeltau->TabIndex = 16;
            this->labeltau->Text = L"tau - Шаг по времени";
            this->labeltau->Click += gcnew System::EventHandler(this, &MyForm::labeltau_Click);
            // 
            // textBox8
            // 
            this->textBox8->BackColor = System::Drawing::SystemColors::Control;
            this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox8->Location = System::Drawing::Point(166, 60);
            this->textBox8->Name = L"textBox8";
            this->textBox8->Size = System::Drawing::Size(93, 22);
            this->textBox8->TabIndex = 15;
            // 
            // textBox6
            // 
            this->textBox6->BackColor = System::Drawing::SystemColors::Control;
            this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox6->Location = System::Drawing::Point(166, 32);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(93, 22);
            this->textBox6->TabIndex = 13;
            // 
            // label_t_vr
            // 
            this->label_t_vr->AutoSize = true;
            this->label_t_vr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label_t_vr->Location = System::Drawing::Point(16, 63);
            this->label_t_vr->Name = L"label_t_vr";
            this->label_t_vr->Size = System::Drawing::Size(118, 16);
            this->label_t_vr->TabIndex = 7;
            this->label_t_vr->Text = L"t - Время расчета";
            // 
            // label_t_nach
            // 
            this->label_t_nach->AutoSize = true;
            this->label_t_nach->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label_t_nach->Location = System::Drawing::Point(15, 35);
            this->label_t_nach->Name = L"label_t_nach";
            this->label_t_nach->Size = System::Drawing::Size(98, 16);
            this->label_t_nach->TabIndex = 5;
            this->label_t_nach->Text = L"T - Начальная";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label1->Location = System::Drawing::Point(6, 64);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(114, 16);
            this->label1->TabIndex = 7;
            this->label1->Text = L"Lamda тепл-ть -";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(120, 64);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(0, 16);
            this->label3->TabIndex = 8;
            // 
            // button_raschet
            // 
            this->button_raschet->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_raschet->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button_raschet->Location = System::Drawing::Point(334, 724);
            this->button_raschet->Name = L"button_raschet";
            this->button_raschet->Size = System::Drawing::Size(282, 67);
            this->button_raschet->TabIndex = 3;
            this->button_raschet->Text = L"Рассчитать теплопроводность";
            this->button_raschet->UseVisualStyleBackColor = true;
            this->button_raschet->Click += gcnew System::EventHandler(this, &MyForm::button_raschet_Click);
            // 
            // label_result
            // 
            this->label_result->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->label_result->Location = System::Drawing::Point(644, 614);
            this->label_result->Name = L"label_result";
            this->label_result->Size = System::Drawing::Size(506, 115);
            this->label_result->TabIndex = 4;
            this->label_result->Text = L"Результаты будут здесь...";
            // 
            // groupBox2
            // 
            this->groupBox2->BackColor = System::Drawing::SystemColors::Window;
            this->groupBox2->Controls->Add(this->labelRight_tcp);
            this->groupBox2->Controls->Add(this->labelRight_koeff);
            this->groupBox2->Controls->Add(this->textboxright2);
            this->groupBox2->Controls->Add(this->textboxright1);
            this->groupBox2->Controls->Add(this->comboRightTypegu);
            this->groupBox2->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox2->Location = System::Drawing::Point(12, 209);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(312, 175);
            this->groupBox2->TabIndex = 5;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Правое граничное условие";
            // 
            // labelRight_tcp
            // 
            this->labelRight_tcp->AutoSize = true;
            this->labelRight_tcp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->labelRight_tcp->Location = System::Drawing::Point(6, 113);
            this->labelRight_tcp->Name = L"labelRight_tcp";
            this->labelRight_tcp->Size = System::Drawing::Size(139, 16);
            this->labelRight_tcp->TabIndex = 5;
            this->labelRight_tcp->Text = L"Температура среды";
            // 
            // labelRight_koeff
            // 
            this->labelRight_koeff->AutoSize = true;
            this->labelRight_koeff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->labelRight_koeff->Location = System::Drawing::Point(6, 85);
            this->labelRight_koeff->Name = L"labelRight_koeff";
            this->labelRight_koeff->Size = System::Drawing::Size(136, 16);
            this->labelRight_koeff->TabIndex = 4;
            this->labelRight_koeff->Text = L"Коэф. теплообмена";
            // 
            // textboxright2
            // 
            this->textboxright2->BackColor = System::Drawing::SystemColors::Control;
            this->textboxright2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textboxright2->Location = System::Drawing::Point(185, 110);
            this->textboxright2->Name = L"textboxright2";
            this->textboxright2->Size = System::Drawing::Size(101, 22);
            this->textboxright2->TabIndex = 3;
            // 
            // textboxright1
            // 
            this->textboxright1->BackColor = System::Drawing::SystemColors::Control;
            this->textboxright1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textboxright1->Location = System::Drawing::Point(185, 82);
            this->textboxright1->Name = L"textboxright1";
            this->textboxright1->Size = System::Drawing::Size(101, 22);
            this->textboxright1->TabIndex = 2;
            // 
            // comboRightTypegu
            // 
            this->comboRightTypegu->BackColor = System::Drawing::SystemColors::Control;
            this->comboRightTypegu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->comboRightTypegu->FormattingEnabled = true;
            this->comboRightTypegu->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
                L"I род (постоянная температура)", L"II род (тепловой поток)",
                    L"III род (конвекция)"
            });
            this->comboRightTypegu->Location = System::Drawing::Point(6, 32);
            this->comboRightTypegu->Name = L"comboRightTypegu";
            this->comboRightTypegu->Size = System::Drawing::Size(228, 24);
            this->comboRightTypegu->TabIndex = 1;
            this->comboRightTypegu->Text = L"3 род (конвекция)";
            this->comboRightTypegu->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboRightTypegu_SelectedIndexChanged);
            // 
            // chart
            // 
            chartArea1->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
            chartArea1->AxisX2->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::False;
            chartArea1->AxisY2->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::False;
            chartArea1->Name = L"ChartArea1";
            this->chart->ChartAreas->Add(chartArea1);
            this->chart->Cursor = System::Windows::Forms::Cursors::Hand;
            legend1->AutoFitMinFontSize = 10;
            legend1->BorderColor = System::Drawing::Color::Black;
            legend1->DockedToChartArea = L"ChartArea1";
            legend1->Enabled = false;
            legend1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            legend1->IsTextAutoFit = false;
            legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
            legend1->Name = L"Legend1";
            this->chart->Legends->Add(legend1);
            this->chart->Location = System::Drawing::Point(91, 5);
            this->chart->Name = L"chart";
            this->chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
            series1->BorderWidth = 7;
            series1->ChartArea = L"ChartArea1";
            series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
            series1->Color = System::Drawing::Color::CornflowerBlue;
            series1->Legend = L"Legend1";
            series1->MarkerSize = 7;
            series1->Name = L"Явная схема";
            series2->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
            series2->BorderWidth = 3;
            series2->ChartArea = L"ChartArea1";
            series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
            series2->Color = System::Drawing::Color::GreenYellow;
            series2->Legend = L"Legend1";
            series2->MarkerStep = 5;
            series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
            series2->Name = L"Неявная схема";
            series3->BorderWidth = 3;
            series3->ChartArea = L"ChartArea1";
            series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
            series3->Color = System::Drawing::Color::Crimson;
            series3->Legend = L"Legend1";
            series3->MarkerBorderWidth = 5;
            series3->MarkerStep = 5;
            series3->Name = L"Схема Кранка-Николсон";
            series3->YValuesPerPoint = 6;
            this->chart->Series->Add(series1);
            this->chart->Series->Add(series2);
            this->chart->Series->Add(series3);
            this->chart->Size = System::Drawing::Size(641, 514);
            this->chart->TabIndex = 6;
            this->chart->Text = L"chart2";
            // 
            // button1
            // 
            this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
            this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button1->ForeColor = System::Drawing::SystemColors::Control;
            this->button1->Location = System::Drawing::Point(1228, 623);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(67, 67);
            this->button1->TabIndex = 7;
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::SystemColors::Control;
            this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
            this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button2->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
            this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button2->ForeColor = System::Drawing::SystemColors::Control;
            this->button2->Location = System::Drawing::Point(1313, 623);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(67, 67);
            this->button2->TabIndex = 8;
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // shema_grb
            // 
            this->shema_grb->BackColor = System::Drawing::SystemColors::Window;
            this->shema_grb->Controls->Add(this->kn_chb);
            this->shema_grb->Controls->Add(this->neyavn_chb);
            this->shema_grb->Controls->Add(this->yavn_chb);
            this->shema_grb->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->shema_grb->Location = System::Drawing::Point(334, 469);
            this->shema_grb->Name = L"shema_grb";
            this->shema_grb->Size = System::Drawing::Size(282, 123);
            this->shema_grb->TabIndex = 9;
            this->shema_grb->TabStop = false;
            this->shema_grb->Text = L"Тип разностной схемы:";
            // 
            // kn_chb
            // 
            this->kn_chb->AutoSize = true;
            this->kn_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->kn_chb->Location = System::Drawing::Point(18, 90);
            this->kn_chb->Name = L"kn_chb";
            this->kn_chb->Size = System::Drawing::Size(185, 20);
            this->kn_chb->TabIndex = 4;
            this->kn_chb->Text = L"схема Кранка-Николсон";
            this->kn_chb->UseVisualStyleBackColor = true;
            this->kn_chb->CheckedChanged += gcnew System::EventHandler(this, &MyForm::kn_chb_CheckedChanged);
            // 
            // neyavn_chb
            // 
            this->neyavn_chb->AutoSize = true;
            this->neyavn_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->neyavn_chb->Location = System::Drawing::Point(17, 60);
            this->neyavn_chb->Name = L"neyavn_chb";
            this->neyavn_chb->Size = System::Drawing::Size(124, 20);
            this->neyavn_chb->TabIndex = 3;
            this->neyavn_chb->Text = L"неявная схема";
            this->neyavn_chb->UseVisualStyleBackColor = true;
            // 
            // yavn_chb
            // 
            this->yavn_chb->AutoSize = true;
            this->yavn_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->yavn_chb->Location = System::Drawing::Point(17, 34);
            this->yavn_chb->Name = L"yavn_chb";
            this->yavn_chb->Size = System::Drawing::Size(108, 20);
            this->yavn_chb->TabIndex = 2;
            this->yavn_chb->Text = L"явная схема";
            this->yavn_chb->UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this->groupBox3->BackColor = System::Drawing::SystemColors::Window;
            this->groupBox3->Controls->Add(this->flowMaterials);
            this->groupBox3->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox3->Location = System::Drawing::Point(334, 55);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(304, 412);
            this->groupBox3->TabIndex = 11;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Дополнительный материал";
            // 
            // flowMaterials
            // 
            this->flowMaterials->AutoScroll = true;
            this->flowMaterials->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
            this->flowMaterials->Location = System::Drawing::Point(6, 25);
            this->flowMaterials->Name = L"flowMaterials";
            this->flowMaterials->Size = System::Drawing::Size(288, 380);
            this->flowMaterials->TabIndex = 33;
            this->flowMaterials->WrapContents = false;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(120, 64);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(0, 16);
            this->label7->TabIndex = 0;
            // 
            // label9
            // 
            this->label9->Location = System::Drawing::Point(0, 0);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(100, 23);
            this->label9->TabIndex = 0;
            // 
            // groupBox5
            // 
            this->groupBox5->BackColor = System::Drawing::Color::White;
            this->groupBox5->Controls->Add(this->button_ochistka);
            this->groupBox5->Controls->Add(this->Xmax);
            this->groupBox5->Controls->Add(this->Xmin);
            this->groupBox5->Controls->Add(this->Tmin);
            this->groupBox5->Controls->Add(this->Tmax);
            this->groupBox5->Controls->Add(this->chart);
            this->groupBox5->Location = System::Drawing::Point(644, 23);
            this->groupBox5->Name = L"groupBox5";
            this->groupBox5->Size = System::Drawing::Size(736, 582);
            this->groupBox5->TabIndex = 12;
            this->groupBox5->TabStop = false;
            this->groupBox5->Enter += gcnew System::EventHandler(this, &MyForm::groupBox5_Enter);
            // 
            // button_ochistka
            // 
            this->button_ochistka->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button_ochistka->Location = System::Drawing::Point(327, 525);
            this->button_ochistka->Name = L"button_ochistka";
            this->button_ochistka->Size = System::Drawing::Size(230, 28);
            this->button_ochistka->TabIndex = 11;
            this->button_ochistka->Text = L"Очистить значения";
            this->button_ochistka->UseVisualStyleBackColor = true;
            this->button_ochistka->Click += gcnew System::EventHandler(this, &MyForm::button_ochistka_Click);
            // 
            // Xmax
            // 
            this->Xmax->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Xmax->Location = System::Drawing::Point(640, 525);
            this->Xmax->Name = L"Xmax";
            this->Xmax->Size = System::Drawing::Size(50, 28);
            this->Xmax->TabIndex = 10;
            this->Xmax->TextChanged += gcnew System::EventHandler(this, &MyForm::Xmax_TextChanged);
            // 
            // Xmin
            // 
            this->Xmin->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Xmin->Location = System::Drawing::Point(181, 525);
            this->Xmin->Name = L"Xmin";
            this->Xmin->Size = System::Drawing::Size(50, 28);
            this->Xmin->TabIndex = 9;
            this->Xmin->TextChanged += gcnew System::EventHandler(this, &MyForm::Xmin_TextChanged);
            // 
            // Tmin
            // 
            this->Tmin->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Tmin->Location = System::Drawing::Point(37, 416);
            this->Tmin->Name = L"Tmin";
            this->Tmin->Size = System::Drawing::Size(50, 28);
            this->Tmin->TabIndex = 8;
            this->Tmin->TextChanged += gcnew System::EventHandler(this, &MyForm::Tmin_TextChanged);
            // 
            // Tmax
            // 
            this->Tmax->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Tmax->Location = System::Drawing::Point(37, 67);
            this->Tmax->Name = L"Tmax";
            this->Tmax->Size = System::Drawing::Size(50, 28);
            this->Tmax->TabIndex = 7;
            this->Tmax->TextChanged += gcnew System::EventHandler(this, &MyForm::Tmax_TextChanged);
            // 
            // textBox_debug
            // 
            this->textBox_debug->BackColor = System::Drawing::SystemColors::Window;
            this->textBox_debug->Location = System::Drawing::Point(12, 406);
            this->textBox_debug->Multiline = true;
            this->textBox_debug->Name = L"textBox_debug";
            this->textBox_debug->ReadOnly = true;
            this->textBox_debug->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->textBox_debug->Size = System::Drawing::Size(312, 323);
            this->textBox_debug->TabIndex = 13;
            this->textBox_debug->WordWrap = false;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1402, 805);
            this->Controls->Add(this->textBox_debug);
            this->Controls->Add(this->groupBox5);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->label_result);
            this->Controls->Add(this->button_raschet);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->groupLeftgu);
            this->Controls->Add(this->groupBox3);
            this->Controls->Add(this->shema_grb);
            this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Модель теплопроводности композитного стержня";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->groupLeftgu->ResumeLayout(false);
            this->groupLeftgu->PerformLayout();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
            this->shema_grb->ResumeLayout(false);
            this->shema_grb->PerformLayout();
            this->groupBox3->ResumeLayout(false);
            this->groupBox5->ResumeLayout(false);
            this->groupBox5->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        bool isCalculating = false;
        bool hasCalculationResult = false;
        void DebugLog(String^ text) {
            textBox_debug->AppendText(text + Environment::NewLine);
        }
        void ClearDebug() {
            textBox_debug->Clear();
        }
        void InitializeData()
        {
            materialBoxes = gcnew List<GroupBox^>();

            yavn_chb->Checked = true;
            neyavn_chb->Checked = false;
            kn_chb->Checked = false;

            comboLeftTypegu->SelectedIndex = 2;
            comboRightTypegu->SelectedIndex = 2;

            InitializeDynamicMaterialsUI();

            Xmin->KeyDown += gcnew KeyEventHandler(this, &MyForm::textBox_scale_KeyDown);
            Xmax->KeyDown += gcnew KeyEventHandler(this, &MyForm::textBox_scale_KeyDown);
            Tmin->KeyDown += gcnew KeyEventHandler(this, &MyForm::textBox_scale_KeyDown);
            Tmax->KeyDown += gcnew KeyEventHandler(this, &MyForm::textBox_scale_KeyDown);

            solution = nullptr;
            explicitSolution = nullptr;
            implicitSolution = nullptr;
            cnSolution = nullptr;

            textBoxtau->Text = "0";
            textBox6->Text = "20";   
            textBox8->Text = "660";  
            textBoxtau->Text = "0";  
        }

        GroupBox^ CreateMaterialBox(int number)
        {
            GroupBox^ gb = gcnew GroupBox();
            gb->Text = "Материал " + number.ToString();
            gb->Width = 225;
            gb->Height = 225;
            gb->Margin = System::Windows::Forms::Padding(0, 0, 0, 6);
            gb->Font = gcnew System::Drawing::Font(
                L"Montserrat SemiBold",
                9,
                System::Drawing::FontStyle::Bold
            );

            ComboBox^ cb = gcnew ComboBox();
            cb->Name = "comboMaterial";
            cb->Location = Point(8, 25);
            cb->Size = Drawing::Size(195, 24);
            cb->DropDownStyle = ComboBoxStyle::DropDownList;
            cb->Items->Add(L"Сталь");
            cb->Items->Add(L"Кирпич");
            cb->SelectedIndex = (number == 1 ? 0 : 1);

            gb->Controls->Add(cb);

            array<String^>^ labels = gcnew array<String^>
            {
                L"Lambda тепл-ть",
                    L"ro - Плотность",
                    L"C - Теплоемкость",
                    L"L - длина стержня",
                    L"N - узлы"
            };

            array<String^>^ names = gcnew array<String^>
            {
                L"txtLambda",
                    L"txtRo",
                    L"txtC",
                    L"txtL",
                    L"txtN"
            };

            for (int i = 0; i < labels->Length; i++)
            {
                Label^ lbl = gcnew Label();
                lbl->Text = labels[i];
                lbl->Location = Point(8, 63 + i * 28);
                lbl->Size = Drawing::Size(115, 22);

                TextBox^ tb = gcnew TextBox();
                tb->Name = names[i];
                tb->Location = Point(125, 60 + i * 28);
                tb->Size = Drawing::Size(75, 22);
                tb->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F);

                gb->Controls->Add(lbl);
                gb->Controls->Add(tb);
            }

            cb->SelectedIndexChanged += gcnew EventHandler(this, &MyForm::DynamicMaterialChanged);

            FillMaterialBox(gb);

            return gb;
        }

        void FillMaterialBox(GroupBox^ gb)
        {
            ComboBox^ cb = safe_cast<ComboBox^>(gb->Controls["comboMaterial"]);

            TextBox^ txtLambda = safe_cast<TextBox^>(gb->Controls["txtLambda"]);
            TextBox^ txtRo = safe_cast<TextBox^>(gb->Controls["txtRo"]);
            TextBox^ txtC = safe_cast<TextBox^>(gb->Controls["txtC"]);
            TextBox^ txtL = safe_cast<TextBox^>(gb->Controls["txtL"]);
            TextBox^ txtN = safe_cast<TextBox^>(gb->Controls["txtN"]);

            if (cb->Text == L"Сталь")
            {
                txtLambda->Text = "33";
                txtRo->Text = "7710";
                txtC->Text = "496";
                txtL->Text = "1";
                txtN->Text = "512";
            }
            else if (cb->Text == L"Кирпич")
            {
                txtLambda->Text = "0,5";
                txtRo->Text = "2000";
                txtC->Text = "850";
                txtL->Text = "0,24";
                txtN->Text = "511";
            }
        }

        void DynamicMaterialChanged(Object^ sender, EventArgs^ e)
        {
            ComboBox^ cb = safe_cast<ComboBox^>(sender);
            GroupBox^ gb = safe_cast<GroupBox^>(cb->Parent);

            FillMaterialBox(gb);
        }

        void InitializeDynamicMaterialsUI()
        {
            flowMaterials->Controls->Clear();
            materialBoxes->Clear();

            materialButtonsPanel = gcnew Panel();
            materialButtonsPanel->Width = 225;
            materialButtonsPanel->Height = 42;
            materialButtonsPanel->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);

            btnAddMaterialDynamic = gcnew Button();
            btnAddMaterialDynamic->Text = L"Добавить";
            btnAddMaterialDynamic->Location = Point(8, 6);
            btnAddMaterialDynamic->Size = Drawing::Size(95, 28);
            btnAddMaterialDynamic->Click += gcnew EventHandler(this, &MyForm::AddMaterialDynamic_Click);

            btnDeleteMaterialDynamic = gcnew Button();
            btnDeleteMaterialDynamic->Text = L"Удалить";
            btnDeleteMaterialDynamic->Location = Point(128, 6);
            btnDeleteMaterialDynamic->Size = Drawing::Size(95, 28);
            btnDeleteMaterialDynamic->Click += gcnew EventHandler(this, &MyForm::DeleteMaterialDynamic_Click);

            materialButtonsPanel->Controls->Add(btnAddMaterialDynamic);
            materialButtonsPanel->Controls->Add(btnDeleteMaterialDynamic);

            GroupBox^ firstMaterial = CreateMaterialBox(1);
            materialBoxes->Add(firstMaterial);

            flowMaterials->Controls->Add(firstMaterial);
            flowMaterials->Controls->Add(materialButtonsPanel);

            btnDeleteMaterialDynamic->Visible = false;
        }

        void AddMaterialDynamic_Click(Object^ sender, EventArgs^ e)
        {
            flowMaterials->Controls->Remove(materialButtonsPanel);

            GroupBox^ newMaterial = CreateMaterialBox(materialBoxes->Count + 1);
            materialBoxes->Add(newMaterial);

            flowMaterials->Controls->Add(newMaterial);
            flowMaterials->Controls->Add(materialButtonsPanel);

            btnDeleteMaterialDynamic->Visible = materialBoxes->Count > 1;
        }

        void DeleteMaterialDynamic_Click(Object^ sender, EventArgs^ e)
        {
            if (materialBoxes->Count <= 1)
                return;

            GroupBox^ lastMaterial = materialBoxes[materialBoxes->Count - 1];

            flowMaterials->Controls->Remove(lastMaterial);
            materialBoxes->RemoveAt(materialBoxes->Count - 1);

            btnDeleteMaterialDynamic->Visible = materialBoxes->Count > 1;
        }

        List<RodSegment^>^ buildsegments()
        {
            List<RodSegment^>^ segs = gcnew List<RodSegment^>();

            for each (GroupBox ^ gb in materialBoxes)
            {
                ComboBox^ cb = safe_cast<ComboBox^>(gb->Controls["comboMaterial"]);

                TextBox^ txtLambda = safe_cast<TextBox^>(gb->Controls["txtLambda"]);
                TextBox^ txtRo = safe_cast<TextBox^>(gb->Controls["txtRo"]);
                TextBox^ txtC = safe_cast<TextBox^>(gb->Controls["txtC"]);
                TextBox^ txtL = safe_cast<TextBox^>(gb->Controls["txtL"]);
                TextBox^ txtN = safe_cast<TextBox^>(gb->Controls["txtN"]);

                Material^ mat = gcnew Material();
                mat->Name = cb->Text;
                mat->Lambda = Convert::ToDouble(txtLambda->Text);
                mat->ro = Convert::ToDouble(txtRo->Text);
                mat->C = Convert::ToDouble(txtC->Text);
                mat->L = Convert::ToDouble(txtL->Text);
                mat->NodesCount = Convert::ToInt32(txtN->Text);

                segs->Add(gcnew RodSegment(mat, mat->L, mat->NodesCount));
            }

            return segs;
        }

        BoundaryCondition^ LBC() {
            switch (comboLeftTypegu->SelectedIndex)
            {
            case 0: //1 род
            {
                double value = Convert::ToDouble(textboxleft1->Text);
                return gcnew BoundaryCondition(BoundaryConditionType::FirstKind, value);
            }
            case 1: //2 род
            {
                double value = Convert::ToDouble(textboxleft1->Text);
                return gcnew BoundaryCondition(BoundaryConditionType::SecondKind, value, true);
            }
            case 2: //3 род
            {
                double alpha = Convert::ToDouble(textboxleft1->Text);
                double temp = Convert::ToDouble(textboxleft2->Text);
                return gcnew BoundaryCondition(BoundaryConditionType::ThirdKind, alpha, temp);
            }
            default:
                throw gcnew Exception("Не выбран тип левого граничного условия.");
            }
        }

        BoundaryCondition^ RBC() {
            switch (comboRightTypegu->SelectedIndex)
            {
            case 0: //1 род
            {
                double value = Convert::ToDouble(textboxright1->Text);
                return gcnew BoundaryCondition(BoundaryConditionType::FirstKind, value);
            }
            case 1: //2 род
            {
                double value = Convert::ToDouble(textboxright1->Text);
                return gcnew BoundaryCondition(BoundaryConditionType::SecondKind, value, false);
            }
            case 2: //3 род
            {
                double alpha = Convert::ToDouble(textboxright1->Text);
                double temp = Convert::ToDouble(textboxright2->Text);
                return gcnew BoundaryCondition(BoundaryConditionType::ThirdKind, alpha, temp);
            }
            default:
                throw gcnew Exception("Не выбран тип правого граничного условия.");
            }
        }

        void seriesvision()
        {
            for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series)
            {
                series->Enabled = false;
                series->LegendText = "";
            }

            if (hasCalculationResult)
            {
                if (yavn_chb->Checked && chart->Series[0]->Points->Count > 0)
                {
                    chart->Series[0]->Enabled = true;
                    chart->Series[0]->LegendText = "Явная схема";
                }
                if (neyavn_chb->Checked && chart->Series[1]->Points->Count > 0)
                {
                    chart->Series[1]->Enabled = true;
                    chart->Series[1]->LegendText = "Неявная схема";
                }
                if (kn_chb->Checked && chart->Series[2]->Points->Count > 0)
                {
                    chart->Series[2]->Enabled = true;
                    chart->Series[2]->LegendText = "Схема Кранка-Николсон";
                }
            }

            bool hasAnySeries = chart->Series[0]->Enabled || chart->Series[1]->Enabled || chart->Series[2]->Enabled;
            chart->Legends[0]->Enabled = hasAnySeries;
        }

        void AutoScaleChart()
        {
            bool hasPoints = false;

            for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series)
            {
                if (series->Points->Count > 0 && series->Enabled)
                {
                    hasPoints = true;
                    break;
                }
            }

            if (!hasPoints)
            {
                Tmin->Text = "";
                Tmax->Text = "";
                Xmin->Text = "";
                Xmax->Text = "";
                return;
            }

            double minY = Double::MaxValue;
            double maxY = Double::MinValue;
            double minX = Double::MaxValue;
            double maxX = Double::MinValue;

            for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series)
            {
                if (!series->Enabled || series->Points->Count == 0)
                    continue;

                for each (System::Windows::Forms::DataVisualization::Charting::DataPoint ^ point in series->Points)
                {
                    double x = point->XValue;
                    double y = point->YValues[0];

                    if (x < minX) minX = x;
                    if (x > maxX) maxX = x;
                    if (y < minY) minY = y;
                    if (y > maxY) maxY = y;
                }
            }

            double yMargin = (maxY - minY) * 0.1;
            double xMargin = (maxX - minX) * 0.1;

            if (Math::Abs(maxY - minY) < 0.001)
            {
                yMargin = Math::Abs(minY) * 0.1;
                if (yMargin < 1.0) yMargin = 1.0;
            }

            if (Math::Abs(maxX - minX) < 0.001)
            {
                xMargin = Math::Abs(minX) * 0.1;
                if (xMargin < 0.1) xMargin = 0.1;
            }

            double xMinVal = minX - xMargin;
            double xMaxVal = maxX + xMargin;
            double yMinVal = minY - yMargin;
            double yMaxVal = maxY + yMargin;

            chart->ChartAreas[0]->AxisX->Minimum = xMinVal;
            chart->ChartAreas[0]->AxisX->Maximum = xMaxVal;
            chart->ChartAreas[0]->AxisY->Minimum = yMinVal;
            chart->ChartAreas[0]->AxisY->Maximum = yMaxVal;
            chart->ChartAreas[0]->AxisX->Interval = Double::NaN;
            chart->ChartAreas[0]->AxisY->Interval = Double::NaN;
            chart->ChartAreas[0]->AxisX->LabelStyle->Format = "F2";
            chart->ChartAreas[0]->AxisY->LabelStyle->Format = "F1";

            Xmin->Text = xMinVal.ToString("F2");
            Xmax->Text = xMaxVal.ToString("F2");
            Tmin->Text = yMinVal.ToString("F1");
            Tmax->Text = yMaxVal.ToString("F1");
        }

        void ApplyScale()
        {
            try
            {
                double xMinVal = Convert::ToDouble(Xmin->Text);
                double xMaxVal = Convert::ToDouble(Xmax->Text);
                double yMinVal = Convert::ToDouble(Tmin->Text);
                double yMaxVal = Convert::ToDouble(Tmax->Text);

                if (xMinVal >= xMaxVal)
                    throw gcnew Exception("X мин должно быть меньше X макс");

                if (yMinVal >= yMaxVal)
                    throw gcnew Exception("Y мин должно быть меньше Y макс");

                chart->ChartAreas[0]->AxisX->Minimum = xMinVal;
                chart->ChartAreas[0]->AxisX->Maximum = xMaxVal;
                chart->ChartAreas[0]->AxisY->Minimum = yMinVal;
                chart->ChartAreas[0]->AxisY->Maximum = yMaxVal;
                chart->ChartAreas[0]->AxisX->Interval = (xMaxVal - xMinVal) / 5.0;
                chart->ChartAreas[0]->AxisY->Interval = (yMaxVal - yMinVal) / 5.0;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Ошибка при установке масштаба: " + ex->Message,
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void SaveSelectedSchemesToCSV(String^ filename)
        {
            try
            {
                bool saveExplicit = (yavn_chb->Checked && explicitSolution != nullptr && explicitSolution->GetAllNodes() != nullptr);
                bool saveImplicit = (neyavn_chb->Checked && implicitSolution != nullptr && implicitSolution->GetAllNodes() != nullptr);
                bool saveCN = (kn_chb->Checked && cnSolution != nullptr && cnSolution->GetAllNodes() != nullptr);
                if (!saveExplicit && !saveImplicit && !saveCN)
                {
                    MessageBox::Show("Ошибка. Выберите тип разностной схемы.",
                        "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    return;
                }

                array<Node^>^ explicitNodes = nullptr;
                array<Node^>^ implicitNodes = nullptr;
                array<Node^>^ cnNodes = nullptr;

                int nodeCount = 0;

                if (saveExplicit)
                {
                    explicitNodes = explicitSolution->GetAllNodes();
                    nodeCount = explicitNodes->Length;
                }

                if (saveImplicit)
                {
                    implicitNodes = implicitSolution->GetAllNodes();
                    if (nodeCount == 0)
                        nodeCount = implicitNodes->Length;
                }

                if (saveCN)
                {
                    cnNodes = cnSolution->GetAllNodes();
                    if (nodeCount == 0)
                        nodeCount = cnNodes->Length;
                }

                StreamWriter^ sw = gcnew StreamWriter(filename, false, System::Text::Encoding::UTF8);

                sw->Write("X");
                if (saveExplicit) sw->Write(";Explicit");
                if (saveImplicit) sw->Write(";Implicit");
                if (saveCN) sw->Write(";CrankNicolson");
                sw->WriteLine();

                for (int i = 0; i < nodeCount; i++)
                {
                    double x = 0.0;

                    if (saveExplicit && explicitNodes != nullptr && i < explicitNodes->Length)
                        x = explicitNodes[i]->X;
                    else if (saveImplicit && implicitNodes != nullptr && i < implicitNodes->Length)
                        x = implicitNodes[i]->X;
                    else if (saveCN && cnNodes != nullptr && i < cnNodes->Length)
                        x = cnNodes[i]->X;

                    sw->Write(x.ToString("F6"));

                    if (saveExplicit)
                    {
                        if (explicitNodes != nullptr && i < explicitNodes->Length)
                            sw->Write(";" + explicitNodes[i]->T.ToString("F6"));
                        else
                            sw->Write(";");
                    }

                    if (saveImplicit)
                    {
                        if (implicitNodes != nullptr && i < implicitNodes->Length)
                            sw->Write(";" + implicitNodes[i]->T.ToString("F6"));
                        else
                            sw->Write(";");
                    }

                    if (saveCN)
                    {
                        if (cnNodes != nullptr && i < cnNodes->Length)
                            sw->Write(";" + cnNodes[i]->T.ToString("F6"));
                        else
                            sw->Write(";");
                    }

                    sw->WriteLine();
                }

                sw->Close();

                MessageBox::Show("Данные успешно сохранены в файл:\n" + filename,
                    "Сохранение завершено",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information);
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Ошибка при сохранении CSV: " + ex->Message,
                    "Ошибка",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Error);
            }
        }

        double calculatetau(List<RodSegment^>^ segs)
        {
            double minTau = Double::MaxValue;

            for each(RodSegment ^ seg in segs)
            {
                double lambda = seg->Mat->Lambda;
                double ro = seg->Mat->ro;
                double c = seg->Mat->C;

                double a = lambda / (ro * c);
                double h = seg->Length / (seg->NodesCount + 1.0);
                double tau = (h * h) / (2.0 * a);

                if (tau < minTau)
                    minTau = tau;
            }

            return minTau;
        }

private: System::Void button_raschet_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (isCalculating)
    {
        MessageBox::Show("Расчет уже выполняется. Пожалуйста, подождите.",
            "Расчет выполняется",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        return;
    }

    isCalculating = true;

    try
    {
        this->Cursor = Cursors::WaitCursor;
        this->button_raschet->Enabled = false;
        this->button_raschet->Text = L"Выполняется расчет...";

        chart->Series[0]->Points->Clear();
        chart->Series[1]->Points->Clear();
        chart->Series[2]->Points->Clear();

        BoundaryCondition^ leftBC = LBC();
        BoundaryCondition^ rightBC = RBC();

        List<RodSegment^>^ segs = buildsegments();

        double stableTau = calculatetau(segs);
        double selectedTau = stableTau;

        if (!String::IsNullOrWhiteSpace(textBoxtau->Text) && textBoxtau->Text != "0")
        {
            selectedTau = Convert::ToDouble(textBoxtau->Text);
        }
        else
        {
            textBoxtau->Text = stableTau.ToString("E6");
        }

        if (yavn_chb->Checked && selectedTau > stableTau)
        {
            System::Windows::Forms::DialogResult result =
                MessageBox::Show(
                    "Условие устойчивости явной схемы не выполняется.\n\n" +
                    "Максимально допустимый tau = " + stableTau.ToString("E6") + "\n" +
                    "Введенный tau = " + selectedTau.ToString("E6") + "\n\n" +
                    "Продолжить расчет? График может быть некорректным.",
                    "Нарушено условие устойчивости",
                    MessageBoxButtons::YesNo,
                    MessageBoxIcon::Warning
                );

            if (result == System::Windows::Forms::DialogResult::No)
                return;
        }

        ClearDebug();

        DebugLog("отладка");
        DebugLog("Количество сегментов: " + segs->Count.ToString());

        for (int i = 0; i < segs->Count; i++)
        {
            DebugLog("");
            DebugLog("Сегмент " + (i + 1).ToString());
            DebugLog("  Материал: " + segs[i]->Mat->Name);
            DebugLog("  Длина: " + segs[i]->Length.ToString("F3"));
            DebugLog("  Узлов: " + segs[i]->NodesCount.ToString());
            double hSeg = segs[i]->Length / (segs[i]->NodesCount + 1.0);
            DebugLog("  h: " + hSeg.ToString("E6"));
        }

        double commonT0 = Convert::ToDouble(textBox6->Text);
        double commonEndTime = Convert::ToDouble(textBox8->Text);

        chart->ChartAreas[0]->AxisX->Title = "Длина стержня, м";
        chart->ChartAreas[0]->AxisY->Title = "Температура, °C";

        if (!yavn_chb->Checked && !neyavn_chb->Checked && !kn_chb->Checked)
        {
            yavn_chb->Checked = true;
        }

        if (yavn_chb->Checked)
        {
            explicitSolution = gcnew Solution(segs, leftBC, rightBC, commonT0, commonEndTime);
            explicitSolution->SetUserTau(selectedTau);
            explicitSolution->CalculateExplicitScheme();
            array<Node^>^ nodes = explicitSolution->GetAllNodes();

            chart->Series[0]->Points->Clear();
            for (int i = 0; i < nodes->Length; i++)
            {
                chart->Series[0]->Points->AddXY(nodes[i]->X, nodes[i]->T);
            }

            DebugLog("");
            DebugLog("Явная схема:");
            DebugLog("  h = " + explicitSolution->LastH.ToString("E6"));
            DebugLog("  tau = " + explicitSolution->LastTau.ToString("E6"));
            DebugLog("  Шагов по времени: " + explicitSolution->LastTimeSteps.ToString());
            DebugLog("  Всего узлов: " + explicitSolution->LastNodeCount.ToString());
            DebugLog("  Время расчета, мс: " + explicitSolution->LastElapsedMs.ToString("F2"));

            solution = explicitSolution;
        }
        else
        {
            explicitSolution = nullptr;
        }

        if (neyavn_chb->Checked)
        {
            implicitSolution = gcnew Solution(segs, leftBC, rightBC, commonT0, commonEndTime);
            implicitSolution->SetUserTau(selectedTau);
            implicitSolution->CalculateImplicitScheme();
            array<Node^>^ nodes = implicitSolution->GetAllNodes();

            chart->Series[1]->Points->Clear();
            for (int i = 0; i < nodes->Length; i++)
            {
                chart->Series[1]->Points->AddXY(nodes[i]->X, nodes[i]->T);
            }

            DebugLog("");
            DebugLog("Неявная схема:");
            DebugLog("  h = " + implicitSolution->LastH.ToString("E6"));
            DebugLog("  tau = " + implicitSolution->LastTau.ToString("E6"));
            DebugLog("  Шагов по времени: " + implicitSolution->LastTimeSteps.ToString());
            DebugLog("  Всего узлов: " + implicitSolution->LastNodeCount.ToString());
            DebugLog("  Итераций Якоби: " + implicitSolution->JacobiIter.ToString());
            DebugLog("  Время расчета, мс: " + implicitSolution->LastElapsedMs.ToString("F2"));

            solution = implicitSolution;
        }
        else
        {
            implicitSolution = nullptr;
        }

        if (kn_chb->Checked)
        {
            cnSolution = gcnew Solution(segs, leftBC, rightBC, commonT0, commonEndTime);
            cnSolution->SetUserTau(selectedTau);
            cnSolution->CalculateCNScheme();
            array<Node^>^ nodes = cnSolution->GetAllNodes();

            chart->Series[2]->Points->Clear();
            for (int i = 0; i < nodes->Length; i++)
            {
                chart->Series[2]->Points->AddXY(nodes[i]->X, nodes[i]->T);
            }

            DebugLog("");
            DebugLog("Схема Кранка-Николсон:");
            DebugLog("  h = " + cnSolution->LastH.ToString("E6"));
            DebugLog("  tau = " + cnSolution->LastTau.ToString("E6"));
            DebugLog("  Шагов по времени: " + cnSolution->LastTimeSteps.ToString());
            DebugLog("  Всего узлов: " + cnSolution->LastNodeCount.ToString());
            DebugLog("  Итераций: " + cnSolution->LastCNIterations.ToString());
            DebugLog("  Время расчета, мс: " + cnSolution->LastElapsedMs.ToString("F2"));

            solution = cnSolution;
        }
        else
        {
            cnSolution = nullptr;
        }

        hasCalculationResult = true;
        seriesvision();
        AutoScaleChart();

        array<Node^>^ finalNodes = solution->GetAllNodes();
        DebugLog("");
        DebugLog("Итоговая сетка:");
        DebugLog("  X первого узла: " + finalNodes[0]->X.ToString("F3"));
        DebugLog("  X последнего узла: " + finalNodes[finalNodes->Length - 1]->X.ToString("F3"));
        DebugLog("  Всего узлов в итоговом решении: " + finalNodes->Length.ToString());
        int mid = finalNodes->Length / 2;

        double totalLength = 0.0;
        for each (RodSegment ^ seg in segs)
            totalLength += seg->Length;

        String^ materialsInfo = "Материал 1: " + segs[0]->Mat->Name;
        if (segs->Count > 1)
            materialsInfo += "\nМатериал 2: " + segs[1]->Mat->Name;

        label_result->Text =
            "Расчет завершен!\n" +
            materialsInfo + "\n" +
            "Общая длина: " + totalLength.ToString("F3") + " м\n" +
            "Левое ГУ: " + leftBC->ToString() + "\n" +
            "Правое ГУ: " + rightBC->ToString() + "\n" +
            "Температура в начале: " + finalNodes[0]->T.ToString("F2") + "\n" +
            "Температура в середине: " + finalNodes[mid]->T.ToString("F2") + "\n" +
            "Температура в конце: " + finalNodes[finalNodes->Length - 1]->T.ToString("F2");
    }
    catch (Exception^ ex)
    {
        label_result->Text = "Ошибка расчета: " + ex->Message;
        MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally
    {
        this->Cursor = Cursors::Default;
        this->button_raschet->Enabled = true;
        this->button_raschet->Text = L"Рассчитать теплопроводность";
        isCalculating = false;
    }
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e){}

private: System::Void comboLeftTypegu_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    switch (comboLeftTypegu->SelectedIndex)
    {
    case 0: //1 род
        labelLeft_koeff->Text = "Температура, C";
        labelLeft_tcp->Visible = false;
        textboxleft2->Visible = false;
        textboxleft1->Visible = true;
        textboxleft1->Text = "200";
        break;

    case 1: //2 род
        labelLeft_koeff->Text = "Тепловой поток, Вт/м^2";
        labelLeft_tcp->Visible = false;
        textboxleft2->Visible = false;
        textboxleft1->Visible = true;
        textboxleft1->Text = "200";
        break;

    case 2: //3 род
        labelLeft_koeff->Text = "Коэф. теплообмена";
        labelLeft_tcp->Visible = true;
        labelLeft_tcp->Text = "Температура среды, C";
        textboxleft2->Visible = true;
        textboxleft1->Visible = true;
        textboxleft1->Text = "15,536";
        textboxleft2->Text = "200";
        break;
    }
}

private: System::Void comboRightTypegu_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    switch (comboRightTypegu->SelectedIndex)
    {
    case 0: //1 род
        labelRight_koeff->Text = "Температура, C";
        labelRight_tcp->Visible = false;
        textboxright2->Visible = false;
        textboxright1->Visible = true;
        textboxright1->Text = "200";
        break;

    case 1: //2 род
        labelRight_koeff->Text = "Тепловой поток, Вт/м^2";
        labelRight_tcp->Visible = false;
        textboxright2->Visible = false;
        textboxright1->Visible = true;
        textboxright1->Text = "200";
        break;

    case 2: //3 род
        labelRight_koeff->Text = "Коэф. теплообмена";
        labelRight_tcp->Visible = true;
        labelRight_tcp->Text = "Температура среды, C";
        textboxright2->Visible = true;
        textboxright1->Visible = true;
        textboxright1->Text = "15,536";
        textboxright2->Text = "200";
        break;
    }
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ timestamp = DateTime::Now.ToString("yyyyMMdd_HHmmss");
        String^ imageFilename = "temperature_chart_" + timestamp + ".png";

        Bitmap^ bmp = gcnew Bitmap(chart->Width, chart->Height);
        chart->DrawToBitmap(bmp, Rectangle(0, 0, bmp->Width, bmp->Height));
        bmp->Save(imageFilename, System::Drawing::Imaging::ImageFormat::Png);
        delete bmp;

        String^ csvFilename = "temperature_data_" + timestamp + ".csv";
        SaveSelectedSchemesToCSV(csvFilename);

        MessageBox::Show(
            "График сохранен как: " + imageFilename + "\n" +
            "Данные сохранены как: " + csvFilename,
            "Сохранение завершено!",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Ошибка при сохранении: " + ex->Message,
            "Ошибка!",
            MessageBoxButtons::OK,
            MessageBoxIcon::Error);
    }
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    chart->Series[0]->Points->Clear();
    chart->Series[1]->Points->Clear();
    chart->Series[2]->Points->Clear();

    hasCalculationResult = false;
    seriesvision();

    label_result->Text = "Результаты будут здесь...";
    Tmin->Text = "";
    Tmax->Text = "";
    Xmin->Text = "";
    Xmax->Text = "";

    chart->ChartAreas[0]->AxisX->Minimum = Double::NaN;
    chart->ChartAreas[0]->AxisX->Maximum = Double::NaN;
    chart->ChartAreas[0]->AxisY->Minimum = Double::NaN;
    chart->ChartAreas[0]->AxisY->Maximum = Double::NaN;
    chart->ChartAreas[0]->AxisX->Interval = Double::NaN;
    chart->ChartAreas[0]->AxisY->Interval = Double::NaN;

    chart->Refresh();
    this->Focus();
    solution = nullptr;
    explicitSolution = nullptr;
    implicitSolution = nullptr;
    cnSolution = nullptr;
}

private: System::Void yavn_chb_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
}

private: System::Void neyavn_chb_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
}

private: System::Void kn_chb_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
}

private: System::Void Tmax_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}

private: System::Void Tmin_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}

private: System::Void Xmin_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}

private: System::Void Xmax_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}

private: System::Void groupBox5_Enter(System::Object^ sender, System::EventArgs^ e)
{
}

private: System::Void textBox_scale_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter)
    {
        e->SuppressKeyPress = true;
        ApplyScale();
    }
}

private: System::Void textBox_scale_Leave(System::Object^ sender, System::EventArgs^ e)
{
    ApplyScale();
}

private: System::Void button_auto_scale_Click(System::Object^ sender, System::EventArgs^ e)
{
    AutoScaleChart();
}
       private: System::Void textBox_debug_TextChanged(System::Object^ sender, System::EventArgs^ e) {
       }
private: System::Void button_ochistka_Click(System::Object^ sender, System::EventArgs^ e) {
    Xmin->Text = "";
    Xmax->Text = "";
    Tmin->Text = "";
    Tmax->Text = "";

    chart->ChartAreas[0]->AxisX->Minimum = Double::NaN;
    chart->ChartAreas[0]->AxisX->Maximum = Double::NaN;
    chart->ChartAreas[0]->AxisY->Minimum = Double::NaN;
    chart->ChartAreas[0]->AxisY->Maximum = Double::NaN;

    chart->ChartAreas[0]->AxisX->Interval = Double::NaN;
    chart->ChartAreas[0]->AxisY->Interval = Double::NaN;

    AutoScaleChart();
    chart->Refresh();
}
private: System::Void labeltau_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxtau_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
       }