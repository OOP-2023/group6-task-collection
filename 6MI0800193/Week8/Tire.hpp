#ifndef _TIRE_HPP
#define _TIRE_HPP
#include "CarPart.hpp"
class Tire : public CarPart
{
private:
	int width; // [155, 365]
	int profile; // [30, 80]
	int diameter; // [13, 21]

	bool validate(int value, int min, int max);

public:
	Tire();
	Tire(int w, int p, int d, const char* id, const char* man_name, const char* desc);

	int get_width() const;
	int get_profile() const;
	int get_diameter() const;

	void set_width(int w);
	void set_profile(int p);
	void set_diameter(int d);

	friend std::ostream& operator<< (std::ostream& out, const Tire& tire);
};

#endif // !_TIRE_HPP
