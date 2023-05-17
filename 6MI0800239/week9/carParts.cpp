#include "carParts.h"
#include<iostream>
#include<fstream>
#include<cstring>

void copy(const carParts& current)
{
	strcpy(name,current.name);
}

std::ofstream& operator<<(std::ostream& ofs, const Engine& current)
{
	
}
