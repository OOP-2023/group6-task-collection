#pragma once

#include <iostream>

class CarPart {
private:
	char* id;
	char* description;
	char* manufacturerName;

	void copy(const CarPart& other);

	void copy(const char* source, char*& target);

	void free();

public:
	CarPart(const char* id, const char* manufacturerName, const char* description);

	CarPart(const CarPart& other);

	const CarPart& operator=(const CarPart& other);

	~CarPart();

	const char* getManufacturerName() const;

	const char* getDescription() const;

	const char* getId() const;
};
