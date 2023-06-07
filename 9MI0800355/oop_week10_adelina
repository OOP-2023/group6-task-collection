#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

class ComponentBase {
protected:
    float x;
    float y;
public:
    virtual void showDialog()const = 0;
    void move(float dx, float dy){
        x = dx;
        y = dy;
    }
    virtual ~ComponentBase() = default;
};
class Label :public ComponentBase {
private:
    char name[16];
public:
    void showDialog()const override {
        cout << "Enter x: ";
        cout << "Enter y: ";
        cout << "Enter name: ";
    }
};
class RadioButton :public ComponentBase {
private:
    char name[16];
    bool isUsed;
public:
    void showDialog() const override {
        cout << "Enter name: ";
        cout << "On: " << isUsed;
    }
    bool flip() {
        isUsed = !isUsed;
    }
    bool isOn() const {
        return isUsed;
    }
};
class TextBox : public ComponentBase {
private:
    char* text;
public :
    void free();
    void copy(TextBox& other);

    TextBox();
    TextBox(TextBox& other);
    TextBox& operator=(TextBox& other);
    ~TextBox();

    void showDialog()const override {
        cout << "Enter text: ";
    }
};
void TextBox::free() {
    delete[] text;
    text = nullptr;
}
void TextBox::copy(TextBox& other) {
    strcpy(text, other.text);
}
TextBox::TextBox() {
    text = new char[100];
}
TextBox::TextBox(TextBox& other) {
    copy(other);
}
TextBox& TextBox::operator=(TextBox& other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}
TextBox::~TextBox() {
    free();
}
class Forms {
private:
    vector<ComponentBase*> vector;
public:
    void addLabel(Label& label);
    void addRadioButton(RadioButton& radiobutton);
    void addTextBox(TextBox& textbox);
};
void Forms::addLabel(Label& label) {
    vector.push_back(&label);
}
void Forms::addRadioButton(RadioButton& radiobutton) {
    vector.push_back(&radiobutton);
}
void Forms::addTextBox(TextBox& textbox) {
    vector.push_back(&textbox);
}
int main()
{
}
