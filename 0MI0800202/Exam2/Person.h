#ifndef EXAM2_PERSON_H
#define EXAM2_PERSON_H


#include <string>

class Person
{
private:
    static int id;
    char* name;
    double age;
    std::string businessCard;
    double intellect;
public:
    Person(char* _name, int _age, std::string _businessCard, int _intellect);
    Person(Person& other);
    void printInformation();
    double coefficientGetter() const;
    char* nameGetter();
    int idGetter() const;
};


#endif //EXAM2_PERSON_H
