#pragma once

class CarPart
{
	char* id;
	char* manufacturerName;
	char* description;

	void freeId();
	void freeManufacturerName();
	void freeDescription();

	void free();

public:
	CarPart(const char* = "", const char* = "", const char* = "");


	char* getId() const;
	void setId(const char*);

	char* getManufacturerName() const;
	void setManufacturerName(const char*);

	char* getDescription() const;
	void setDescription(const char*);
};