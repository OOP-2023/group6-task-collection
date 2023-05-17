#include <iostream>

template<class T>
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

	T& operator[](size_t);
	const T operator[](size_t) const;

	~vector();
};

#endif

template<class T>
inline void vector<T>::free()
{
	delete[] data;
}

template<class T>
inline void vector<T>::copyFrom(const vector& vec)
{
	size = vec.size;
	capacity = vec.capacity;
	data = new T * [capacity];
	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}

template<class T>
inline void vector<T>::resize()
{
	capacity = 2 * capacity;

	T* newMemory = new T[capacity];

	for (size_t i = 0; i < size; i++)
		newMemory[i] = data[i];
	delete[] data;
	data = newMemory;
}

template<class T>
inline vector<T>::vector()
{
	size = 0;
	capacity = 8;
	data = new T[capacity];
}

template<class T>
inline vector<T>::vector(const vector& other) {
	copyFrom(other);
}

template<class T>
inline vector<T>& vector<T>::operator=(const vector<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
inline size_t vector<T>::getSize() const {
	return size;
}

template<class T>
inline void vector<T>::push_back(int elem) {
	if (size == capacity)
		resize();

	data[size++] = elem;
}

template<class T>
T& vector<T>::operator[](size_t index) {
	if (index >= size)
		throw std::exception("out of range");
	return data[index];
}

template<class T>
const T vector<T>::operator[](size_t index) const {
	if (index >= size)
		throw std::exception("out of range");
	return data[index];
}

template<class T >
inline vector<T>::~vector() {
	free();
}
