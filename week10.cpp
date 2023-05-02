#include <iostream>
#include <cstring>

class ComponentBase {
protected:
    float x, y;
public:
    virtual showDialog() = 0;
    void move(float dx, float dy) {
        x=dx;
        y=dy;
    }

    virtual ~ComponentBase() = default;
};

class Label: public ComponentBase{
private:
   char arr[16];
public:
    showDialog() override {
        std::cout<<"Please enter coordinates: ";
        std::cout<<std::endl<<"x = "; std::cin>>x;
        std::cout<<std::endl<<"y = "; std::cin>>y;
    }

};

class RadioButton: public ComponentBase{
private:
    char text[16];
    bool isChosen;
public:
    bool isOn() const{
        return isChosen;
    }
    showDialog() override {
        std::cout<<"Please enter a text (max 15 symbols): "<<std::endl;
        std::cin.getline(text, 16);
        std::cout<<std::endl<<isChosen;
    }
    flip(){
        isChosen=!isChosen;
    }
};

class TextBox: public ComponentBase{
private:
    char* str;
public:
    showDialog() override {
        std::cout<<"Please enter a text:"<<std::endl;
        std::cin.getline(str, '\0');
    }

    //constructor
    TextBox(char* _str){
        str=new char[strlen(_str)+1];
        strcpy(str, _str);
    }
    //destructor
    ~TextBox(){
        delete [] str;
    }
    //copy constructor
    TextBox(TextBox const& other){
        str=new char[strlen(other.str)+1];
        strcpy(str, other.str);
    }
    //operator=
    TextBox& operator=(TextBox const& other){
        if(this!=&other){
            delete [] str;
            str=new char[strlen(other.str)+1];
            strcpy(str, other.str);
        }
        return *this;
    }
    //move constructor
    TextBox(TextBox && other){
        str=other.str;
        other.str=nullptr;
    }
    //move operator=
    TextBox& operator=(TextBox&& other){
        if(this!=&other){
            delete[]str;
            str=other.str;
            other.str=nullptr;
        }
        return *this;
    }
};

#include <vector>
class Collection {
private:
    std::vector<ComponentBase*> collection;
public:
    void addLabel();
    void addRadioButton();
    void addText();
};

void Collection::addLabel() {
    this->collection.push_back(new Label());
}

void Collection::addRadioButton(){
    this->collection.push_back(new RadioButton());
}

void Collection::addText(){
    this->collection.push_back(new Text());
}

int main() {
   // ComponentBase* t = new Label();
    Collection c;
    c.addText();
    c.addLabel();
}
