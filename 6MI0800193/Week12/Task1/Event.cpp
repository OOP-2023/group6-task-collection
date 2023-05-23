#include "Event.hpp"

bool Event::is_happening_currently(size_t current_h, size_t current_m) const
{
	size_t current_time = current_h * 60 + current_m;
	return current_time >= start && current_time <= end;
}
