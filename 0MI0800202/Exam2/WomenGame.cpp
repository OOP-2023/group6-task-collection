//
// Created by swordypepe on 5/20/23.
//

#include <cstring>
#include "WomenGame.h"
#include "iostream"

WomenGame::WomenGame(const std::vector<Person> &participants, Person *hostOfTheGame, char **events, char** _goals)
: TVGame(participants, hostOfTheGame, events)
{
    if (participantsSize != participantCapacity)
    {
        throw std::runtime_error("Wrong count of participants given");
    }
    goals = new char*[goalCapacity];
    for (int i = 0; i < goalCapacity; ++i)
    {
        strcpy(goals[i], _goals[i]);
    }
}

void WomenGame::doEvent()
{
    Person* chosenPerson = findBanishedParticipant();
    char nextEvent[30] = "Task was ";
    strcat(nextEvent, goals[currentGoal]);
    strcat(nextEvent, chosenPerson->nameGetter());
    events[sizeOfEvents++] = nextEvent;
    currentGoal++;
}

Person *WomenGame::findBanishedParticipant()
{
    Person* chosenPerson = &participants[0];
    for (int i = 1; i < participantsSize; ++i)
    {
        if (participants[i].coefficientGetter() < chosenPerson->coefficientGetter())
        {
            chosenPerson = &participants[i];
        }
    }
    return chosenPerson;
}

