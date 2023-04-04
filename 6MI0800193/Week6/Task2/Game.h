#pragma once
#include "Player.h"
#include <iostream>
using namespace std;
enum Bet
{
	exit = 0,
	odd_or_even = 1,
	prime_or_not = 2,
	is_pow_of = 3,
	guess_num = 4

};

class Game
{
public:
	void Play(Player& player);
};

