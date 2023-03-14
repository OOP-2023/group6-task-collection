// Practicum_OOP_28.02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int const  SIZEOFARRAY = 100;

namespace PairOfNumbers
{
    struct PairOfNumber
    {
        int first;
        int second;

        void read(std::istream &in);

        void write(std::ostream& out)
        {
            out << first << " " << second;
        }

        //(a, b) > (c, d) <=> (a > c) || ( (a == c) && (b > d) )  
        int compare(PairOfNumber const& other) const {
            // return 0 if this is 'equal' to other
            // return -1 if this is 'less than' other
            // return 1 if this is 'greater than' other

            if (this->first == other.first && this->second == other.second)
                return 0;
            if ((this->first > other.first) || ((this->first == other.first)
                && (this->second > other.second)))
                return 1;
            else
                return -1;
        }


    };

    void PairOfNumber::read(std::istream& in) {
        in >> this->first;
        in >> this->second;
    }
}
 
void ReadArrayOfPairOfNumber(PairOfNumbers::PairOfNumber* ArrayOfPairOfNumber,size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        ArrayOfPairOfNumber[i].read(std::cin);
    }
}

void SortOfArray(PairOfNumbers::PairOfNumber* ArrayOfPairOfNumber, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i; j < size; j++)
        {
            if (ArrayOfPairOfNumber[j].compare(ArrayOfPairOfNumber[minIndex]))
                minIndex = j;
        }

        if (minIndex != i)
        {
            std::swap(ArrayOfPairOfNumber[i], ArrayOfPairOfNumber[minIndex]);
        }
    }

}


int main()
{
    PairOfNumbers::PairOfNumber x,y;

    x.read(std::cin);

    x.compare(y); // PairOfNumbers::PairOfNumber::compare(x, y);
    y.compare(x); // PairOfNumbers::PairOfNumber::compare(y, x);

    PairOfNumbers::PairOfNumber ArrayOfPairOfNumber[SIZEOFARRAY] = {0};
    ReadArrayOfPairOfNumber(ArrayOfPairOfNumber,SIZEOFARRAY);
    SortOfArray(ArrayOfPairOfNumber, SIZEOFARRAY);
    std::cout << "The Biggest element of the Array is: ";
    ArrayOfPairOfNumber[SIZEOFARRAY - 1].write(std::cout);

    int number;
    std::cin >> number;
    PairOfNumbers::PairOfNumber* DynamicArrayOfPairOfNumber = new  PairOfNumbers::PairOfNumber[number];
    ReadArrayOfPairOfNumber(DynamicArrayOfPairOfNumber,number);
    SortOfArray(DynamicArrayOfPairOfNumber, number);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
