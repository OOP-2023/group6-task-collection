#include <iostream>
#include "Game.hpp"
#pragma warning ( disable : 4996)

//----------------------------------------------------------
//I use glabal variables just for optimisation :)
bool isPrime[101];
int SIZE = 101;

void init()
{
	for (size_t i = 2; i <= SIZE; i++)
		isPrime[i] = true;
}

void destroyNumbers(int i)
{
	int toDestroy = i + i;
	while (toDestroy <= SIZE)
	{
		isPrime[toDestroy] = false;
		toDestroy += i;
	}
}

void sieveEratosthenes()
{
	for (size_t i = 2; i <= SIZE; i++)
	{
		if (isPrime[i])
			destroyNumbers(i);
	}
}
//----------------------------------------------------------


void Player::free()
{
	delete[] password;
	delete[] username;
}
void Player::copy(const Player& player)
{
	username = new char[strlen(player.username) + 1];
	password = new char[strlen(player.password) + 1];

	strcpy(username, player.username);
	strcpy(password, player.password);
	age = player.age;
	money = player.money;
}
Player::Player(const char* name, const char* pass, unsigned _age, double _money)
{
	username = new char[strlen(name) + 1];
	strcpy(username, name);
	password = new char[strlen(pass) + 1];
	strcpy(password, pass);
	age = _age;
	money = _money;
}
Player::~Player()
{
	free();
}
Player::Player(const Player& player)
{
	copy(player);
}
Player& Player::operator=(const Player& player)
{
	if (this != &player)
	{
		free();
		copy(player);
	}
	return *this;
}
void Player::setAge(unsigned _age)
{
	if (age <= 10 && age >= 70)
		age = 10; //default

	age = _age;
}
void Player::setMoney(double _money)
{
	money = _money;
}
char* Player::getUsername()
{
	return username;
}
char* Player::getPassword()
{
	return password;
}
unsigned Player::getAge()
{
	return age;
}
int Player::getMoney()
{
	return money;
}
void Player::changeUsername(const char* newName)
{
	delete[] username;
	username = new char[strlen(newName) + 1];
	strcpy(username, newName);
}


void Game::changeMoney(Player& player,double _money)
{
	player.setMoney(_money);
}
bool Game::checkForPassword(Player& player)
{
	std::cout << player.getUsername() << " enter your password please:" << std::endl;
	while (true)
	{
		char buff[1024];
		std::cin.getline(buff, 1024, '\n');
		if (strcmp(player.getPassword(), buff) == 0)
		{
			//std::cout << "You entered the right password" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Wrong password. Try again" << std::endl;
		}
	}
}
bool Game::checkForAges(Player& player)
{
	if (player.getAge() < 18) 
	{
		std:: cout << "You are not old enough" << std::endl;
		return false;
	}
	else 
	{
		std::cout << "Welcome to the game :)" << std::endl;
		std::cout << std::endl;
		return true;
	}
}
bool Game::validBet(int bet, double allMoney)
{
	if (bet <= allMoney)
		return true;
	else {
		std::cout << "You do not have enough money" << std::endl;
		return false;
	}
}
void Game::toLower(char* name)
{
	while (*name)
	{
		if (*name >= 'A' && *name <= 'Z')
			*name = (*name - 'A') + 'a';

		name++;
	}
}
bool Game::isPowerOfTwo(int number)
{
	int step = 1;
	while (step < number)
		step = step << 1;

	if (number == step) return true;
	else return false;
}
void Game::play(Player& player)
{
	checkForPassword(player);
	if (!checkForAges(player))
		return;

	int money = player.getMoney();
	bool changeNumber = true;
	int currentNumber = 0;

	while (true)
	{
		int bet;
		bool wanToQuit = false;
		std::cout << "Your balance is: " << money << std::endl;
		std::cout << "Bet certain amount of money: " << std::endl;
		do {
			std::cin >> bet;
		} while (!validBet(bet,money));
		money -= bet;
		if(changeNumber)
			currentNumber = rand() % 100 + 1;

		std::cout << "currentNumber " << currentNumber << std::endl;
		std::cout << "Make your prediction (write down the number): "<< std::endl;
		std::cout << "1) Odd or Even "<< std::endl;
		std::cout << "2) Prime "<< std::endl;
		std::cout << "3) Power of 2"<< std::endl;
		std::cout << "4) Predict the certain number"<< std::endl;
		std::cout << "5) Leave the game" << std::endl;
		int prediction;
		std::cin >> prediction;

		switch (prediction)
		{
		case 1: {
			std::cout << "Enter even or odd" << std::endl;
			char name[5];
			std::cin.ignore();
			std::cin.getline(name, 5);
			toLower(name);
			if ( !strcmp(name,"even") && !(currentNumber & 1) || !strcmp(name,"odd") && (currentNumber & 1))
			{
				std::cout << "You guessed it right!" << std::endl;
				money += bet + bet * 0.2;
				changeNumber = true;
				continue;
			}
			else
			{
				std::cout << "Wrong guess" << std::endl;
			}
		}; break;
		case 2: {
			if (isPrime[currentNumber])
			{
				std::cout << "You guessed it right!" << std::endl;
				money += bet + bet * 0.5;
				changeNumber = true;
				continue;
			}
			else
			{
				std::cout << "Wrong guess" << std::endl;
			}

		}; break;
		case 3: {

			if (isPowerOfTwo(currentNumber))
			{
				std::cout << "You guessed it right!" << std::endl;
				money += bet * 2;
				changeNumber = true;
				continue;
			}
			else
			{
				std::cout << "Wrong guess" << std::endl;
			}
		}; break;
		case 4: {
			std::cout << "Enter your number between 1-100" << std::endl;
			int playerNum;
			std::cin >> playerNum;
			if (playerNum == currentNumber)
			{
				std::cout << "You guessed it right!" << std::endl;
				money += bet * 10;
				changeNumber = true;
				continue;
			}
			else
			{
				std::cout << "Wrong guess" << std::endl;
			}
		}; break;
		case 5: wanToQuit = true; ; break;
		};

		if (wanToQuit || money == 0) break;

		std::cout << "Do you want to continue with the same number (yes/no)" << std::endl;
		char answ[4];
		std::cin.ignore();
		std::cin.getline(answ, 4);
		toLower(answ);
		std::cout << answ << std::endl;
		if (!strcmp(answ,"yes")) changeNumber = false;
		else if(!strcmp(answ, "no")) changeNumber = true;
	}

	changeMoney(player,money);
	std::cout << "Thank you for you game! Your current balance is: " << player.getMoney()<<std::endl;
}

int main()
{
	//Generating all prime numbers
	init();
	sieveEratosthenes();

	Player player("Pe7atN", "123321", 20, 130); //Creating a profile

	Game game;
	game.play(player);
}
