#include<iostream>
using namespace std;

template<class T,size_t size>
class MyArr {
	T* arr;
	void free();
	void copy(const MyArr& arr);

public:
	MyArr();
	MyArr(const MyArr&);
	MyArr& operator=(const MyArr&);
	~MyArr();

	T& operator[](size_t index);
	const T& operator[](size_t index) const;
};

template<class T, size_t size>
void MyArr<T, size>::free()
{
	delete[] arr;
}

template<class T, size_t size>
void MyArr<T, size>::copy(const MyArr& _arr)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = _arr[i];
	}
}

template<class T, size_t size>
MyArr<T, size>::MyArr()
{
	arr = new T[size];
}

template<class T, size_t size>
MyArr<T, size>::MyArr(const MyArr& _arr)
{
	free();
	copy(_arr);
}

template<class T, size_t size>
MyArr<T,size>& MyArr<T, size>::operator=(const MyArr<T,size>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

template<class T, size_t size>
MyArr<T, size>::~MyArr()
{
	free();
}

template<class T, size_t size>
T& MyArr<T, size>::operator[](size_t index)
{
	return arr[index];
}

template<class T, size_t size>
const T& MyArr<T, size>::operator[](size_t index) const
{
	return arr[index];
}
