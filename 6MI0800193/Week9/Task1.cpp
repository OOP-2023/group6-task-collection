#include <iostream>
#include "FormsCollection.hpp"
int main()
{
    FormsCollection fc = FormsCollection();
    fc.add_label();
    fc.add_radio_button();
    fc.add_text_box();

    fc.call_show_dialog_at(0);
    fc.call_show_dialog_at(1);
    fc.call_show_dialog_at(2);

    for (size_t i = 0; i < fc.get_len(); i++)
    {
        std::cout << std::endl;
        fc.get_at(i)->print();
        std::cout << std::endl;
    }

    FormsCollection fc2 = FormsCollection(fc);

    fc2.call_show_dialog_at(0);

    fc.get_at(0)->print();
    fc2.get_at(0)->print();

}

/*
20
20
Label1
RadioTest
Textboxtestingwdawd
*/