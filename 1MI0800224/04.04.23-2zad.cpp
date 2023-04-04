#include <iostream>
#include <cstdlib>

class Player{
    char* name;
    char* password;
    unsigned age;
    double money;
};

class Game{
private:
    int r=(int)rand()%100+1;
    int suggestion;
public:
    Game(int random, const int suggest);
};

Game::Game(int random, const int suggest){
    this->r=random;
    this->suggestion=suggest;
}

int main(){

}
