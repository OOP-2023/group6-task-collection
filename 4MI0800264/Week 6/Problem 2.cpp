#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable:4996)

bool isPrime(int number)
{
	int end = sqrt(number);

	for (int i = 2; i <= end; i++)
	{
		if (number % i == 0)
			return false;
	}

	return true;
}

bool isPowerOf2(int number)
{
	int i = 1;
	while (i < number)
		i *= 2;

	return i == number;

}

void userInputMethod(int& method)
{
	while (method < 1 || method > 5)
	{
		std::cout << "Enter Method For Playing this Round: \n type 1: Guess if the number is even/odd. If you guess, you win 1/5 of you bet. \n type 2: Guess if the number is Prime. If you guess, you win 1/2 of you bet. \n type 3: Guess if the number is a power of 2. If you guess, you double your bet. \n type 4: Guess if the number. If you guess, you win 10 times your bet. \n type 5: Quit Game";
		std::cin >> method;
	}
}

void userInputBet(int& bet)
{
	while (bet < 1)
	{
		std::cout << "Enter your bet: \n";
		std::cin >> bet;
	}
}

void userInputEvenOrOdd(int& evenOrOdd)
{
	while (evenOrOdd != 1 && evenOrOdd != 0)
	{
		std::cout << "Enter: \n 0: if the number is even \n 1: if the nuber is odd";
		std::cin >> evenOrOdd;
	}
}

void userInputPlayerNumber(int& playerNumber)
{
	while (playerNumber < 1 || playerNumber > 100)
	{
		std::cout << "Enter Number: \n";
		std::cin >> playerNumber;
	}
}

class Player
{
	char* name;
	char* password;
	int age;
	int balance;

public:

	//TODO: FINISH THE BIG FOUR

	char* getName()
	{
		return name;
	}
	void setName(const char* inputName)
	{
		strcpy(name, inputName);
	}

	char* getPassword()
	{
		return password;
	}
	void sedPassword(const char* inputPassword)
	{
		strcpy(password, inputPassword);
	}

	int getAge()
	{
		return age;
	}
	void setAge(int inputAge)
	{
		age = inputAge;
	}

	int getBalance()
	{
		return balance;
	}
	void setBalance(int inputBalance)
	{
		balance = inputBalance;
	}
};

void PlayRound(Player& player, int& playerNumber, int systemNumber, int bet, int method, int evenOrOdd, bool& quitGame)
{
	do
	{
		userInputBet(bet);
		player.setBalance(player.getBalance() - bet);

		userInputMethod(method);

		if (method == 1)
		{
			userInputEvenOrOdd(evenOrOdd);

			if ((evenOrOdd == 1 && systemNumber % 2 == 1) ||
				(evenOrOdd == 0 && systemNumber % 2 == 0))
			{
				bet += bet / 5;
			}
			else
				bet = 0;
		}
		else if (method == 2)
		{
			bet = (isPrime(systemNumber)) ? bet * 1.5 : 0;
		}
		else if (method == 3)
		{
			bet = (isPowerOf2(systemNumber)) ? bet * 2 : 0;
		}
		else if (method == 4)
		{
			userInputPlayerNumber(playerNumber);
			bet = (playerNumber == systemNumber) ? bet * 10 : 0;
		}
		else
			quitGame = true;

		player.setBalance(player.getBalance() + bet);
	} while (!quitGame || player.getBalance() != 0);
}

class Game
{
public:
	void play(Player& player)
	{
		char* playerInputPassword;
		int playerNumber = 0, systemNumber = 0, method = 0, bet = 0, evenOrOdd = 0;
		bool quitGame = false;

		do
		{
			std::cout << "Enter your Password: \n";
			std::cin.ignore();
			std::cin >> playerInputPassword;
		} while (strcmp(playerInputPassword, player.getPassword()) != 0);

		while (!quitGame || player.getBalance() != 0)
		{
			systemNumber = rand() % 100 + 1;

			PlayRound(player, playerNumber, systemNumber, bet, method, evenOrOdd, quitGame);
		}
	}
};

int main()
{

	return 0;
}