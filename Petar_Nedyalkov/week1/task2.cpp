#include <iostream>

struct OrderPair
{
	int first;
	int second;
	void readPair()
	{
		std::cin >> first >> second;
	}

	void printPair()
	{
		std::cout << first <<" "<< second << std::endl;
	}
};

int comparePairs(const OrderPair a, const OrderPair b)
{
	if (a.first > b.first || a.first == b.first && a.second > b.second) return -1; //firstpair is bigger
	else if (a.first < b.first || a.first == b.first && a.second < b.second) return 1; //secondpair is bigger
	else return 0; //equal 
}

OrderPair findBiggestPair(const OrderPair* arr, size_t size)
{
	OrderPair maxPair = arr[0];
	for (size_t i = 1; i < size; i++)
		if (comparePairs(arr[i], maxPair) == -1) maxPair = arr[i];

	return maxPair;
}

void sortPairs(OrderPair* arr, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		OrderPair minPair = arr[i];
		int minIndex = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (comparePairs(minPair, arr[j]) == -1)
			{
				minPair = arr[j];
				minIndex = j;
			}
		}

		std::swap(arr[minIndex], arr[i]);
		std::swap(arr[i], minPair);
	}

}
int main()
{
	OrderPair arr[100];
	OrderPair* arrPtr = new OrderPair();
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		arr[i].readPair();
	}

	std::cout<<comparePairs(arr[0], arr[1])<<std::endl;
	std::cout<<comparePairs(arr[1], arr[0])<<std::endl;
	std::cout<<comparePairs(arr[1], arr[2])<<std::endl;
	std::cout << std::endl;

	findBiggestPair(arr, n).printPair();
	std::cout << std::endl;

	sortPairs(arr, n);

	for (int i = 0; i < n; i++)
	{
		arr[i].printPair();
	}
}