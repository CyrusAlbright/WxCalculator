#pragma once

#include "wx/wx.h"
#include <iostream>
#include <string>

class CalculatorForm : public wxFrame {
public:
	CalculatorForm();
	~CalculatorForm();
	void OnButtonClicked(wxCommandEvent& event);

public:
	wxTextCtrl* textBox;
	wxButton** buttons;
	std::string* buttonLabels;

	wxDECLARE_EVENT_TABLE();
};