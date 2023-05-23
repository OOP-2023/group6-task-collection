#ifndef _EVENT_FIXED_INTER
#define _EVENT_FIXED_INTER
#include "Event.hpp"
class EventWithFixedIntermission : public Event
{
private:
	size_t pause_start;
public:
	EventWithFixedIntermission(size_t hours_s, size_t minutes_s,
		size_t hours_e, size_t minutes_e, size_t pause_h, size_t pause_m);

	bool is_valid_time(size_t start, size_t end) const override;

	Event* clone() const override;
	~EventWithFixedIntermission() = default;

	bool is_happening_currently(size_t current_h, size_t current_m) const override;
};

#endif // !_EVENT_FIXED_INTER
