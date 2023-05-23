#ifndef _SIMPLE_EVENT
#define _SIMPLE_EVENT
#include "Event.hpp"

class SimpleEvent : public Event
{
private:
public:
	SimpleEvent(size_t hours, size_t minutes, size_t, size_t);

	bool is_valid_time(size_t start, size_t end) const override;

	Event* clone() const override;
	~SimpleEvent() = default;

	bool is_happening_currently(size_t current_h, size_t current_m) const override;
};

#endif // !_SIMPLE_EVENT
