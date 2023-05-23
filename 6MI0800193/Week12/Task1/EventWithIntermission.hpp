#ifndef _EVENT_WITH_INTERMISSION
#define _EVENT_WITH_INTERMISSION
#include "Event.hpp"
class EventWithIntermission : public Event
{
private:
	size_t pause_start;
	size_t pause_end;

public:
	EventWithIntermission(size_t hours_s, size_t minutes_s,
		size_t hours_e, size_t minutes_e, 
		size_t pause_start_h, size_t pause_start_m,
		size_t pause_end_h, size_t pause_end_m);

	bool is_valid_time(size_t start, size_t end) const override;

	Event* clone() const override;
	~EventWithIntermission() = default;

	bool is_happening_currently(size_t current_h, size_t current_m) const override;
};
#endif // !_EVENT_WITH_INTERMISSION
