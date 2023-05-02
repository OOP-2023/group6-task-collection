#ifndef TIRES_HPP
#define TIRES_HPP
#include"CarPart.h"
#include<fstream>
class Tires : public CarPart {
private:
	size_t _width;
	size_t _profile;
	size_t _diameterInInches;
public:
	friend std::ostream& operator<<(std::ostream&, const Tires&);

	Tires();
	Tires(const char*, const char*, const char*,const size_t, const size_t,const size_t);
}; 
#endif

