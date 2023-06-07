#ifndef EXAM2_TVGAME_H
#define EXAM2_TVGAME_H


#include <vector>
#include "Person.h"

class TVGame
{
private:
    const size_t MAX_ARR_SIZE = 200;
protected:
    unsigned sizeOfEvents;
    unsigned participantsSize;
    std::vector<Person> participants;
    Person* hostOfTheGame;
    char** events;
public:
    TVGame(const std::vector<Person>& participants, Person* hostOfTheGame, char** events);
    virtual ~TVGame();
    void showEvents(int limit);
    void printFormatInformation();
    virtual void doEvent() = 0;


};


#endif //EXAM2_TVGAME_H
