template<class T, size_t size>
class MyArray {
	T* arr;

public:
	MyArray() {
		arr = new T[size];
	}
	MyArray(const T& other) {
		for (int i = 0; i < size; ++i)
			other[i] == arr[i];
	}
	~MyArray() {
		delete[] arr;
	}

	const T& operator[](const size_t& idx) const {
		return arr[idx];
	}

	T& operator[](const size_t& idx) {
		return arr[idx];
	}

	T& operator=(const T& other) {
		if (this != &other)
		{
			delete[] arr;
			for (int i = 0; i < size; ++i)
				other[i] == arr[i];
        }
		return *this;
	}
};


int main()
{

	MyArray<int, 10> x;
	x[0] = 12;
	cout << x[0] << endl;
	MyArray<int, 20> y;
	MyArray<int, 30> z;
   
}
