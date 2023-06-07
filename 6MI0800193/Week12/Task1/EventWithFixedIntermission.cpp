#include "EventWithFixedIntermission.hpp"

EventWithFixedIntermission::EventWithFixedIntermission(size_t hours_s, size_t minutes_s, size_t hours_e, size_t minutes_e, size_t pause_h, size_t pause_m)
{
	start = hours_s * 60 + minutes_s;
	end = hours_e * 60 + minutes_e;
	pause_start = pause_h * 60 + pause_m;
	if (!is_valid_time(start, end))
	{
		this->start = 0;
		this->end = 60;
	}

}

bool EventWithFixedIntermission::is_valid_time(size_t start, size_t end) const
{
	size_t time = end - start;
	return time - 20 > 0 && time - 20 <= 240;
}

Event* EventWithFixedIntermission::clone() const
{
	return new EventWithFixedIntermission(*this);
}

bool EventWithFixedIntermission::is_happening_currently(size_t current_h, size_t current_m) const
{
	size_t current = current_h * 60 + current_m;
	return Event::is_happening_currently(current_h, current_m) &&
		(current < pause_start || current > pause_start + 20);
}
