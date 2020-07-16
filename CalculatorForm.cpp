#include "CalculatorForm.h"

wxBEGIN_EVENT_TABLE(CalculatorForm, wxFrame)
wxEND_EVENT_TABLE()

CalculatorForm::CalculatorForm() : wxFrame(nullptr, wxID_ANY, "My Form", wxPoint(50, 50), wxSize(400, 600)) {
	textBox = new wxTextCtrl(this, wxID_ANY);
	buttons = new wxButton*[24];
	wxGridSizer* grid = new wxGridSizer(6, 4, wxSize(0, 0));
	wxBoxSizer* container = new wxBoxSizer(wxVERTICAL);
	buttonLabels = new std::string[24]{
		"^",
		"CE",
		"Clear",
		"Back",
		"1/x",
		"x^2",
		"sqrt(x)",
		"/",
		"7",
		"8",
		"9",
		"*",
		"4",
		"5",
		"6",
		"-",
		"1",
		"2",
		"3",
		"+",
		"+/-",
		"0",
		".",
		"="
	};

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			int id = i * 4 + j;
			wxString label(buttonLabels[id].c_str(), wxConvUTF8);
			buttons[id] = new wxButton(this, id, label);
			buttons[id]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorForm::OnButtonClicked, this);
			grid->Add(buttons[id], 1, wxEXPAND | wxALL);
		}
	}

	container->Add(textBox, 1, wxEXPAND | wxALL);
	container->Add(grid, 3, wxEXPAND | wxALL);

	this->SetSizer(container);
	container->Layout();
}

CalculatorForm::~CalculatorForm() {
	delete buttons;
}

void CalculatorForm::OnButtonClicked(wxCommandEvent& event) {
	int id = event.GetId();
	std::string label = buttonLabels[id];
	std::string text = textBox->GetValue().ToStdString();

	if (label == "Clear") {
		textBox->Clear();
	} else if (label == "x^2") {
		(*textBox) << "^2";
	} else if (label == "1/x") {
		std::string expression = "1/(" + textBox->GetValue().ToStdString() + ")";
		textBox->SetLabelText(expression);
	} else if (label == "sqrt(x)") {
		std::string expression = "sqrt(" + textBox->GetValue().ToStdString() + ")";
		textBox->SetLabelText(expression);
	} else {
		(*textBox) << label.c_str();
	}

	event.Skip();
}