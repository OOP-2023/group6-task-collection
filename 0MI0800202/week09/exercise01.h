
#ifndef WEEK09_EXERCISE01_H
#define WEEK09_EXERCISE01_H

#include <iostream>
#include <vector>

class ComponentBase
{
protected:
    int x, y;
public:
    virtual void showDialog() = 0;
    virtual ~ComponentBase() = default;
    void move(int dx, int dy);
};
class Label : public ComponentBase
{
private:
    char arr[16];
public:
    void showDialog() override;
};

int f(int x)
{
    return !(!x);
}
class RadioButton : public ComponentBase
{
private:
    char arr[16];
    bool chosen;
public:
    void showDialog() override;
    void flip()
    {
        chosen = !chosen;
    }
    bool isOn() const
    {
        return chosen;
    }
};
class TextBox : public ComponentBase
{
private:
    std::string arr;
public:
    void showDialog() override;
};
class Collection
{
private:
    std::vector<ComponentBase*> collection;
public:
    void addLabel(Label label);
    void TextBox(TextBox textBox);
    void RadioButton(RadioButton radioButton);
};
void f() {
    std::vector<ComponentBase*> v;


}
#endif
