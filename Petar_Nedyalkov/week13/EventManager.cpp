#include <iostream>
#include "Events.h"

void EventManager::free() {
	for (size_t i = 0; i < index; i++)
		delete data[i];

	delete[] data;
}

void EventManager::copy(const EventManager& other) {
	
	capacity = other.capacity;
	index = other.index;
	data = new Events * [capacity]{nullptr};

	for (size_t i = 0; i < index; i++)
		data[i] = other.data[i]->clone();
}

EventManager::EventManager(size_t cap)
{
	capacity = cap;
	index = 0;
	data = new Events * [capacity]{nullptr};
}

EventManager::~EventManager() {
	free();
}

EventManager::EventManager(const EventManager& other) {
	copy(other);
}

EventManager& EventManager::operator=(const EventManager& other) {
	
	if (this != &other)	{

		free();
		copy(other);
	}
	return *this;
}

bool EventManager::addEvent(Events* current) {

	if (index == capacity)
		return false;
	data[index++] = current->clone();
}

bool EventManager::isBusy(unsigned hour, unsigned mins) const{
	for (size_t i = 0; i < index; i++)
		if (data[i]->isActiveInCertainTime(hour, mins)) return false;

	return true;
}

size_t EventManager::onGoingEvents(unsigned hour, unsigned mins) const {

	size_t count = 0;
	
	for (size_t i = 0; i < index; i++)
		if (data[i]->isActiveInCertainTime(hour, mins)) count++;

	return count;
}

