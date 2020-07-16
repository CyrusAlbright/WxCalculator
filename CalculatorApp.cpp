#include "CalculatorApp.h"

wxIMPLEMENT_APP(CalculatorApp);

CalculatorApp::CalculatorApp() {

}

CalculatorApp::~CalculatorApp() {

}

bool CalculatorApp::OnInit() {
	form = new CalculatorForm();
	form->Show();
	return true;
}