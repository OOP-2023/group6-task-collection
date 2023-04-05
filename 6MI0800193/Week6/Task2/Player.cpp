#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"
#include <cstring>
#include <iostream>
void Player::change_name(const char* str)
{
	delete[] name;
	name = new char[strlen(str) + 1];
	strcpy(name, str);
}

Player::Player()
{
	this->name = new char[1];
	name[0] = '\0';

	this->pass = new char[1];
	pass[0] = '\0';

	this->age = 0;
	this->money = 0;
}

Player::Player(const char* name, const char* pass, unsigned age, unsigned money)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->pass = new char[strlen(pass) + 1];
	strcpy(this->pass, pass);

	this->age = age;
	this->money = money;
}

Player::~Player()
{
	delete[] pass;
	delete[] name;
}

Player::Player(const Player& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->pass = new char[strlen(other.pass) + 1];
	strcpy(this->pass, other.pass);

	this->age = other.age;
	this->money = other.money;
}

Player& Player::operator=(const Player& rhs)
{
	if (this != &rhs)
	{
		delete[] name;
		delete[] pass;

		this->name = new char[strlen(rhs.name) + 1];
		strcpy(this->name, rhs.name);

		this->pass = new char[strlen(rhs.pass) + 1];
		strcpy(this->pass, rhs.pass);

		this->age = rhs.age;
		this->money = rhs.money;
	}
	return *this;
}

bool Player::enter_password()
{
	char pass_enter[200];

	std::cout << "Enter password: " << std::endl;
	std::cin.getline(pass_enter, 200);

	return strcmp(pass_enter, this->pass) == 0;
}

bool Player::validate_age()
{
	return this->age >= 18;
}


