#include "FormCollection.h"

int main()
{
	Label label1;
	label1.showDialog();

	RadioButton radioButton1;
	radioButton1.showDialog();

	TextBox textBox1;
	textBox1.showDialog();

	FormCollection formCollection;
	formCollection.addLabel(label1);
	formCollection.addRadioButton(radioButton1);
	formCollection.addTextBox(textBox1);

	return 0;
}