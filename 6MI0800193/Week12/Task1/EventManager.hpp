#ifndef _EVENT_MANAGER
#define _EVENT_MANAGER
#include "Event.hpp"
#include <vector>
using namespace std;
class EventManager
{
private:
	vector<Event*> events;
	size_t capacity;
	size_t count;

	void free();
	void copy(const vector<Event*>& other, size_t count);

	void sort_events_by_end();

public:
	EventManager(size_t cap);
	EventManager(const EventManager& other);
	EventManager& operator=(const EventManager& other);
	~EventManager();

	bool add_event(Event& event);
	bool add_event(Event*& event);
	bool add_event(Event*&& event);
	int get_max_attendable();
	size_t ongoin_events(size_t current_h, size_t current_m) const;

};

#endif // !_EVENT_MANAGER
