#include "MyForm.h"
#include <cmath>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Globalization;

[STAThreadAttribute]
void main(array<String^>^ args)

{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    calculatorv1::MyForm form;
    Application::Run(% form);
}