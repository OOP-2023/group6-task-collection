#include <iostream>
#include "Engine.h"


unsigned Engine::getHorsePowers() const
{
	return horsePowers;
}
void Engine::setHorsePowers(unsigned inputHorsePowers)
{
	horsePowers = inputHorsePowers;
}

Engine::Engine(unsigned inputHorsePowers)
{
	setHorsePowers(inputHorsePowers);
}