#ifndef CAR_PARTS_
#define CAR_PARTS_
#include "Tyres.h"
#include "engine.h"
#include "accumulator.h"

class carParts
{
	char* name;
	char* description;
	char* id;

	void copy(const carParts& current);

	friend std::ofstream& operator<<(std::ostream& ofs, const carParts& current);
public:
	carParts();
	carParts(const carParts& current);
	carParts& operator=(const carParts& other);
};

#endif

