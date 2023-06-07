#include <iostream>
using namespace std;


struct orderedPair {
	int first;
	int second;
};

void print(const orderedPair& arg) {
		cout << arg.first << " " << arg.second;
};

orderedPair compare(const orderedPair& arg1, const orderedPair& arg2) {
	orderedPair greatest;
	if (arg1.first > arg2.first) {
		greatest.first = arg1.first;
		greatest.second = arg1.second;
		
	}
	if (arg1.first < arg2.first) {
		greatest.first = arg2.first;
		greatest.second = arg2.second;
	}
	return greatest;
}

bool isBigger (const orderedPair& arg1, const orderedPair& arg2) {
	if (arg1.first > arg2.first) {
		return 1;
	}
	else
		return 0;
}

orderedPair greatestOrderedPair( orderedPair arr[], int const size_t, orderedPair biggest) {
	orderedPair max = arr[0];
	for (int i = 1; i < 100 ; i++) {
		
		if (isBigger(arr[i], max)) {
			max = arr[i];
		}

	}
	return max;
}

void sortOrderedPairs (orderedPair* dynamicPairs, size_t N)
{
	orderedPair* dynamicOrderedPair = new orderedPair[N];

	for (int i = 0; i < N - 1; i++)
	{
		int minOrderedPair = i;

		for (int j = i; j < N; j++)
		{
			if (isBigger(dynamicOrderedPair[minOrderedPair], dynamicOrderedPair[j]))
				minOrderedPair = j;
		}

		if (minOrderedPair != i)
		{
			std::swap(dynamicOrderedPair[i], dynamicOrderedPair[minOrderedPair]);
		}
	}
	delete[] dynamicOrderedPair;
}


int main() {
	orderedPair arr[100];
    size_t N;
	
	
}