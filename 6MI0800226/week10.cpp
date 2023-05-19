#include <iostream>
#include "ComponentBase.hpp"

int main()
{
	FormsCollection* forms = new FormsCollection();
	forms->addLabel(1, 2, "yo");
	forms->addRadioButton(3, 5, "nb", true);
	forms->addTextBox(6, 7, "string yo");
	forms->print();
}