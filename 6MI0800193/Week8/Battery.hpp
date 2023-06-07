#ifndef _BATTERY_HPP
#define _BATTERY_HPP
#include "CarPart.hpp"
class Battery : public CarPart
{
private:
	int capacity;
	char* battery_id;
public:
	Battery();
	Battery(int cap, const char* batt_id, const char* id, const char* man_name, const char* desc);
	~Battery();
	Battery(const Battery& bat);
	Battery& operator= (const Battery& rhs);

	void set_capacity(int cap);
	void set_battery_id(const char* battery_id);

	int get_capacity() const;
	const char* get_battery_id() const;

	friend std::ostream& operator<<(std::ostream& out, const Battery& bat);

};

#endif // !_BATTERY_HPP
