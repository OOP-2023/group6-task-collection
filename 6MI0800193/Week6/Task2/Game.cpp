#include "Game.h"

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
		cout << "0 - Exit" << endl;
		cout << "1 - Guess odd or even." << endl;
		cout << "2 - Guess prime or not." << endl;
		cout << "3 - Guess power of two or not." << endl;
		cout << "4 - Guess exact number." << endl;
		cout << "Choose bet: ";

		int num;
		cin >> num;

		switch (num)
		{
		case Bet::exit:
			break;
		case Bet::odd_or_even:
			break;
		case Bet::prime_or_not:
			break;
		case Bet::is_pow_of:
			break;
		case Bet::guess_num:
			break;
		default:
			break;
		}
	}
}