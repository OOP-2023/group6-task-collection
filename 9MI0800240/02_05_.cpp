// 02_05_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#pragma warning (disable:4996)

class ComponentBase
{
protected:
    float x;
    float y;
public:
    virtual void showDialog() = 0;

    void move(float dx, float dy)
    {
        x = dx;
        y = dy;
    }

    virtual ComponentBase* clone() const = 0;

    virtual ~ComponentBase()= default;
};
class Label : public ComponentBase
{
private:
    char arr[16];
public:
    void showDialog() override 
    {
        std::cin >> x;
        std::cin >> y;
        std::cin.getline(arr, 16);
    }

    ComponentBase* clone() const
    {
        return new Label(*this);
    }
};

class RadioButton : public ComponentBase 
{
private:
    char arr[16];
    bool checkButton;
public:
    void showDialog() override 
    {
        std::cin.getline(arr, 16);
        std::cout << "Check the Radio button (true or false) = ";
        std::cin >> checkButton;
    }

    ComponentBase* clone() const
    {
        return new RadioButton(*this);
    }

    void flip()
    {
        checkButton = !checkButton;
    }

    bool isOn() const
    {
        return checkButton;
    }
};

class TextBox : public ComponentBase
{
private:
    char* inputText;

    void copy(const TextBox& t)
    {
        inputText = new char[strlen(t.inputText) + 1];
        strcpy(this->inputText, t.inputText);
    }
    void free()
    {
        delete[] inputText;
    }
public:
    TextBox()
    {
        inputText = nullptr;
    }

    TextBox(const TextBox& other)
    {
        copy(other);
    }
    TextBox& operator=(const TextBox& other)
    {
        if (this != &other)
        {
            free();
            copy(other);
        }
        return *this;
    }
    ~TextBox()
    {
        free();
    }

    ComponentBase* clone() const
    {
        return new TextBox(*this);
    }

    void showDialog() override 
    {
        std::cout << "Input text: ";
        std::cin.getline(inputText,1024);
    }
};

class CollectionForms
{
private:
    std::vector<ComponentBase*> collection;
    size_t vectorSize = collection.size();

public:
    void addLabel()
    {
        collection.push_back(new Label);
    }

    void addRadioButton()
    {
        collection.push_back(new RadioButton);
    }

    void addTextBox()
    {
        collection.push_back(new TextBox);
    }

    CollectionForms(const CollectionForms& current)
    {
        for (size_t i = 0; i < current.collection.size(); i++)
        {
            collection.push_back(
                current.collection[i]->clone()
            );
        }
    }

    ~CollectionForms()
    {
        for (size_t i = 0; i < collection.size(); i++)
        {
            delete collection[i];
        }
    }

};

int main()
{
    
}

