#include "problems.hpp"
void vector::resize() {
	int* newData = new int[this->capacity * 2];
	for (size_t i = 0; i < this->capacity; i++){
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}
void vector::copy(const vector& rhs) {
	for (size_t i = 0; i < rhs.size; i++){
		this->data[i] = rhs.data[i];
	}
}
void vector::free() {
	delete[] data;
}
vector::vector() {
	this->capacity = 8;
	this->size = 0;
	this->data = new int[capacity];
	

}
vector::vector(const vector& rhs) {
	this->capacity = rhs.capacity;
	this->size = rhs.size;
	int* data = new int[capacity];
	this->copy(rhs);
}
vector::vector(vector&& rhs) {
	this->capacity = rhs.capacity;
	this->size = rhs.size;
	this->data = rhs.data;
	rhs.capacity = 0;
	rhs.data = 0;
	rhs.data = nullptr;
}
vector::vector(int argCap) {
	this->capacity = argCap;
	this->size = 0;
	this->data = new int[capacity];
}
vector::vector(int argCap, int argDef) {
	this->capacity = argCap;
	this->size = argCap-1;//array is filled / no free spaces
	for (size_t i = 0; i < this->capacity; i++){
		this->data[i] = argDef;
	}
}
vector& vector::operator=(const vector& rhs) {
	if (this != &rhs) {
		this->capacity = rhs.capacity;
		this->size = rhs.size;
		this->data = new int[capacity];
		this->copy(rhs);
	}
	return*this;
}
int vector::operator[](size_t rhs) const {
	return this->data[rhs];//trqbva da ima proverka
}
int& vector::operator[](size_t rhs){
	return data[rhs];//same here
}
void vector::push_back(int rhs) {
	if (size == capacity) {
		this->resize();
	}
	this->data[++size] = rhs;
}

int vector::pop_back() {
	int temp= this->data[size];
	data[size--] = 0;
	return temp;
}


vector:: ~vector() {
	delete[] data;
}
int main() {

}
