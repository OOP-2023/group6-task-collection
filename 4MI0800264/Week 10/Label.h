#pragma once

#include "ComponentBase.h"
#pragma warning(disable:4996)


class Label : public ComponentBase
{
	char array[16];

public:

	Label& operator= (const Label& other);
	

	void showDialog();
};