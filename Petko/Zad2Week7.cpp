// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;
class Player {
private:
    char* firstName;
    char* password;
    unsigned age;
    int money;
public:
    Player(char const* name, char const* pass, unsigned& years, int& mon);
    void changeName(char const* anotherName);
    ~Player();
};
Player::Player(char const* name, char const* pass, unsigned& years, int& mon)
{
    firstName = new char[strlen(name) + 1];
    strcpy(firstName, name);
    password = new char[strlen(pass) + 1];
    strcpy(password, pass);
    age = years;
    money = mon;
}
void Player::changeName(char const* anotherName)
{
    delete[] firstName;
    firstName = new char[strlen(anotherName) + 1];
    strcpy(firstName, anotherName);
}
Player::~Player()
{
    delete[]firstName;
    delete[]password;
}
enum Guess {
    evenOrOdd,
    isPrime,
    isPowOfTwo,
    guessNum
};
class Game {
private:
    unsigned num;
    Guess guess;
public:
    Game(unsigned num,Guess guess);
};

int main()
{
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
