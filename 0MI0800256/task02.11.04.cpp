#pragma once
#ifndef VECTOR_HEADER
#define VECTOR_HEADER

class vector {
private:
	T* data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const vector&);
	void resize();
public:
	vector();
	vector(const vector&);

	vector& operator=(const vector&);

	size_t getSize() const;
	void push_back(int);

	int& operator[](size_t);
	const int operator[](size_t) const;

	~vector();
};

#endif

#include "Header1.h"
#include <exception>

void vector::free() {
	delete[] data;
}

void vector::copyFrom(const vector& other) {
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];

	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}

void vector::resize() {
	capacity = 2 * capacity;

	T* newMemory = new T[capacity];

	for (int i = 0; i < size; i++)
		newMemory[i] = data[i];

	delete[] data;
	data = newMemory;
}

vector::vector() {
	size = 0;
	capacity = 8;
	data = new T[capacity];
}

vector::vector(const vector& other) {
	copyFrom(other);
}

vector& vector::operator=(const vector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

size_t vector::getSize() const {
	return size;
}

void vector::push_back(T elem) {
	if (size == capacity)
		resize();

	data[size++] = elem;
}



T& vector::operator[](size_t index) {
	if (index >= size)
		throw std::exception("out of range");
	return data[index];
}

const T vector::operator[](size_t index) const {
	if (index >= size)
		throw std::exception("out of range");
	return data[index];
}

vector::~vector() {
	free();
}
