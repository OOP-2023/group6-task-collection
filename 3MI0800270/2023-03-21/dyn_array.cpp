#include <iostream>
#include "vector.h"

int main() {
    Vector vec = Vector();
    for (int i = 0;i < 3;i++) {
        for (int j = 2;j > 0;j--) {
            vec.push_back(i - j, i + j);
        }
    }
    for (int i = 0;i < vec.getSize();i++) {
        std::cout << vec[i].value << ',' << vec[i].rank << std::endl;
    }
    std::cout << vec.peak() << std::endl;
    std::cout << vec.getElementWithBiggestRank() << std::endl;
    std::cout << vec.peak() << std::endl;

}