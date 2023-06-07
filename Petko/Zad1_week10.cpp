#include <iostream>
#include <cstring>
using namespace std;
class ComponentBase {
protected:
	float x;
	float y;
public:
	virtual void showDialog() = 0;
	void move(float dx, float dy);
	virtual ~ComponentBase() = default;
};
void ComponentBase::move(float dx, float dy) {
	x += dx;
	y += dy;
}

class Label :public ComponentBase {
private:
	char label[16];
public:
	void showDialog() override;
};
void Label::showDialog() {
	cout << "Enter X";
	cin >> x;
	cout << "Enter Y";
	cin >> y;
	cout << "Enter name of the label";
	cin.getline(label, 16);
}
class RadioButton :public ComponentBase {
private:
	char string[16];
	bool button = false;
public:
	void showDialog() override;
	void flip();
	bool isOn() const;
};
void RadioButton::showDialog() {
	cout << "Enter name of the label";
	cin.getline(string, 16);
	cout << "Is the button turned on";
	cin >> button;
}
void RadioButton::flip() {
	button = !button;
}
bool RadioButton::isOn()const {
	return button == 1;
}
class TextBox :public ComponentBase {
private:
	char* str;
public:
	void showDialog()override;
	TextBox();
	~TextBox();
	TextBox(TextBox const& other);
	TextBox& operator=(const TextBox& other);
};
TextBox::TextBox()
{
	str = nullptr;
}
TextBox::TextBox(TextBox const& other) {
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
}
TextBox& TextBox::operator=(const TextBox& other) {
	if (this != &other) {
		delete[]str;
		str = new char[strlen(other.str) + 1];
		strcpy(str, other.str);
	}
}
void TextBox::showDialog() {
	unsigned size = 0;
	cout << "Enter size";
	cin.getline(str, size);
}
TextBox::~TextBox() {
	delete[] str;
}
int main()
{

}