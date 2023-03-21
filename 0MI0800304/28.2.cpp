#include <iostream>
struct OrderedPair{
    int first{ 0 };
    int second{ 0 };
    void readOrderedPair() {
        std::cin >> first;
        std::cin >> second;
    }
    OrderedPair compare(OrderedPair& x2) const {
        if (this->first == x2.first) {
            if (x1.second > x2.second) return x1;
            else return x2;
        }
        else if (x1.first > x2.first) return x1;
        else return x2;
    }
    OrderedPair findBiggest(OrderedPair arr[100]) {
        OrderedPair max = arr[0];
        for (size_t i = 1; i < 100; i++)
            max = compare(max, arr[i]);
        return max;
        
    }
    void sortOrderedPairs(OrderedPair arr[],size_t size) {
        for (size_t i = 0; i < size-1; i++){
            for (size_t j = 0; j < size-1-i; j++) {
                if (arr[j].first == arr[j + 1].first) {
                    if (arr[j].second > arr[j + 1].second) swap(arr[j], arr[j + 1]);

                }
                else if (arr[j].first > arr[j + 1].first)swap(arr[j], arr[j + 1]);
                
            }
        }
    }
    void swap(OrderedPair& x1, OrderedPair& x2) {
        OrderedPair temp = x1;
        x1 = x2;
        x2 = temp;
    }
};

int main(){
    OrderedPair x, y;

    x.compare(y); // compare(x, y); this == &x
    y.compare(x); // compare(y,x); this == &y
   

}

//void readOrderedPair(std::istream& in) {
//    in >> first;
//    in >> second;
//}
//x.readOrderedPair(std::cin);