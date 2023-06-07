#define _CRT_SECURE_NO_WARNINGS
#include "CarPart.hpp"

CarPart::CarPart()
{
	this->id = new char[1];
	id[0] = '\0';

	this->desc = new char[1];
	desc[0] = '\0';

	this->manufact_name = new char[1];
	manufact_name[0] = '\0';
}

CarPart::~CarPart()
{
	cleanup();
}

CarPart::CarPart(const char* id, const char* man_name, const char* desc)
{
	set_str(id, this->id);
	set_str(man_name, this->manufact_name);
	set_str(desc, this->desc);
}

CarPart::CarPart(const CarPart& ref)
{
	set_str(ref.id, this->id);
	set_str(ref.manufact_name, this->manufact_name);
	set_str(ref.desc, this->desc);
}

CarPart& CarPart::operator=(const CarPart& rhs)
{
	if (this != &rhs)
	{
		cleanup();
		set_str(rhs.id, this->id);
		set_str(rhs.manufact_name, this->manufact_name);
		set_str(rhs.desc, this->desc);
	}
	return *this;
}

const char* CarPart::get_id() const
{
	return this->id;
}

const char* CarPart::get_manufact_name() const
{
	return this->manufact_name;
}

const char* CarPart::get_desc() const
{
	return this->desc;
}

void CarPart::set_id(const char* id)
{
	delete[] this->id;
	set_str(id, this->id);
}

void CarPart::set_manufact(const char* manufact_name)
{
	delete[] this->manufact_name;
	set_str(manufact_name, this->manufact_name);
}

void CarPart::set_desc(const char* desc)
{
	delete[] this->desc;
	set_str(desc, this->desc);
}

std::ostream& operator<<(std::ostream& out, const CarPart& part)
{
	out << '(' << part.get_id() << ')' << " by " << part.get_manufact_name() <<
		" - " << part.get_desc();
	return out;
}

void CarPart::set_str(const char* from, char*& to)
{
	to = new char[strlen(from) + 1];
	strcpy(to, from);
}

void CarPart::cleanup()
{
	delete[] desc;
	delete[] manufact_name;
	delete[] id;
}