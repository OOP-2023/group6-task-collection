#include <iostream>

template <typename T, size_t size>
class MyArray{

    T* data;
public:
    MyArray(){
        data = new T[size];
    }
    ~MyArray(){
        delete [] data;
    }
    MyArray(MyArray const& other){
        data=new T[size];
        for(size_t idx=0; idx<size; idx++){
            data[idx] = other.data[idx];
        }
    }

    MyArray& operator=(MyArray const& other){
        if(this!=&other){
                for(size_t idx=0; idx<size; ++idx){
                    data[idx] = other.data[idx];
                }
        }
        return *this;
    }

    const T& operator[](const size_t& idx) const{
        return data[idx];
    }
    T& operator[](const size_t& idx){
        return data[idx];
    }
};

int main(){
    MyArray<int, 10> size_ten_array;
}
