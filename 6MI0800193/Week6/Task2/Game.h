#pragma once
#include "Player.h"
#include <iostream>
using namespace std;
enum Bet
{
	leave = 0,
	odd_or_even = 1,
	prime_or_not = 2,
	is_pow_of = 3,
	guess_num = 4

};

class Game
{
private:
	unsigned secret_number;
	unsigned wagered_ammount;
	bool secret_num_prime;
	bool secret_num_even;
	bool secret_num_pow_of_two;
	void generate_number();
	void bet_odd_or_even(Player& player);
	void bet_prime_or_not(Player& player);
	void bet_is_pow_of(Player& player);
	void guess_num(Player& player);
	void is_prime(unsigned num);

public:
	void Play(Player& player);
};

