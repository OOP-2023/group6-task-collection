#ifndef _GAME_HPP
#define _GAME_HPP
class Player
{
private:
	char* username;
	char* password;
	unsigned age;
	double money;
	void free();
	void copy(const Player& player);
public:
	Player(const char* name, const char* pass, unsigned _age, double _money);
	~Player();
	Player(const Player& player);
	Player& operator=(const Player& player);
	void setAge(unsigned _age);
	void setMoney(double _money);
	char* getUsername();
	char* getPassword();
	unsigned getAge();
	int getMoney();
	void changeUsername(const char* newName);
};

class Game
{
private:
	void changeMoney(Player& player, double _money);
	bool checkForPassword(Player & player);
	bool checkForAges(Player& player);
	bool validBet(int bet, double allMoney);
	void toLower(char* name);
	bool isPowerOfTwo(int number);
public:
	void play(Player& player);
};

#endif // !_GAME_HPP

