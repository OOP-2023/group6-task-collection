#include "FormCollection.h"

void FormCollection::free()
{
	for (size_t i = 0; i < count; i++)
	{
		if (data[i] != nullptr)
			delete[] data[i];

		data[i] = nullptr;
	}

	if (data != nullptr)
		delete[] data;
}

void FormCollection::copy(const FormCollection& other)
{
	size = other.size;
	count = other.count;

	for (size_t i = 0; i < other.count; i++)
	{
		delete[] data[i];

		*data[i] = *other.data[i];
	}
}

void FormCollection::resize()
{
	ComponentBase** tempData = data;
	size *= 2;
	data = new ComponentBase * [size];

	for (size_t i = 0; i < count; i++)
	{
		data[i] = tempData[i];
		tempData[i] = nullptr;
	}

	delete[] tempData;
}


FormCollection::FormCollection()
{
	size = 8;
	count = 0;
	data = new ComponentBase* [8] {nullptr};
}

FormCollection::FormCollection(const FormCollection& other)
{
	copy(other);
}

FormCollection::~FormCollection()
{
	free();
}

void FormCollection::addLabel(const Label& label)
{
	if (count == size)
		resize();

	*data[count++] = label;
}

void FormCollection::addRadioButton(const RadioButton& radioButton)
{
	if (count == size)
		resize();

	*data[count++] = radioButton;
}

void FormCollection::addTextBox(const TextBox& textBox)
{
	if (count == size)
		resize();

	*data[count++] = textBox;
}

