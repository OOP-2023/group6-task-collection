#ifndef __CARPART_HPP
#define __CARPART_HPP

#include<fstream>

class CarPart
{
	char* _identifier = nullptr;
	char* _manufacturerName = nullptr;
	char* _description = nullptr;
	void copyFrom(const CarPart&);
	void free();

	friend std::ostream& operator<<(std::ostream& out, const CarPart& date);
	friend std::istream& operator>>(std::istream& in, CarPart& date);

public:
	CarPart();
	CarPart(const char*, const char*, const char*);
	CarPart(const CarPart&);
	CarPart& operator=(const CarPart&);

	~CarPart();
};

void copyDynamicCharArray(char*& destination, const char* source);
#endif

