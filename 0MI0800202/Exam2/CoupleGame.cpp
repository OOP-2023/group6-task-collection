//
// Created by swordypepe on 5/20/23.
//

#include "CoupleGame.h"
#include <iostream>
#include <cstring>

CoupleGame::CoupleGame(const std::vector<Person> &participants, Person *hostOfTheGame, char **events) : TVGame(
        participants, hostOfTheGame, events)
{
    if (participants[participantCapacity].idGetter() != participantCapacity)
    {
        throw std::runtime_error("invalid person in array present");
    }
    pairs = new Pair[participantCapacity / 2];
    int counter = 0;
    for (int i = 0; i < participantCapacity; i += 2)
    {
        pairs[counter].firstPersonID = participants[i].idGetter();
        pairs[counter].secondPersonID = participants[i + 1].idGetter();
        counter++;
    }

}

CoupleGame::~CoupleGame()
{
    delete[] pairs;
}

void CoupleGame::doEvent()
{
    Pair chosenPair = findBanishedParticipants();
    char nextEvent[30] = "";
    strcat(nextEvent, participants[chosenPair.firstPersonID].nameGetter());
    strcat(nextEvent, "and");
    strcat(nextEvent, participants[chosenPair.secondPersonID].nameGetter());
    strcat(nextEvent, "were eliminated");
    events[sizeOfEvents++] = nextEvent;
}

CoupleGame::Pair CoupleGame::findBanishedParticipants()
{
    Pair chosenPair = pairs[0];
    for (int i = 2; i < participantsSize; i += 2)
    {
        if (participants[i].coefficientGetter() + participants[i + 1].coefficientGetter() < participants[chosenPair.firstPersonID].idGetter() + participants[chosenPair.firstPersonID].idGetter() )
        {
            chosenPair.firstPersonID = i;
            chosenPair.secondPersonID = i + 1;
        }

    }
}

