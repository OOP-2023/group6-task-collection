// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct OrderedPair {
	int first;
	int second;
};

void inputPair(OrderedPair& p)
{
	cin >> p.first >> p.second;
}
bool compairPairs(const OrderedPair& p, const OrderedPair& p1)
{
	return (p.first > p1.first || ((p.first == p1.first) && (p.second > p1.second)));
}
void biggestPair(const OrderedPair* arr, int& maxFirst, int& maxSecond)
{
	maxFirst = arr[0].first;
	maxSecond = arr[0].second;
	for (size_t i = 1; i < 100; i++)
	{
		if (arr[i].first > maxFirst && arr[i].second > maxSecond)
		{
			maxFirst = arr[i].first;
			maxSecond = arr[i].second;
		}
	}
}
void swap(OrderedPair& first, OrderedPair& second)
{
	OrderedPair temp = first;
	first = second;
	second = first;
}
void bubbleSort(OrderedPair* arr, size_t size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j].first > arr[j + 1].first && (arr[j].second > arr[j + 1].second))
			{
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped)
			return;
	}
}
int main()
{
	int size;
	OrderedPair stArr[100];
	for (size_t i = 0; i < 100; i++)
	{
		cin >> stArr[i].first >> stArr[i].second;
	}
	cin >> size;
	OrderedPair* dynArr = new OrderedPair[size];
	delete[] dynArr;
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
