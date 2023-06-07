#pragma once

class Engine
{
	unsigned horsePowers;

public:
	Engine(unsigned inputHorsePowers);

	unsigned getHorsePowers() const;
	void setHorsePowers(unsigned inputHorsePowers);
};