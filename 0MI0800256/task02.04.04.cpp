#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(size_t number) {
	while(number!=0)
	{
		for (int i = 1; i < sqrt(number); ++i)
		{
			if (number % i == 0)
				return false;	
		}
		return true;
	}
}
bool isDegreeOfTwo(size_t number)
{
	while (number != 0)
	{
		number / 2;
	}
	if (number != 1)
		return false;
	return true;
}
class Player
{
private:
	char* name;
	char* password;
	size_t age;
	size_t money;

public:
	Player() {};
	Player(char* name, char* password);
	Player(Player& const gamer, Player& const gamer2);
	Player& operator=(Player& const gamer);
	~Player();
	void setMoney(size_t m) {
		money = m;
	}
	int getMoney() const {
		return money;
	}

};

Player::Player(char* name, char* password) {
	char* name = new char[50];
	char* password = new char[50];

}
Player::Player(Player& const gamer, Player& const gamer2) {
	gamer.name = gamer2.name;
	gamer.password = gamer2.password;
	gamer.age = gamer2.age;
	gamer.money = gamer2.money;
}
Player& Player::operator=(Player& const gamer) {
	return *this;
}
Player::~Player() {
	delete[] name;
	delete[] password;
}


class Play {
private:
	size_t number;
	size_t suggestion;
public:
	void play(Player& player);
};

void Play::play(Player& player) {
	if (suggestion % 2 == number % 2)
		player.setMoney(player.getMoney() + player.getMoney() / 5);

	if (isPrime(suggestion) == isPrime(number))
		player.setMoney(player.getMoney() + player.getMoney() / 2);

	if (isDegreeOfTwo(suggestion) == isDegreeOfTwo(number))
		player.setMoney(player.getMoney() * 2);

	if (suggestion == number)
		player.setMoney(player.getMoney() * 10);
}
int main()
{

}
