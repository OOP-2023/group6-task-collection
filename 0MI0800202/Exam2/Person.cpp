//
// Created by swordypepe on 5/20/23.
//

#include "Person.h"

#include <utility>
#include <iostream>
#include <cstring>

int id = 0;
Person::Person(char *_name, int _age, std::string _businessCard, int _intellect)
{
    name = new char[strlen(_name)];
    strcpy(name, _name);
    age = _age;
    businessCard = std::move(_businessCard);
    intellect = _intellect;
    id++;
}

Person::Person(Person &other)
{
    name = other.name;
    age = other.age;
    businessCard = other.businessCard;
    intellect = other.intellect;
}

void Person::printInformation()
{
    std::cout << name << std::endl<< age << std::endl<< businessCard << std::endl<< intellect << std::endl;
}

double Person::coefficientGetter() const
{
    return intellect / age;
}

char* Person::nameGetter()
{
    return name;
}

int Person::idGetter() const
{
    return id;
}

