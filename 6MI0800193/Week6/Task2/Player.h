#pragma once
class Player
{
private:
	char* name;
	char* pass;
	unsigned age;

	
public:
	unsigned money;
	void change_name(const char* str);
	Player();
	Player(const char* name, const char* pass, unsigned age, unsigned money);
	~Player();
	Player(const Player& other);
	Player& operator=(const Player& rhs);

	bool enter_password();
	bool validate_age();
};

