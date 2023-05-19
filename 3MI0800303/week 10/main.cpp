#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ComponentBase {
    private:
        float x;
        float y;
    public:
        virtual ~ComponentBase() = default;
        virtual void showDialog() = 0;
        virtual ComponentBase* clone() const = 0;
        virtual void print() const = 0;

        void move(float dx, float dy);
        void setX(float _x) { x = _x; }
        void setY(float _y) { y = _y; }
        float getX() const {return x;}
        float getY() const {return y;}
};

class Label : public ComponentBase {
    private:
        char symbs[17];
    public:
        Label(){}
        ~Label() override {}
        Label* clone() const override { return new Label(*this); }
        void print() const override {
            cout << getX() << " " << getY() << " " << symbs << endl;
        }
        void showDialog() override {
            cout << "Enter coorinates and 16 chars";
            int x,y;
            cin >> x >> y;
            
            setX(x); 
            setY(y);

            cin.getline(symbs, 17);
        }
};

class RadioButton : public ComponentBase {
    private:
        char symbs[17];
        bool active;
    public:
        RadioButton(){}
        ~RadioButton() override {}
        RadioButton* clone() const override { return new RadioButton(*this); }

        void print() const override {
            cout << getX() << " " << getY() << " " << symbs << " " << active << endl;
        }

        void showDialog() override {
            cout << "Enter coorinates and 16 chars";
            int temp1,temp2;
            cin >> temp1 >> temp2;
            
            setX(temp1); 
            setY(temp2);

            cin.getline(symbs, 17);
            cout << "Is the button acctive. Enter 1 for yes and 0 for no";
            cin >> temp1;
            active = temp1;
        }
        void flip(){
            active = !active;
        }
        bool isOn(){
            return active;
        }
};

class TextBox : public ComponentBase {
    private:
        string text;
    public:
        TextBox(){}
        ~TextBox() override {}
        TextBox* clone() const override { return new TextBox(*this); }

        void print() const override {
            cout << getX() << " " << getY() << " " << text << endl;
        }

        void showDialog() override {
            cout << "Enter text";
            getline(cin, text);
        }
};

class FormCollection {
    private:
        vector<ComponentBase*> forms;
    public:
        FormCollection(){}
        FormCollection(const FormCollection& other){
            size_t size = other.forms.size();
            forms.reserve(size);
            for (size_t i = 0; i < size; i++)
            {
                forms.push_back(other.forms[i]->clone());
            }
        }
        ~FormCollection(){
            size_t size = forms.size();
            for (size_t i = 0; i < size; i++)
            {
                delete forms[i];
            }
        }

        // void addLabel(const Label& label){
        //     forms.push_back(label.clone());
        // }

        // void addRadioButton(const RadioButton& radiobtn){
        //     forms.push_back(radiobtn.clone());
        // }
        
        // void addTextBox(const TextBox& tbox){
        //     forms.push_back(tbox.clone());
        // }

        void addLabel(){
            Label temp;
            temp.showDialog();
            forms.push_back(temp.clone());
        }

        void addRadioButton(){
            RadioButton temp;
            temp.showDialog();
            forms.push_back(temp.clone());
        }
        
        void addTextBox(){
            TextBox temp;
            temp.showDialog();
            forms.push_back(temp.clone());
        }

        void print() const {
            size_t size = forms.size();
            for (size_t i = 0; i < size; i++)
            {
                forms[i]->print();
            }
            
        }
};

int main(){
    FormCollection collection;

    collection.addLabel();

    collection.print();
}