#include "EventManager.hpp"
#include <algorithm>
#include <iostream>
void EventManager::free()
{
	for (size_t i = 0; i < count; i++)
	{
		delete events[i];
	}
	events.clear();
} 

void EventManager::copy(const vector<Event*>& other, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		events.push_back(other[i]->clone());
	}
}

EventManager::EventManager(size_t cap)
{
	capacity = cap;
	count = 0;
}

EventManager::EventManager(const EventManager& other)
{
	capacity = other.capacity;
	count = other.count;
	copy(other.events, other.count);
}

EventManager& EventManager::operator=(const EventManager& other)
{
	if (this != &other)
	{
		free();
		capacity = other.capacity;
		count = other.count;
		copy(other.events, other.count);
	}
	return *this;
}

EventManager::~EventManager()
{
	free();
}

bool EventManager::add_event(Event& event)
{
	if (count >= capacity)
		return false;

	events.push_back(event.clone());
	count++;

	return true;
}

bool EventManager::add_event(Event*& event)
{
	if (count >= capacity)
		return false;

	events.push_back(event);
	count++;

	return true;
}

bool EventManager::add_event(Event*&& event)
{
	if (count >= capacity)
		return false;

	events.push_back(event);
	count++;

	return true;
}

size_t EventManager::ongoin_events(size_t current_h, size_t current_m) const
{
	size_t active_events = 0;
	for (size_t i = 0; i < count; i++)
	{
		if (events[i]->is_happening_currently(current_h, current_m))
			active_events++;
	}
	return active_events;
}

bool compare(const Event* ev1, const Event* ev2)
{
	return ev1->get_end() < ev2->get_end();
}

void EventManager::sort_events_by_end()
{
	std::sort(events.begin(), events.end(), compare);
}

int EventManager::get_max_attendable()
{
	sort_events_by_end();

	size_t max_attendable = 1;
	size_t current_end = events[0]->get_end();

	for (size_t i = 1; i < events.size(); i++)
	{
		if (events[i]->get_start() > current_end)
		{
			max_attendable++;
			current_end = events[i]->get_end();
		}
	}
	return max_attendable;
}