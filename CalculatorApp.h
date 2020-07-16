#pragma once

#include "wx/wx.h"
#include "CalculatorForm.h"

class CalculatorApp : public wxApp {
public:
	CalculatorApp();
	~CalculatorApp();
	virtual bool OnInit();

private:
	CalculatorForm* form = nullptr;
};