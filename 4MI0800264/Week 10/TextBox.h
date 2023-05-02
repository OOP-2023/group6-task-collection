#pragma once
#include "ComponentBase.h"

class TextBox : public ComponentBase
{
	char* text;

public:

	TextBox& operator= (const TextBox& other);

	void showDialog();

	~TextBox();
};
