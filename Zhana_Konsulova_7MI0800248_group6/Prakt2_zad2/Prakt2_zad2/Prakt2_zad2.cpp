// Prakt2_zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


struct Pair
{
    int first, second;
    void Read()
    {
        std::cin >> first >> second;
    }
    void Print() const
    {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

bool IsFirstPairBigger(const Pair& p1,const Pair& p2)
{
    return
        p1.first > p2.first ||
        (p1.first == p2.first && p1.second > p2.second);
}

Pair TheBiggest(Pair arr[100])
{
    Pair theBiggest = arr[0];
    for (int i = 1; i < 100; i++)
    {
        if (IsFirstPairBigger(arr[i], theBiggest))
            theBiggest = arr[i];
    }
    return theBiggest;
}



void Swap(Pair& p1, Pair& p2)
{
    Pair temp = p1;
    p1 = p2;
    p2 = temp;
}
void SortTheArrOfPairs(Pair * arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (IsFirstPairBigger(arr[j], arr[j + 1]))
            {
                Swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped)
            return;
    }
    
}

void Print(Pair* arr, size_t size)
{
    for (int i = 0; i < size; i++)
        std::cout << "(" << arr[0].first << ", " << arr[1].second << ")" << std::endl;
}

int main()
{
    /*
    Pair pair1;
    pair1.Read();
    std::cout << pair1.first << ", " << pair1.second;

    Pair p1 = { 1,3 };
    Pair p2 = { 1, 4};
    std::cout << "is the first bigger: " << IsFirstPairBigger(p1, p2) << std::endl;
    */

    Pair arr[100] = { {1,2}, {1,4}, {3,5}, {4,7}, {6,9}, {2,3}, {4,5} };
    Pair theBiggest = TheBiggest(arr);
    theBiggest.Print();


}

