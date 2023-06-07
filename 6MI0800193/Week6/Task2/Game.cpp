#include "Game.h"

void Game::bet_odd_or_even(Player& player)
{
	system("CLS");
	cout << "Guessing odd or even." << endl;
	cout << "Your guess? (1 - odd; 2 - even): ";
	int choice;
	cin >> choice;

	if ((choice == 1 && secret_number % 2 != 0) || (choice == 2 && secret_number % 2 == 0))
	{
		cout << "You guessed right!. You win: " << wagered_ammount * 1.20 << endl;
		player.money += wagered_ammount * 1.20;
	}
	else
	{
		cout << "You guessed wrong! You lost: " << wagered_ammount << endl;
	}
}

void Game::bet_prime_or_not(Player& player)
{
	system("CLS");
	cout << "Guessing prime or not." << endl;
	cout << "Your guess? (1 - prime; 2 - not prime): ";
	int choice;
	cin >> choice;

	if ((choice == 1 && secret_num_prime) || (choice == 2 && !secret_num_prime))
	{
		cout << "You guessed right!. You win: " << wagered_ammount * 1.50 << endl;
		player.money += wagered_ammount * 1.50;
	}
	else
	{
		cout << "You guessed wrong! You lost: " << wagered_ammount << endl;
	}
}

void Game::bet_is_pow_of(Player& player)
{
	system("CLS");
	cout << "Guessing power of two or not." << endl;
	cout << "Your guess? (1 - pow of two; 2 - not pow of two): ";
	int choice;
	cin >> choice;

	if ((choice == 1 && secret_num_pow_of_two) || (choice == 2 && !secret_num_pow_of_two))
	{
		cout << "You guessed right!. You win: " << wagered_ammount * 2 << endl;
		player.money += wagered_ammount * 2;
	}
	else
	{
		cout << "You guessed wrong! You lost: " << wagered_ammount << endl;
	}
}

void Game::guess_num(Player& player)
{
	system("CLS");
	cout << "Guessing exact number." << endl;
	cout << "Your guess?: ";
	int choice;
	cin >> choice;

	if ((choice == secret_number))
	{
		cout << "You guessed right!. You win: " << wagered_ammount * 10 << endl;
		player.money += wagered_ammount * 10;
	}
	else
	{
		cout << "You guessed wrong! You lost: " << wagered_ammount << endl;
	}
}

void Game::generate_number()
{
	secret_number = rand() % 100 + 1;
	secret_num_even = (secret_number % 2 == 0);
	is_prime(secret_number);
	secret_num_pow_of_two = !((secret_number)&(secret_number - 1));
}

void Game::is_prime(unsigned num)
{
	for (size_t i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			this->secret_num_prime = false;
			return;
		}
	}
	this->secret_num_prime = true;
}

void Game::Play(Player& player)
{
	if (!player.validate_age())
	{
		cout << "Not over 18!" << endl;
		return;
	}
	if (!player.enter_password())
	{
		cout << "Invalid password!" << endl;
		return;
	}


	while (player.money > 0)
	{
		cout << endl;
		generate_number();
		cout << "New number generated: " << endl;
		cout << "Current money: " << player.money << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Guess odd or even." << endl;
		cout << "2 - Guess prime or not." << endl;
		cout << "3 - Guess power of two or not." << endl;
		cout << "4 - Guess exact number." << endl;
		cout << endl;
		cout << "Choose bet: ";

		int num;
		cin >> num;

		wagered_ammount = 0;
		cout << endl;
		cout << "Choose bet ammount: " << endl;
		cin >> wagered_ammount;

		player.money -= wagered_ammount;

		switch (num)
		{
		case Bet::leave:
			return;
			break;
		case Bet::odd_or_even:
			bet_odd_or_even(player);
			break;
		case Bet::prime_or_not:
			bet_prime_or_not(player);
			break;
		case Bet::is_pow_of:
			bet_is_pow_of(player);
			break;
		case Bet::guess_num:
			guess_num(player);
			break;
		default:
			cout << "Invalid command!" << endl;
			break;
		}
	}
	cout << "Game over!" << endl;
}