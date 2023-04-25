#ifndef _CAR_PART_HPP
#define _CAR_PART_HPP
#include <fstream>
#include <iostream>
#include <cstring>
class CarPart
{
private:
	char* id;
	char* manufact_name;
	char* desc;

	void set_str(const char* from, char*& to);
	void cleanup();

public:
	CarPart();
	~CarPart();
	CarPart(const char* id, const char* man_name, const char* desc);
	CarPart(const CarPart& ref);
	CarPart& operator=(const CarPart& rhs);

	const char* get_id() const;
	const char* get_manufact_name() const;
	const char* get_desc() const;

	void set_id(const char* id);
	void set_manufact(const char* manufact_name);
	void set_desc(const char* desc);

	friend std::ostream& operator<<(std::ostream& out, const CarPart& part);
};

#endif // !_CAR_PART_HPP
