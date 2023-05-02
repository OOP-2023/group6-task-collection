#pragma once

#include "ComponentBase.h"
#pragma warning(disable:4996)

class RadioButton : public ComponentBase
{
	char text[16];
	bool isChosen;

public:

	RadioButton& operator= (const RadioButton& other);

	void showDialog();

	void flip();

	bool isOn() const;
};
