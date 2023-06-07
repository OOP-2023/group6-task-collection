#include "exercise01.h"
#include <iostream>
void ComponentBase::move(const int dx, int dy)
{
    x = dx;
    y = dy;
}

void TextBox::showDialog()
{
        std::cin >> x >> y;
        std::cin >> arr;
}

void RadioButton::showDialog()
{
    char replacementArr[16];
    std::cin >> x >> y;
    std::cin >> chosen;
    std::cin.getline(arr, 16);
    std::cin.ignore();
}

void Label::showDialog()
{
    char replacementArr[16];
    std::cin >> x >> y;
    std::cin.getline(arr, 16);
    std::cin.ignore();
}

void Collection::addLabel(Label label)
{
    collection.push_back(new Label(label));
}
void Collection::addTextBox(TextBox textBox)
{
    collection.push_back(new TextBox(textBox));
}
void Collection::addRadioButton(RadioButton radioButton)
{
    collection.push_back(new RadioButton(radioButton));
}

