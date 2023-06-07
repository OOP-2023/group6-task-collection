//
// Created by swordypepe on 5/20/23.
//

#include <cstring>
#include <iostream>
#include "TVGame.h"


TVGame::TVGame(const std::vector<Person>& _participants, Person *_hostOfTheGame, char **_events)
{
    participantsSize = _participants.size();
    for (int i = 0; i < participantsSize; ++i)
    {
        participants[i] = _participants[i];
    }
    hostOfTheGame = new Person(*_hostOfTheGame);
    events = new char*[MAX_ARR_SIZE];
    sizeOfEvents = sizeof(_events);
    for (int i = 0; i < sizeOfEvents; ++i)
    {
        events[i] = new char[MAX_ARR_SIZE];
        strcpy(events[i], _events[i]);
    }
}

TVGame::~TVGame()
{
    delete hostOfTheGame;
    for (int i = 0; i < sizeOfEvents; ++i)
    {
        delete events[i];
    }
    delete[] events;
}

void TVGame::showEvents(int limit)
{
    for (int i = 0; i < sizeOfEvents; ++i)
    {
        std::cout << events[i] << std::endl;
    }
    if (limit > sizeOfEvents)
    {
        std::cout << "No more events are present";
    }
}

void TVGame::printFormatInformation()
{
    hostOfTheGame->printInformation();
    for (int i = 0; i < participantsSize; ++i)
    {
        participants[i].printInformation();
    }
}
