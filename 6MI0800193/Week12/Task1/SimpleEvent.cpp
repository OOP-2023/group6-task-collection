#include "SimpleEvent.hpp"

SimpleEvent::SimpleEvent(size_t hours_start, size_t minutes_start, size_t hours_end, size_t minutes_end) 
	
{
	start = hours_start * 60 + minutes_start;
	end = hours_end * 60 + minutes_end;
	if (!is_valid_time(start, end))
	{
		this->start = 0;
		this->end = 60;
	}
}

bool SimpleEvent::is_valid_time(size_t start, size_t end) const 
{
	return end - start > 0 && end - start <= 120;
}

Event* SimpleEvent::clone() const
{
	return new SimpleEvent(*this);
}

bool SimpleEvent::is_happening_currently(size_t current_h, size_t current_m) const
{
	return Event::is_happening_currently(current_h, current_m);
}
