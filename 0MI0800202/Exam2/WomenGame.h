#ifndef EXAM2_WOMENGAME_H
#define EXAM2_WOMENGAME_H


#include <vector>
#include "TVGame.h"

class WomenGame : public TVGame
{
private:
    const unsigned participantCapacity = 11;
    const unsigned goalCapacity = 12;
    unsigned currentGoal = 0;
    char** goals;
    Person* findBanishedParticipant();
public:
    WomenGame(const std::vector<Person> &participants, Person *hostOfTheGame, char **events, char** goals);
    void doEvent() override;
};


#endif
