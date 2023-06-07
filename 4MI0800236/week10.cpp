// week10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class ComponentBase {
protected:
    float x;
    float y;
public: 
    virtual void showDialog() = 0;

    void move(float dx, float dy) {
        x = dx;
        y = dy;
    }
};

class Label :public ComponentBase {
private:
    char arr[16];
public:
    void showDialog() override {
        std::cout << "Enter x";
        std::cin >> x;
        std::cout << "Enter y";
        std::cin >> y;
        std::cout << "Enter label name";
        std::cin.getline(arr, 16);
    }
};

class RadioButton :public ComponentBase {
private:
    char arr[16];
    bool checkIfButtonIsPressed;
public:
    void showDialog() override {
        std::cout << "Enter x:";
        std::cin >> x;
        std::cout << "Enter y:";
        std::cin >> y;
        std::cout << "Enter name:";
        std::cin.getline(arr, 16);
        std::cout << "Check if the button is pressed: ";
        std::cin >> checkIfButtonIsPressed;
    }

    void flip() {
        checkIfButtonIsPressed != checkIfButtonIsPressed;
    }

    bool isOn() const {
        return checkIfButtonIsPressed;
    }
};

class TextBox :public ComponentBase {
private:
    std::string text;
public: 
    void showDialog() override {
        std::cout << "Enter x:";
        std::cin >> x;
        std::cout << "Enter y:";
        std::cin >> y;
        std::cout << "Enter text";
        std::getline(std::cin, text);
    }
   
};

#include <vector>

class Collection {
private:
    std::vector<ComponentBase> collection;
public:
    void addLabel();
    void addradioButton();
    void addTextBox();
};

int main()
{
    std::cout << "Hello World!\n";
}

