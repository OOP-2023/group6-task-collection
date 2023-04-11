#include <iostream>

template <typename T>
const T& max(T* arr, size_t size){
    T maximal = arr[0];
    for(int i=0; i<size, ++i){
        if(arr[i]>maximal)
            maximal=arr[i];
    }
    return maximal;
}

int main(){

}
