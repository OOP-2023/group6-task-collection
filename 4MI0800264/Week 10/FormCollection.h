#pragma once

#include "ComponentBase.h"
#include "Label.h"
#include "RadioButton.h"
#include "TextBox.h"

class FormCollection
{
	ComponentBase** data;
	int size;
	int count;

	void free();

	void copy(const FormCollection& other);

	void resize();

public:

	FormCollection();

	FormCollection(const FormCollection& other);

	~FormCollection();

	void addLabel(const Label& label);

	void addRadioButton(const RadioButton& radioButton);

	void addTextBox(const TextBox& textBox);
};
