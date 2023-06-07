#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>

class ComponentBase {
protected:
    float x = 0;
    float y = 0;
public:
    void move(float dx, float dy);
    virtual void showDialog() = 0;
    virtual ComponentBase* clone() = 0;
    ComponentBase() = default;
    ComponentBase(float x, float y);
    virtual ~ComponentBase() = default;
};

void ComponentBase::move(float dx, float dy) {
    x = dx;
    y = dy;
}

ComponentBase::ComponentBase(float x, float y) {
    this->x = x;
    this->y = y;
}

class Label: public ComponentBase {
public:
    char text[16];
    void showDialog() override;
    Label(float x, float y, const char* text);
    Label();
    ComponentBase* clone() override;
};

Label::Label() {
    showDialog();
}

ComponentBase* Label::clone() {
    return new Label(this->x, this->y, this->text);
}

void Label::showDialog() {
    std::cout << "Enter x,y coordinates" << std::endl;
    std::cin >> this->x >> this->y;
    std::cout << "Enter text" << std::endl;
    std::cin.getline(this->text, 16);
}

Label::Label(float x, float y, const char* text):ComponentBase(x, y) {
    strncpy(this->text, text, 16);
}

class RadioButton: public ComponentBase {
    char text[16];
    bool state;
public:
    void showDialog()override;
    void flip();
    bool isOn() const;
    RadioButton();
    RadioButton(float dx, float dy, const char* text, bool isOn);
};



void RadioButton::showDialog() {
    std::cout << "Enter x,y coordinates" << std::endl;
    std::cin >> this->x >> this->y;
    std::cout << "Enter text" << std::endl;
    std::cin.getline(this->text, 16);
    std::cout << "Enter state" << std::endl;
    std::cin >> state;
}
RadioButton::RadioButton(float dx, float dy, const char* text, bool isOn): ComponentBase(x, y) {
    strncpy(this->text, text, 16);
    state = isOn;
}

void RadioButton::flip() {
    state = !state;
}
bool RadioButton::isOn() const {
    return state;
}

class TextBox: public ComponentBase {
    std::string text;
public:
    void showDialog() override;
    TextBox(float x, float y, const char* text);
};

TextBox::TextBox(float x, float y, const char* text):ComponentBase(x, y) {
    this->text = text;
}

void TextBox::showDialog() {
    std::cout << "Enter x,y coordinates" << std::endl;
    std::cin >> this->x >> this->y;
    int withFile = 0;
    std::cout << "Do you want to enter from file?" << std::endl;
    std::cin >> withFile;
    if (withFile) {
        std::string filename;
        std::cout << "Enter filename" << std::endl;
        std::cin >> filename;
        std::ifstream file(filename);
        file >> text;
    }
    else {
        std::cout << "Enter text" << std::endl;
        std::cin >> text;
    }
}

class ComponentCollection {
    std::vector<ComponentBase> components;
public:

};

int main() {
    Label button;
}