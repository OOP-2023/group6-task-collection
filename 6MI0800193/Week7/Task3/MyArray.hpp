#ifndef _MY_ARRAY_HPP
#define _MY_ARRAY_HPP

#include <iostream>

template <typename T, size_t capacity>
class Array
{
public:


	const T& at(size_t idx) const;

	const T& operator[](size_t idx) const;

	const T& front() const;
	const T& back() const;

	void add(const T& type);

	bool empty();
	size_t get_count();
	size_t max_size();

	T* data();

	Array();

private:
	size_t cap;
	size_t count;
	T array[capacity];
};

template<typename T, size_t capacity>
const T& Array<T, capacity>::at(size_t idx) const
{
	if (!(idx < 0 || idx >= this->count))
		return this->array[idx];
}

template<typename T, size_t capacity>
const T& Array<T, capacity>::operator[](size_t idx) const
{
	if (!(idx < 0 || idx >= this->count))
		return this->array[idx];
}

template<typename T, size_t capacity>
inline const T& Array<T, capacity>::front() const
{
	return this->array[0];
}

template<typename T, size_t capacity>
inline const T& Array<T, capacity>::back() const
{
	return this->array[count - 1];
}

template<typename T, size_t capacity>
inline void Array<T, capacity>::add(const T& type)
{
	if (count < cap)
	{
		this->array[count] = type;
		count++;
	}
}

template<typename T, size_t capacity>
inline bool Array<T, capacity>::empty()
{
	return this->count == 0;
}

template<typename T, size_t capacity>
inline size_t Array<T, capacity>::get_count()
{
	return this->count;
}

template<typename T, size_t capacity>
inline size_t Array<T, capacity>::max_size()
{
	return this->cap;
}

template<typename T, size_t capacity>
T* Array<T, capacity>::data()
{
	return this->array;
}

template<typename T, size_t capacity>
inline Array<T, capacity>::Array()
{
	this->cap = capacity;
	this->count = 0;
}




#endif // !_MY_ARRAY_HPP
