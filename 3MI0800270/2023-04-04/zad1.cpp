#include <cstring>
class Player {
    char* name;
    char* password;
    unsigned age;
    unsigned balance;
public:
    Player(const char* name, const char* password, unsigned age, unsigned balance);
    Player(const Player&);
    Player(Player&&);
    ~Player();

    void setName(const char*);
    bool isPasswordCorrect(const char*);
};

Player::Player(const char* name, const char* password, unsigned age, unsigned balance) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->password = new char[strlen(password)];
    strcpy(this->password, password);
    this->age = age;
    this->balance = balance;
}
Player::Player(const Player& other): Player(other.name, other.password, other.age, other.balance) {}
Player::Player(Player&& other) {
    this->name = other.name;
    this->password = other.password;
    this->age = other.age;
    this->balance = other.balance;
}