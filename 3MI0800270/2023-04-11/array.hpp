template<typename T, unsigned size>
class array
{
private:
    T arr[size];
public:
    array();
    array& operator=(const T* arr);
    const T& operator[](unsigned pos) const;
    T& operator[](unsigned pos);
};

template<typename T, unsigned size>
array<T, size>::array() {}

template<typename T, unsigned size>
const T& array<T, size>::operator[](unsigned pos) const {
    return arr[pos];
}

template<typename T, unsigned size>
T& array<T, size>::operator[](unsigned pos) {
    return arr[pos];
}

