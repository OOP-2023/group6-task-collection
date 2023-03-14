using namespace std;
#include <assert.h>
#include <iostream>

const int MAX_SIZE = 100;

struct Pair {
	int first;
	int second;
};

Pair readPair() {
	int first, second;
	cin >> first >> second;
	return Pair{ first, second };
}

bool comparePairs(const Pair& pair1, const Pair& pair2) {
	return (pair1.first > pair2.first || pair1.first == pair2.first && pair1.second > pair2.second);
}

Pair maxPair(const Pair* pairs[MAX_SIZE]) {
	Pair maxPair = *pairs[0];
	for (size_t i = 1; i < MAX_SIZE; i++)
	{
		if (comparePairs(*pairs[i], maxPair))
			maxPair = *pairs[i];
	}
	return maxPair;
}

void swapPairs(Pair& pair1, Pair& pair2) {
	int temp = pair1.first;
	pair1.first = pair2.first;
	pair2.first = temp;

	temp = pair1.second;
	pair1.second = pair2.second;
	pair2.second = temp;
}

void sortPairsArrDESC(Pair* pairs, size_t length) {
	size_t maxIndex;
	for (size_t i = 0; i < length - 1; i++)
	{
		maxIndex = i;
		for (size_t j = 0; j < length; j++)
		{
			if (comparePairs(pairs[j], pairs[maxIndex]))
				maxIndex = j;
		}
		if (i != maxIndex)
			swapPairs(pairs[i], pairs[maxIndex]);
	}
}

int main()
{


}
