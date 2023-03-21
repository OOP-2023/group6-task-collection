#include "RankedPairList.h"
#include <iostream>

int DEFAULT_CAPACITY = 4;

RankedPairList::RankedPairList(size_t cap) {
	pairs = new RankedPair[cap]{0};
	size = 0;
	capacity = cap;
}

RankedPairList::RankedPairList() : RankedPairList(DEFAULT_CAPACITY) {}

void RankedPairList::resize() { // if enlarge true double the size, else shrink
		RankedPair* resPairs = new RankedPair[capacity * 2];
		for (size_t i = 0; i < size; i++)
		{
			resPairs[i] = pairs[i];
		}
		delete[] pairs;
		pairs = resPairs;
		capacity *= 2;
	
	//else if (size - 1 < capacity / 2) {
	//	RankedPair* resPairs = new RankedPair[capacity / 2];
	//	for (size_t i = 0; i < size; i++)
	//	{
	//		resPairs[i] = pairs[i];
	//	}
	//	delete[] pairs;
	//	pairs = resPairs;
	//	capacity /= 2;
	//}
}

void RankedPairList::push_back(int elem, size_t rank) {
	if (size + 1 > capacity) resize();
	pairs[size] = {elem, rank};
	size++;
}

int RankedPairList::getElementWithBiggestRank() {
	int pos = 0;

	for (size_t i = 1; i < size; i++)
	{
		if (pairs[i].rank > pairs[pos].rank) {
			pos = i;
		}
	}
	
	int temp = pairs[pos].value;
	pairs[pos].value = 0;
	pairs[pos].rank = 0;

	return temp;
}

int RankedPairList::peak() const{
	int pos = 0;

	for (size_t i = 1; i < size; i++)
	{
		if (pairs[i].rank > pairs[pos].rank) {
			pos = i;
		}
	}

	return pairs[pos].value;
}

