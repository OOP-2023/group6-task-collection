#include <iostream>
using namespace std;

struct OrderedPair
{
	int first, second;
	/*void read();
	void print();*/
};
//void OrderedPair::read()
//{
//	cout << "Enter natural numbers for ordered pair >";
//	cin >> first >> second;
//}
//void OrderedPair::print() 
//{
//	cout << first << " " << second << endl;
//}

void readOrderedPair(OrderedPair& pair)
{
	cout << "Enter natural numbers for ordered pair >";
	cin >> pair.first >> pair.second;
}

void printOrderedPair(const OrderedPair& pair)
{
	cout << pair.first << " " << pair.second << endl;
}

int compareOrderedPairs(const OrderedPair& pair1, const OrderedPair& pair2)
{
	if (pair1.first > pair2.first || (pair1.first == pair2.first && pair1.second > pair2.second))
		return 1;
	else if (pair1.first == pair2.first && pair1.second == pair2.second)
		return 0;
	else
		return -1;
}

OrderedPair findMaxOrderedPair(const OrderedPair array[100])
{
	OrderedPair max = array[0];

	for (int i = 0; i < 9; i++)
	{
		max = (compareOrderedPairs(array[i], array[i + 1]) == 1) ? max : array[i+1];
	}

	return max;
}

void sortOrderedPairArrayInsideFor(OrderedPair* dynamicArray, int size, int i, bool& swapped)
{
	for (int j = 0; j < size - 1 - i; j++)
	{
		if (compareOrderedPairs(dynamicArray[j], dynamicArray[j + 1]) == 1)
		{
			swap(dynamicArray[j], dynamicArray[j + 1]);
			swapped = true;
		}
	}
}


void sortOrderedPairArray(OrderedPair*& dynamicArray, int size)
{
	bool swapped = true;

	for (int i = 0; i < size - 1 && swapped; i++)
	{
		swapped = false;

		sortOrderedPairArrayInsideFor(dynamicArray, size, i, swapped);
	}
}

int main()
{
	OrderedPair firstPair;
	readOrderedPair(firstPair);
	printOrderedPair(firstPair);

	OrderedPair staticArray[10] = { {1,3} , {2,3} , {0,4} , {5,1} , {2,2} , {3,0} , {-1,2} , {10,12} ,{0,0}, {100,100} };
	OrderedPair max = findMaxOrderedPair(staticArray);
	cout << "------------------ max ordered pair ->" << max.first << "," << max.second << endl;

	OrderedPair* dynamicArray = new OrderedPair[100];
	for (size_t i = 0; i < 10; i++)
	{
		dynamicArray[i] = staticArray[i];
	}

	sortOrderedPairArray(dynamicArray, 10);
	cout << "dynamicArray:" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		printOrderedPair(dynamicArray[i]);
	}

	delete[] dynamicArray;
	return 0;
}