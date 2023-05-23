#ifndef _EVENT_HPP
#define _EVENT_HPP
#include <iostream>
class Event
{
protected:
	size_t start;
	size_t end;

	virtual bool is_valid_time(size_t start, size_t end) const = 0;

public:
	virtual Event* clone() const = 0;
	virtual ~Event() = default;

	size_t get_start() const
	{
		return start;
	};

	size_t get_end() const
	{
		return end;
	};

	virtual bool is_happening_currently(size_t current_h, size_t current_m) const = 0;

	void print() const
	{
		std::cout << start / 60 << ":" << start % 60 << " - " <<
			end / 60 << ":" << end % 60 << std::endl;
	};
};

#endif