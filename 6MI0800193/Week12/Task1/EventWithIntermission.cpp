#include "EventWithIntermission.hpp"

EventWithIntermission::EventWithIntermission(size_t hours_s, size_t minutes_s, size_t hours_e, size_t minutes_e, size_t pause_start_h, size_t pause_start_m, size_t pause_end_h, size_t pause_end_m)
{
	start = hours_s * 60 + minutes_s;
	end = hours_e * 60 + minutes_e;
	pause_start = pause_start_h * 60 + pause_end_m;
	pause_end = pause_end_h * 60 + pause_end_m;
	if (!is_valid_time(start, end))
	{
		this->start = 0;
		this->end = 60;
	}

}

bool EventWithIntermission::is_valid_time(size_t start, size_t end) const
{
	size_t length = end - start - (pause_end - pause_start);
	return length > 0 && length <= 360;
}

Event* EventWithIntermission::clone() const
{
	return new EventWithIntermission(*this);
}

bool EventWithIntermission::is_happening_currently(size_t current_h, size_t current_m) const
{
	size_t current_time = current_h * 60 + current_m;
	return Event::is_happening_currently(current_h, current_m) &&
		!(current_time > pause_start &&
		current_time < pause_end);
}
