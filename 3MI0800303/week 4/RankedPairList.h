#ifndef _RANKED_PAIR_LIST_HPP
#define _RANKED_PAIR_LIST_HPP

struct RankedPair {
	int value;
	size_t rank;
};

class RankedPairList{
	private:
		RankedPair* pairs;
		size_t capacity;
		size_t size;
		void resize(); // doubles if size > capacity, shrinks if capacity/2 >= size

	public:
		RankedPairList();
		RankedPairList(size_t);
		void push_back(int elem, size_t rank);
		int getElementWithBiggestRank();
		int peak() const;
};

#endif