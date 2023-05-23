#ifndef EXAM2_COUPLEGAME_H
#define EXAM2_COUPLEGAME_H


#include "TVGame.h"

class CoupleGame : public TVGame
{
private:
    struct Pair
    {
        int firstPersonID;
        int secondPersonID;
    };
    Pair* pairs;
    const unsigned participantCapacity = 12;
    Pair findBanishedParticipants();

public:
    CoupleGame(const std::vector<Person> &participants, Person *hostOfTheGame, char **events);
    ~CoupleGame() override;
    void doEvent() override;
};


#endif //EXAM2_COUPLEGAME_H
