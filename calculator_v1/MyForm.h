#pragma once
#include "CalculatorEngine.h"

using namespace System::Diagnostics;
namespace calculatorv1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Windows::Forms::DataVisualization::Charting;
    using namespace System::IO;

    public ref class MyForm : public System::Windows::Forms::Form
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
        System::Windows::Forms::Label^ label_lambda;
        System::Windows::Forms::Label^ label_ro;
        System::Windows::Forms::Label^ label_c;
        System::Windows::Forms::Label^ label_alpha;

        System::Windows::Forms::Label^ label_t_nach;

        System::Windows::Forms::Label^ label_t_vr;
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::TextBox^ textBox2;
        System::Windows::Forms::TextBox^ textBox3;
        System::Windows::Forms::TextBox^ textBox4;

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

        Material^ steel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label3;

    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::GroupBox^ shema_grb;

    private: System::Windows::Forms::CheckBox^ yavn_chb;
    private: System::Windows::Forms::CheckBox^ neyavn_chb;
    private: System::Windows::Forms::ComboBox^ comboBox_material;
    private: System::Windows::Forms::GroupBox^ groupBox_material_1;
    private: System::Windows::Forms::TextBox^ textBox_materialL;

    private: System::Windows::Forms::Label^ label_material;
    private: System::Windows::Forms::TextBox^ textBox_materialN;

    private: System::Windows::Forms::Label^ label_material_N;

    private: System::Windows::Forms::RadioButton^ radioButton_add_material;
    private: System::Windows::Forms::VScrollBar^ vScrollBar1;
    private: System::Windows::Forms::GroupBox^ groupBox3;
    private: System::Windows::Forms::GroupBox^ groupBox4;
    private: System::Windows::Forms::RadioButton^ radioButton_add_material2;

    private: System::Windows::Forms::TextBox^ textBox9;
    private: System::Windows::Forms::TextBox^ textBox10;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::ComboBox^ comboBox_material2;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::RadioButton^ radioButton_delete_material2;
    private: System::Windows::Forms::TextBox^ textBox11;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::TextBox^ textBox12;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::TextBox^ textBox13;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::TextBox^ textBox14;

           Solution^ solution;
           bool material2Added = false;

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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->groupLeftgu = (gcnew System::Windows::Forms::GroupBox());
            this->labelLeft_tcp = (gcnew System::Windows::Forms::Label());
            this->labelLeft_koeff = (gcnew System::Windows::Forms::Label());
            this->textboxleft2 = (gcnew System::Windows::Forms::TextBox());
            this->textboxleft1 = (gcnew System::Windows::Forms::TextBox());
            this->comboLeftTypegu = (gcnew System::Windows::Forms::ComboBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->textBox8 = (gcnew System::Windows::Forms::TextBox());
            this->textBox6 = (gcnew System::Windows::Forms::TextBox());
            this->label_t_vr = (gcnew System::Windows::Forms::Label());
            this->label_t_nach = (gcnew System::Windows::Forms::Label());
            this->comboBox_material = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
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
            this->neyavn_chb = (gcnew System::Windows::Forms::CheckBox());
            this->yavn_chb = (gcnew System::Windows::Forms::CheckBox());
            this->groupBox_material_1 = (gcnew System::Windows::Forms::GroupBox());
            this->radioButton_add_material = (gcnew System::Windows::Forms::RadioButton());
            this->textBox_materialN = (gcnew System::Windows::Forms::TextBox());
            this->textBox_materialL = (gcnew System::Windows::Forms::TextBox());
            this->label_material_N = (gcnew System::Windows::Forms::Label());
            this->label_material = (gcnew System::Windows::Forms::Label());
            this->label_alpha = (gcnew System::Windows::Forms::Label());
            this->label_c = (gcnew System::Windows::Forms::Label());
            this->label_ro = (gcnew System::Windows::Forms::Label());
            this->label_lambda = (gcnew System::Windows::Forms::Label());
            this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->radioButton_delete_material2 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton_add_material2 = (gcnew System::Windows::Forms::RadioButton());
            this->comboBox_material2 = (gcnew System::Windows::Forms::ComboBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->textBox11 = (gcnew System::Windows::Forms::TextBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->textBox9 = (gcnew System::Windows::Forms::TextBox());
            this->textBox12 = (gcnew System::Windows::Forms::TextBox());
            this->textBox10 = (gcnew System::Windows::Forms::TextBox());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->textBox13 = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->textBox14 = (gcnew System::Windows::Forms::TextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->groupLeftgu->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
            this->shema_grb->SuspendLayout();
            this->groupBox_material_1->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->groupBox4->SuspendLayout();
            this->SuspendLayout();
            // 
            // groupLeftgu
            // 
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
            this->textboxleft2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textboxleft2->Location = System::Drawing::Point(185, 113);
            this->textboxleft2->Name = L"textboxleft2";
            this->textboxleft2->Size = System::Drawing::Size(101, 22);
            this->textboxleft2->TabIndex = 3;
            // 
            // textboxleft1
            // 
            this->textboxleft1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textboxleft1->Location = System::Drawing::Point(185, 85);
            this->textboxleft1->Name = L"textboxleft1";
            this->textboxleft1->Size = System::Drawing::Size(101, 22);
            this->textboxleft1->TabIndex = 2;
            // 
            // comboLeftTypegu
            // 
            this->comboLeftTypegu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->comboLeftTypegu->FormattingEnabled = true;
            this->comboLeftTypegu->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
                L"I род (постоянная температура)", L"II род (тепловой поток)",
                    L"III род (конвекция)"
            });
            this->comboLeftTypegu->Location = System::Drawing::Point(6, 32);
            this->comboLeftTypegu->Name = L"comboLeftTypegu";
            this->comboLeftTypegu->Size = System::Drawing::Size(228, 24);
            this->comboLeftTypegu->TabIndex = 1;
            this->comboLeftTypegu->Text = L"3 род (конвекция)";
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
            this->groupBox1->Controls->Add(this->textBox8);
            this->groupBox1->Controls->Add(this->textBox6);
            this->groupBox1->Controls->Add(this->label_t_vr);
            this->groupBox1->Controls->Add(this->label_t_nach);
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox1->Location = System::Drawing::Point(334, 473);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(282, 96);
            this->groupBox1->TabIndex = 2;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Общие параметры";
            // 
            // textBox8
            // 
            this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox8->Location = System::Drawing::Point(166, 60);
            this->textBox8->Name = L"textBox8";
            this->textBox8->Size = System::Drawing::Size(93, 22);
            this->textBox8->TabIndex = 15;
            // 
            // textBox6
            // 
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
            this->label_t_vr->Location = System::Drawing::Point(16, 60);
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
            // comboBox_material
            // 
            this->comboBox_material->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Сталь", L"Кирпич" });
            this->comboBox_material->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox_material->FormattingEnabled = true;
            this->comboBox_material->Location = System::Drawing::Point(6, 25);
            this->comboBox_material->Name = L"comboBox_material";
            this->comboBox_material->Size = System::Drawing::Size(240, 24);
            this->comboBox_material->TabIndex = 16;
            this->comboBox_material->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_material_SelectedIndexChanged);
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
            // textBox4
            // 
            this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox4->Location = System::Drawing::Point(153, 147);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(93, 22);
            this->textBox4->TabIndex = 11;
            // 
            // textBox3
            // 
            this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox3->Location = System::Drawing::Point(153, 119);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(93, 22);
            this->textBox3->TabIndex = 10;
            // 
            // textBox2
            // 
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox2->Location = System::Drawing::Point(153, 91);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(93, 22);
            this->textBox2->TabIndex = 9;
            // 
            // textBox1
            // 
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox1->Location = System::Drawing::Point(153, 58);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(93, 22);
            this->textBox1->TabIndex = 8;
            // 
            // button_raschet
            // 
            this->button_raschet->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_raschet->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button_raschet->Location = System::Drawing::Point(334, 575);
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
            this->label_result->Location = System::Drawing::Point(631, 591);
            this->label_result->Name = L"label_result";
            this->label_result->Size = System::Drawing::Size(506, 115);
            this->label_result->TabIndex = 4;
            this->label_result->Text = L"Результаты будут здесь...";
            // 
            // groupBox2
            // 
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
            this->textboxright2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textboxright2->Location = System::Drawing::Point(185, 110);
            this->textboxright2->Name = L"textboxright2";
            this->textboxright2->Size = System::Drawing::Size(101, 22);
            this->textboxright2->TabIndex = 3;
            // 
            // textboxright1
            // 
            this->textboxright1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textboxright1->Location = System::Drawing::Point(185, 82);
            this->textboxright1->Name = L"textboxright1";
            this->textboxright1->Size = System::Drawing::Size(101, 22);
            this->textboxright1->TabIndex = 2;
            // 
            // comboRightTypegu
            // 
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
            legend1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            legend1->IsTextAutoFit = false;
            legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
            legend1->Name = L"Legend1";
            this->chart->Legends->Add(legend1);
            this->chart->Location = System::Drawing::Point(626, 55);
            this->chart->Name = L"chart";
            this->chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
            series1->BorderWidth = 3;
            series1->ChartArea = L"ChartArea1";
            series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
            series1->Color = System::Drawing::Color::CornflowerBlue;
            series1->Legend = L"Legend1";
            series1->Name = L"Явная схема";
            series2->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
            series2->BorderWidth = 3;
            series2->ChartArea = L"ChartArea1";
            series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
            series2->Color = System::Drawing::Color::GreenYellow;
            series2->Legend = L"Legend1";
            series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
            series2->Name = L"Неявная схема";
            this->chart->Series->Add(series1);
            this->chart->Series->Add(series2);
            this->chart->Size = System::Drawing::Size(641, 514);
            this->chart->TabIndex = 6;
            this->chart->Text = L"chart2";
            // 
            // button1
            // 
            this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
            this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button1->ForeColor = System::Drawing::SystemColors::Control;
            this->button1->Location = System::Drawing::Point(1153, 592);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(55, 55);
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
            this->button2->ForeColor = System::Drawing::SystemColors::Control;
            this->button2->Location = System::Drawing::Point(1217, 592);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(55, 55);
            this->button2->TabIndex = 8;
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // shema_grb
            // 
            this->shema_grb->Controls->Add(this->neyavn_chb);
            this->shema_grb->Controls->Add(this->yavn_chb);
            this->shema_grb->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->shema_grb->Location = System::Drawing::Point(334, 360);
            this->shema_grb->Name = L"shema_grb";
            this->shema_grb->Size = System::Drawing::Size(282, 102);
            this->shema_grb->TabIndex = 9;
            this->shema_grb->TabStop = false;
            this->shema_grb->Text = L"Тип разностной схемы:";
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
            // groupBox_material_1
            // 
            this->groupBox_material_1->Controls->Add(this->comboBox_material);
            this->groupBox_material_1->Controls->Add(this->radioButton_add_material);
            this->groupBox_material_1->Controls->Add(this->textBox_materialN);
            this->groupBox_material_1->Controls->Add(this->textBox_materialL);
            this->groupBox_material_1->Controls->Add(this->label_material_N);
            this->groupBox_material_1->Controls->Add(this->label_material);
            this->groupBox_material_1->Controls->Add(this->textBox4);
            this->groupBox_material_1->Controls->Add(this->textBox3);
            this->groupBox_material_1->Controls->Add(this->textBox2);
            this->groupBox_material_1->Controls->Add(this->textBox1);
            this->groupBox_material_1->Controls->Add(this->label_alpha);
            this->groupBox_material_1->Controls->Add(this->label_c);
            this->groupBox_material_1->Controls->Add(this->label_ro);
            this->groupBox_material_1->Controls->Add(this->label_lambda);
            this->groupBox_material_1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox_material_1->Location = System::Drawing::Point(6, 30);
            this->groupBox_material_1->Name = L"groupBox_material_1";
            this->groupBox_material_1->Size = System::Drawing::Size(264, 269);
            this->groupBox_material_1->TabIndex = 10;
            this->groupBox_material_1->TabStop = false;
            this->groupBox_material_1->Text = L"Материал 1";
            // 
            // radioButton_add_material
            // 
            this->radioButton_add_material->AutoSize = true;
            this->radioButton_add_material->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->radioButton_add_material->Location = System::Drawing::Point(6, 232);
            this->radioButton_add_material->Name = L"radioButton_add_material";
            this->radioButton_add_material->Size = System::Drawing::Size(158, 20);
            this->radioButton_add_material->TabIndex = 20;
            this->radioButton_add_material->Text = L"Добавить материал";
            this->radioButton_add_material->UseVisualStyleBackColor = true;
            this->radioButton_add_material->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_add_material_CheckedChanged);
            // 
            // textBox_materialN
            // 
            this->textBox_materialN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox_materialN->Location = System::Drawing::Point(153, 204);
            this->textBox_materialN->Name = L"textBox_materialN";
            this->textBox_materialN->Size = System::Drawing::Size(93, 22);
            this->textBox_materialN->TabIndex = 18;
            // 
            // textBox_materialL
            // 
            this->textBox_materialL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox_materialL->Location = System::Drawing::Point(153, 176);
            this->textBox_materialL->Name = L"textBox_materialL";
            this->textBox_materialL->Size = System::Drawing::Size(93, 22);
            this->textBox_materialL->TabIndex = 18;
            // 
            // label_material_N
            // 
            this->label_material_N->AutoSize = true;
            this->label_material_N->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label_material_N->Location = System::Drawing::Point(6, 204);
            this->label_material_N->Name = L"label_material_N";
            this->label_material_N->Size = System::Drawing::Size(60, 16);
            this->label_material_N->TabIndex = 17;
            this->label_material_N->Text = L"N - узлы";
            // 
            // label_material
            // 
            this->label_material->AutoSize = true;
            this->label_material->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label_material->Location = System::Drawing::Point(6, 178);
            this->label_material->Name = L"label_material";
            this->label_material->Size = System::Drawing::Size(121, 16);
            this->label_material->TabIndex = 17;
            this->label_material->Text = L"L - длина стержня";
            // 
            // label_alpha
            // 
            this->label_alpha->AutoSize = true;
            this->label_alpha->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label_alpha->Location = System::Drawing::Point(6, 153);
            this->label_alpha->Name = L"label_alpha";
            this->label_alpha->Size = System::Drawing::Size(133, 16);
            this->label_alpha->TabIndex = 3;
            this->label_alpha->Text = L"alpha - Теплообмен";
            // 
            // label_c
            // 
            this->label_c->AutoSize = true;
            this->label_c->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label_c->Location = System::Drawing::Point(6, 122);
            this->label_c->Name = L"label_c";
            this->label_c->Size = System::Drawing::Size(120, 16);
            this->label_c->TabIndex = 2;
            this->label_c->Text = L"С - Теплоемкость";
            // 
            // label_ro
            // 
            this->label_ro->AutoSize = true;
            this->label_ro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label_ro->Location = System::Drawing::Point(6, 94);
            this->label_ro->Name = L"label_ro";
            this->label_ro->Size = System::Drawing::Size(99, 16);
            this->label_ro->TabIndex = 1;
            this->label_ro->Text = L"ro - Плотность";
            // 
            // label_lambda
            // 
            this->label_lambda->AutoSize = true;
            this->label_lambda->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label_lambda->Location = System::Drawing::Point(6, 64);
            this->label_lambda->Name = L"label_lambda";
            this->label_lambda->Size = System::Drawing::Size(108, 16);
            this->label_lambda->TabIndex = 0;
            this->label_lambda->Text = L"Lamda тепл-ть -";
            // 
            // vScrollBar1
            // 
            this->vScrollBar1->Location = System::Drawing::Point(263, -3);
            this->vScrollBar1->Name = L"vScrollBar1";
            this->vScrollBar1->Size = System::Drawing::Size(26, 303);
            this->vScrollBar1->TabIndex = 21;
            this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::vScrollBar1_Scroll);
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->groupBox4);
            this->groupBox3->Controls->Add(this->vScrollBar1);
            this->groupBox3->Controls->Add(this->groupBox_material_1);
            this->groupBox3->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox3->Location = System::Drawing::Point(334, 55);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(286, 300);
            this->groupBox3->TabIndex = 11;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Дополнительный материал";
            // 
            // groupBox4
            // 
            this->groupBox4->Controls->Add(this->radioButton_delete_material2);
            this->groupBox4->Controls->Add(this->radioButton_add_material2);
            this->groupBox4->Controls->Add(this->comboBox_material2);
            this->groupBox4->Controls->Add(this->label6);
            this->groupBox4->Controls->Add(this->textBox11);
            this->groupBox4->Controls->Add(this->label8);
            this->groupBox4->Controls->Add(this->textBox9);
            this->groupBox4->Controls->Add(this->textBox12);
            this->groupBox4->Controls->Add(this->textBox10);
            this->groupBox4->Controls->Add(this->label10);
            this->groupBox4->Controls->Add(this->label4);
            this->groupBox4->Controls->Add(this->textBox13);
            this->groupBox4->Controls->Add(this->label5);
            this->groupBox4->Controls->Add(this->label11);
            this->groupBox4->Controls->Add(this->textBox14);
            this->groupBox4->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox4->Location = System::Drawing::Point(6, 305);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(264, 261);
            this->groupBox4->TabIndex = 21;
            this->groupBox4->TabStop = false;
            this->groupBox4->Text = L"Материал 2";
            this->groupBox4->Visible = false;
            // 
            // radioButton_delete_material2
            // 
            this->radioButton_delete_material2->AutoSize = true;
            this->radioButton_delete_material2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->radioButton_delete_material2->Location = System::Drawing::Point(153, 232);
            this->radioButton_delete_material2->Name = L"radioButton_delete_material2";
            this->radioButton_delete_material2->Size = System::Drawing::Size(83, 20);
            this->radioButton_delete_material2->TabIndex = 21;
            this->radioButton_delete_material2->Text = L"Удалить";
            this->radioButton_delete_material2->UseVisualStyleBackColor = true;
            this->radioButton_delete_material2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_delete_material2_CheckedChanged);
            // 
            // radioButton_add_material2
            // 
            this->radioButton_add_material2->AutoSize = true;
            this->radioButton_add_material2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->radioButton_add_material2->Location = System::Drawing::Point(6, 232);
            this->radioButton_add_material2->Name = L"radioButton_add_material2";
            this->radioButton_add_material2->Size = System::Drawing::Size(91, 20);
            this->radioButton_add_material2->TabIndex = 20;
            this->radioButton_add_material2->Text = L"Добавить";
            this->radioButton_add_material2->UseVisualStyleBackColor = true;
            // 
            // comboBox_material2
            // 
            this->comboBox_material2->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Сталь", L"Кирпич" });
            this->comboBox_material2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox_material2->FormattingEnabled = true;
            this->comboBox_material2->Location = System::Drawing::Point(6, 25);
            this->comboBox_material2->Name = L"comboBox_material2";
            this->comboBox_material2->Size = System::Drawing::Size(240, 24);
            this->comboBox_material2->TabIndex = 29;
            this->comboBox_material2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_material2_SelectedIndexChanged);
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label6->Location = System::Drawing::Point(6, 64);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(108, 16);
            this->label6->TabIndex = 24;
            this->label6->Text = L"Lamda тепл-ть -";
            // 
            // textBox11
            // 
            this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox11->Location = System::Drawing::Point(153, 147);
            this->textBox11->Name = L"textBox11";
            this->textBox11->Size = System::Drawing::Size(93, 22);
            this->textBox11->TabIndex = 28;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label8->Location = System::Drawing::Point(6, 94);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(99, 16);
            this->label8->TabIndex = 21;
            this->label8->Text = L"ro - Плотность";
            // 
            // textBox9
            // 
            this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox9->Location = System::Drawing::Point(153, 204);
            this->textBox9->Name = L"textBox9";
            this->textBox9->Size = System::Drawing::Size(93, 22);
            this->textBox9->TabIndex = 18;
            // 
            // textBox12
            // 
            this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox12->Location = System::Drawing::Point(153, 119);
            this->textBox12->Name = L"textBox12";
            this->textBox12->Size = System::Drawing::Size(93, 22);
            this->textBox12->TabIndex = 27;
            // 
            // textBox10
            // 
            this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox10->Location = System::Drawing::Point(153, 175);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(93, 22);
            this->textBox10->TabIndex = 18;
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label10->Location = System::Drawing::Point(6, 122);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(120, 16);
            this->label10->TabIndex = 22;
            this->label10->Text = L"С - Теплоемкость";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label4->Location = System::Drawing::Point(6, 207);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(60, 16);
            this->label4->TabIndex = 17;
            this->label4->Text = L"N - узлы";
            // 
            // textBox13
            // 
            this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox13->Location = System::Drawing::Point(153, 91);
            this->textBox13->Name = L"textBox13";
            this->textBox13->Size = System::Drawing::Size(93, 22);
            this->textBox13->TabIndex = 26;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label5->Location = System::Drawing::Point(6, 181);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(121, 16);
            this->label5->TabIndex = 17;
            this->label5->Text = L"L - длина стержня";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->label11->Location = System::Drawing::Point(6, 153);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(133, 16);
            this->label11->TabIndex = 23;
            this->label11->Text = L"alpha - Теплообмен";
            // 
            // textBox14
            // 
            this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
            this->textBox14->Location = System::Drawing::Point(153, 58);
            this->textBox14->Name = L"textBox14";
            this->textBox14->Size = System::Drawing::Size(93, 22);
            this->textBox14->TabIndex = 25;
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
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1284, 740);
            this->Controls->Add(this->groupBox3);
            this->Controls->Add(this->shema_grb);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->chart);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->label_result);
            this->Controls->Add(this->button_raschet);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->groupLeftgu);
            this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"MyForm";
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
            this->groupBox_material_1->ResumeLayout(false);
            this->groupBox_material_1->PerformLayout();
            this->groupBox3->ResumeLayout(false);
            this->groupBox4->ResumeLayout(false);
            this->groupBox4->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        bool isCalculating = false;

        void InitializeData()
        {
            steel = gcnew Material("Сталь", 33, 7710, 496, 15.536);
            solution = gcnew Solution(steel, nullptr, nullptr);

            comboBox_material->Items->Clear();
            comboBox_material->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Сталь", L"Кирпич" });
            comboBox_material->SelectedIndex = 0;

            comboBox_material2->Items->Clear();
            comboBox_material2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Сталь", L"Кирпич" });
            comboBox_material2->SelectedIndex = 0;

            InitializeGUValues();
            SetDefaultValues();
        }

        void InitializeGUValues()
        {
            textboxleft1->Text = "15,536";
            textboxleft2->Text = "200";

            textboxright1->Text = "15,536";
            textboxright2->Text = "200";
        }

        void SetDefaultValues() {
            comboLeftTypegu->SelectedIndex = 2;
            comboRightTypegu->SelectedIndex = 2;
        }

        // Расчет теплопроводности
    private: System::Void button_raschet_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Добавляем флаг для отслеживания расчета
        static bool isCalculating = false;

        // Проверяем, не выполняется ли уже расчет
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

            String^ originalButtonText = this->button_raschet->Text;
            this->button_raschet->Text = L"Выполняется расчет...";

            chart->Series[0]->Points->Clear();
            chart->Series[1]->Points->Clear();

            UpdateMaterialFromInput();

            BoundaryCondition^ leftBC;
            String^ leftType = comboLeftTypegu->Text;
            double leftValue1 = Convert::ToDouble(textboxleft1->Text);

            // Настраиваем только заголовки осей
            chart->ChartAreas[0]->AxisX->Title = "Длина стержня, м";
            chart->ChartAreas[0]->AxisY->Title = "Температура, °C";

            if (leftType->Contains("I род") && leftType->Contains("постоянная температура"))
            {
                leftBC = gcnew BoundaryCondition(BoundaryConditionType::FirstKind, leftValue1);
            }
            else if (leftType->Contains("II род") && leftType->Contains("тепловой поток"))
            {
                leftBC = gcnew BoundaryCondition(BoundaryConditionType::SecondKind, leftValue1, true);
            }
            else if (leftType->Contains("III род") && leftType->Contains("конвекция"))
            {
                double leftValue2 = Convert::ToDouble(textboxleft2->Text);
                leftBC = gcnew BoundaryCondition(BoundaryConditionType::ThirdKind, leftValue1, leftValue2);
            }
            else
            {
                double leftValue2 = Convert::ToDouble(textboxleft2->Text);
                leftBC = gcnew BoundaryCondition(BoundaryConditionType::ThirdKind, leftValue1, leftValue2);
            }

            BoundaryCondition^ rightBC;
            String^ rightType = comboRightTypegu->Text;
            double rightValue1 = Convert::ToDouble(textboxright1->Text);

            if (rightType->Contains("I род") && rightType->Contains("постоянная температура"))
            {
                rightBC = gcnew BoundaryCondition(BoundaryConditionType::FirstKind, rightValue1);
            }
            else if (rightType->Contains("II род") && rightType->Contains("тепловой поток"))
            {
                rightBC = gcnew BoundaryCondition(BoundaryConditionType::SecondKind, rightValue1, true);
            }
            else if (rightType->Contains("III род") && rightType->Contains("конвекция"))
            {
                double rightValue2 = Convert::ToDouble(textboxright2->Text);
                rightBC = gcnew BoundaryCondition(BoundaryConditionType::ThirdKind, rightValue1, rightValue2);
            }
            else
            {
                double rightValue2 = Convert::ToDouble(textboxright2->Text);
                rightBC = gcnew BoundaryCondition(BoundaryConditionType::ThirdKind, rightValue1, rightValue2);
            }

            solution->LeftBoundary = leftBC;
            solution->RightBoundary = rightBC;
            solution->NodesCount = steel->NodesCount;
            solution->EndTime = steel->EndTime;


            if (yavn_chb->Checked)
            {
                solution->CalculateExplicitScheme();
                array<Node^>^ nodes = solution->GetAllNodes();
                for (int i = 0; i < nodes->Length; i++)
                {
                    chart->Series[0]->Points->AddXY(nodes[i]->X, nodes[i]->T);
                }
            }

            if (neyavn_chb->Checked)
            {
                solution->CalculateImplicitScheme();
                array<Node^>^ nodes = solution->GetAllNodes();
                int step = 150;
                if (nodes->Length > 500) step = 20;
                if (nodes->Length > 1000) step = 50;

                for (int i = 0; i < nodes->Length; i += step)
                {
                    chart->Series[1]->Points->AddXY(nodes[i]->X, nodes[i]->T);
                }
                if ((nodes->Length - 1) % step != 0)
                {
                    chart->Series[1]->Points->AddXY(nodes[nodes->Length - 1]->X, nodes[nodes->Length - 1]->T);
                }
            }
            if (!yavn_chb->Checked && !neyavn_chb->Checked)
            {
                solution->CalculateExplicitScheme();
                array<Node^>^ nodes = solution->GetAllNodes();
                for (int i = 0; i < nodes->Length; i++)
                {
                    chart->Series[0]->Points->AddXY(nodes[i]->X, nodes[i]->T);
                }
                yavn_chb->Checked = true;
            }

            //автоматическое масштабирование графика
            AutoScaleChart();

            array<Node^>^ finalNodes = solution->GetAllNodes();
            String^ result = String::Format(
                "Расчет завершен!\n" +
                "Левое ГУ: {0}\n" +
                "Правое ГУ: {1}\n" +
                "Температура в начале: {2:F2}\n" +
                "Температура в конце: {3:F2}\n" +
                "Температура в середине: {4:F2}",
                leftBC->ToString(),
                rightBC->ToString(),
                finalNodes[0]->T,
                finalNodes[finalNodes->Length - 1]->T,
                finalNodes[finalNodes->Length / 2]->T);
            label_result->Text = result;
        }
        catch (Exception^ ex)
        {
            label_result->Text = "Ошибка расчета: " + ex->Message;
        }
        finally
        {
            this->Cursor = Cursors::Default;

            // Разблокируем кнопку
            this->button_raschet->Enabled = true;

            // Восстанавливаем текст кнопки
            this->button_raschet->Text = L"Рассчитать теплопроводность";

            isCalculating = false;
        }
    }

           void UpdateMaterialFromInput()
           {
               try
               {
                   steel->Lambda = Convert::ToDouble(textBox1->Text);
                   steel->ro = Convert::ToDouble(textBox2->Text);
                   steel->C = Convert::ToDouble(textBox3->Text);
                   steel->Alpha = Convert::ToDouble(textBox4->Text);
                   steel->L = Convert::ToDouble(textBox_materialL->Text);
                   steel->T0 = Convert::ToDouble(textBox6->Text);
                   steel->NodesCount = Convert::ToInt32(textBox_materialN->Text);
                   steel->EndTime = Convert::ToDouble(textBox8->Text);
               }
               catch (Exception^ ex)
               {
                   label_result->Text = "Ошибка в параметрах материала: " + ex->Message;
                   throw;
               }
           }

    private:
        void AutoScaleChart()
        {
            if (chart->Series[0]->Points->Count == 0 && chart->Series[1]->Points->Count == 0)
                return;

            double minY = Double::MaxValue;
            double maxY = Double::MinValue;
            double minX = Double::MaxValue;
            double maxX = Double::MinValue;

            // Находим минимальные и максимальные значения по всем сериям
            for each(System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series)
            {
                if (series->Points->Count > 0)
                {
                    for each(System::Windows::Forms::DataVisualization::Charting::DataPoint ^ point in series->Points)
                    {
                        double x = point->XValue;
                        double y = point->YValues[0];

                        if (x < minX) minX = x;
                        if (x > maxX) maxX = x;
                        if (y < minY) minY = y;
                        if (y > maxY) maxY = y;
                    }
                }
            }

            // Добавляем отступы по осям (10% от диапазона)
            double yMargin = (maxY - minY) * 0.1;
            double xMargin = (maxX - minX) * 0.1;

            // Если все значения одинаковы (особый случай)
            if (Math::Abs(maxY - minY) < 0.001)
            {
                yMargin = Math::Abs(minY) * 0.1;
                if (yMargin < 1) yMargin = 1;
            }

            if (Math::Abs(maxX - minX) < 0.001)
            {
                xMargin = Math::Abs(minX) * 0.1;
                if (xMargin < 0.1) xMargin = 0.1;
            }

            // Устанавливаем границы осей с отступами
            chart->ChartAreas[0]->AxisY->Minimum = minY - yMargin;
            chart->ChartAreas[0]->AxisY->Maximum = maxY + yMargin;
            chart->ChartAreas[0]->AxisX->Minimum = minX - xMargin;
            chart->ChartAreas[0]->AxisX->Maximum = maxX + xMargin;

            // Автоматически подбираем интервалы
            chart->ChartAreas[0]->AxisY->Interval = Double::NaN;
            chart->ChartAreas[0]->AxisX->Interval = Double::NaN;

            // Форматирование подписей
            chart->ChartAreas[0]->AxisX->LabelStyle->Format = "F2";
            chart->ChartAreas[0]->AxisY->LabelStyle->Format = "F1";
        }

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        InitializeScrollBar();
    }

           void InitializeScrollBar() {
               for each(Control ^ control in groupBox3->Controls)
               {
                   if (control != vScrollBar1)
                   {
                       control->Tag = control->Top;
                   }
               }
               vScrollBar1->Maximum = 200;
               vScrollBar1->Minimum = 0;
               vScrollBar1->Value = 0;
               vScrollBar1->SmallChange = 10;
               vScrollBar1->LargeChange = 30;

               CalculateScrollRange();
           }

           void CalculateScrollRange() {
               int maxBottom = 0;
               for each(Control ^ control in groupBox3->Controls)
               {
                   if (control != vScrollBar1 && control->Visible)
                   {
                       int bottom = control->Top + control->Height;
                       if (bottom > maxBottom)
                           maxBottom = bottom;
                   }
               }

               int visibleHeight = groupBox3->ClientSize.Height - 10;
               if (maxBottom > visibleHeight)
               {
                   vScrollBar1->Maximum = maxBottom - visibleHeight + 20;
                   vScrollBar1->Enabled = true;
               }
               else
               {
                   vScrollBar1->Maximum = 0;
                   vScrollBar1->Enabled = false;
               }
           }

    private: System::Void vScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
        int scrollValue = vScrollBar1->Value;

        for each(Control ^ control in groupBox3->Controls)
        {
            if (control == vScrollBar1) continue;
            if (control->Tag != nullptr)
            {
                int originalTop = (int)control->Tag;
                control->Top = originalTop - scrollValue;
            }
        }
    }

    private: System::Void radioButton_add_material_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        if (radioButton_add_material->Checked)
        {
            groupBox4->Visible = true;
            material2Added = true;
            CalculateScrollRange();
        }
        else
        {
            groupBox4->Visible = false;
            material2Added = false;
            CalculateScrollRange();
        }
    }
           private:
               void UpdateControlsPositions()
               {
                   groupBox_material_1->Top = 30;
                   if (material2Added && groupBox4->Visible)
                   {
                       groupBox4->Top = groupBox_material_1->Top + groupBox_material_1->Height + 10;
                   }
                   for each(Control ^ control in groupBox3->Controls)
                   {
                       if (control != vScrollBar1)
                       {
                           control->Tag = control->Top;
                       }
                   }
               }

    private: System::Void radioButton_delete_material2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        if (radioButton_delete_material2->Checked)
        {
            groupBox4->Visible = false;
            material2Added = false;

            radioButton_add_material->Checked = false;

            // Сбрасываем значения второго материала
            textBox14->Text = "";
            textBox13->Text = "";
            textBox12->Text = "";
            textBox11->Text = "";
            textBox10->Text = "";
            textBox9->Text = "";
            comboBox_material2->SelectedIndex = 0;

            groupBox_material_1->Top = 30; // Возвращаем на исходную позицию

            UpdateControlsPositions();
            CalculateScrollRange();
            vScrollBar1->Value = 0;
            vScrollBar1_Scroll(nullptr, nullptr);
        }
    }

    private: System::Void comboLeftTypegu_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ selectedType = comboLeftTypegu->Text;

        if (selectedType->Contains("I род (постоянная температура)")) {
            labelLeft_koeff->Text = "Температура, C";
            labelLeft_tcp->Visible = false;
            textboxleft2->Visible = false;
            textboxleft1->Text = "200";
        }
        else if (selectedType->Contains("II род (тепловой поток)")) {
            labelLeft_koeff->Text = "Тепловой поток, Вт/м^2";
            labelLeft_tcp->Visible = false;
            textboxleft2->Visible = false;
            textboxleft1->Text = "200";
        }
        else if (selectedType->Contains("III род (конвекция)")) {
            labelLeft_koeff->Text = "Коэф. теплообмена";
            labelLeft_tcp->Visible = true;
            labelLeft_tcp->Text = "Температура среды, C";
            textboxleft2->Visible = true;
            textboxleft1->Text = "15,536";
            textboxleft2->Text = "200";
        }
    }

    private: System::Void comboRightTypegu_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ selectedType = comboRightTypegu->Text;

        if (selectedType->Contains("I род (постоянная температура)")) {
            labelRight_koeff->Text = "Температура, C";
            labelRight_tcp->Visible = false;
            textboxright2->Visible = false;
            textboxright1->Text = "200";
        }
        else if (selectedType->Contains("II род (тепловой поток)")) {
            labelRight_koeff->Text = "Тепловой поток, Вт/м^2";
            labelRight_tcp->Visible = false;
            textboxright2->Visible = false;
            textboxright1->Text = "200";
        }
        else if (selectedType->Contains("III род (конвекция)")) {
            labelRight_koeff->Text = "Коэф. теплообмена";
            labelRight_tcp->Visible = true;
            labelRight_tcp->Text = "Температура среды, C";
            textboxright2->Visible = true;
            textboxright1->Text = "15,536";
            textboxright2->Text = "200";
        }
    }

    private: System::Void comboBox_material_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ selectedMaterial = comboBox_material->Text;

        if (selectedMaterial == "Сталь")
        {
            textBox1->Text = "33";
            textBox2->Text = "7710";
            textBox3->Text = "496";
            textBox4->Text = "15,536";
            textBox_materialL->Text = "1";
            textBox6->Text = "20";
            textBox_materialN->Text = "512";
            textBox8->Text = "660";

            String^ leftType = comboLeftTypegu->Text;
            String^ rightType = comboRightTypegu->Text;

            if (leftType->Contains("III род (конвекция)")) {
                textboxleft1->Text = "15,536";
                textboxleft2->Text = "200";
            }
            else if (leftType->Contains("I род")) {
                textboxleft1->Text = "15,536";
            }
            else if (leftType->Contains("II род")) {
                textboxleft1->Text = "100";
            }

            if (rightType->Contains("III род (конвекция)")) {
                textboxright1->Text = "20";
                textboxright2->Text = "200";
            }
            else if (rightType->Contains("I род")) {
                textboxright1->Text = "20";
            }
            else if (rightType->Contains("II род")) {
                textboxright1->Text = "50";
            }
        }
        else if (selectedMaterial == "Кирпич")
        {
            textBox1->Text = "0,5";
            textBox2->Text = "2000";
            textBox3->Text = "850";
            textBox4->Text = "10";
            textBox_materialL->Text = "0,24";
            textBox6->Text = "10";
            textBox_materialN->Text = "511";
            textBox8->Text = "2000";

            String^ leftType = comboLeftTypegu->Text;
            String^ rightType = comboRightTypegu->Text;

            if (leftType->Contains("III род (конвекция)")) {
                textboxleft1->Text = "10";
                textboxleft2->Text = "-30";
            }
            else if (leftType->Contains("I род")) {
                textboxleft1->Text = "10";
            }
            else if (leftType->Contains("II род")) {
                textboxleft1->Text = "50";
            }

            if (rightType->Contains("III род (конвекция)")) {
                textboxright1->Text = "10";
                textboxright2->Text = "25";
            }
            else if (rightType->Contains("I род")) {
                textboxright1->Text = "10";
            }
            else if (rightType->Contains("II род")) {
                textboxright1->Text = "30";
            }
        }
        UpdateMaterialFromInput();
    }

    private: System::Void comboBox_material2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ selectedMaterial = comboBox_material2->Text;

        if (selectedMaterial == "Сталь")
        {
            textBox14->Text = "33";
            textBox13->Text = "7710";
            textBox12->Text = "496";
            textBox11->Text = "15,536";
            textBox10->Text = "1";
            textBox9->Text = "512";
        }
        else if (selectedMaterial == "Кирпич")
        {
            textBox14->Text = "0,5";
            textBox13->Text = "2000";
            textBox12->Text = "850";
            textBox11->Text = "10";
            textBox10->Text = "0,24";
            textBox9->Text = "511";
        }
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            String^ timestamp = DateTime::Now.ToString("yyyyMMdd_HHmmss");
            String^ imageFilename = "temperature_chart.png";

            Bitmap^ bmp = gcnew Bitmap(chart->Width, chart->Height);
            chart->DrawToBitmap(bmp, Rectangle(0, 0, bmp->Width, bmp->Height));
            bmp->Save(imageFilename, System::Drawing::Imaging::ImageFormat::Png);
            delete bmp;

            String^ csvFilename = "temperature_data.csv";
            solution->SaveToCSV(csvFilename);

            MessageBox::Show("График сохранен как: " + imageFilename +
                "\nДанные сохранены как: " + csvFilename,
                "Сохранение завершено!",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Ошибка при сохранении: " + ex->Message,
                "Ошибка!",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        chart->Series[0]->Points->Clear();
        chart->Series[1]->Points->Clear();
        label_result->Text = "Результаты будут здесь...";
    }

    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void textboxleft1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void yavn_chb_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void neyavn_chb_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {}
    };
}