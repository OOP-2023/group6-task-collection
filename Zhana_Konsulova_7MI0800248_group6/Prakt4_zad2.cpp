// Prakt_21.03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Element {
private:
	int value;
	size_t rank;

public:
	Element() : value(0), rank(0) {};
	Element(int v, size_t r) : value(v), rank(r) {};

	void printTheElement()
	{
		std::cout << value << " - " << rank << std::endl;
	}
	int getValue()
	{
		return value;
	}
	size_t getRank()
	{
		return rank;
	}
	void setValue(int v)
	{
		value = v;
	}
	void setRank(size_t r)
	{
		rank = r;
	}
};

class Queue {
private:
	Element* priorityQueue;
	size_t size;
	size_t capacity;

public:
	Queue();
	Queue(Element* queue, size_t s, size_t cap) : priorityQueue(queue), size(s), capacity(cap) {};

	void printTheQueue()
	{
		for (int i = 0; i < size; i++)
			priorityQueue[i].printTheElement();
	}
	Element* getPriorityQueue() const
	{
		return priorityQueue;
	}
	size_t getSize()
	{
		return size;
	}
	size_t getCapacity()
	{
		return capacity;
	}

	void setSize(size_t s)
	{
		size = s;
	}

	void pushBack(Element el);
	Element& peak() const;
	Element getElementWithBiggestRank();
	void deleteTheElementAtASpecificPos(int index);
	
};

//Insertion Sort
void Swap(Element& el1, Element& el2)
{
	size_t rank1 = el1.getRank();
	int value1 = el1.getValue();

	el1.setValue(el2.getValue());
	el1.setRank(el2.getRank());
	el2.setValue(value1);
	el2.setRank(rank1);
}
void Insert(Element* arr, size_t size)
{
	size_t elIndex = size - 1;

	while (elIndex > 0 && arr[elIndex].getRank() > arr[elIndex - 1].getRank())
	{
		Swap(arr[elIndex], arr[elIndex-1]);
		elIndex--;
	}

}
void InsertionSortPriorityQueue(Element* arr, size_t size)
{
	for (int i = 1; i < size; i++)
		Insert(arr, i + 1);
}

void Queue::pushBack(Element el)
{
	Element* prQueue = getPriorityQueue();
	size_t size = getSize();
	prQueue[size] = el;
	setSize(++size);

	InsertionSortPriorityQueue(prQueue, size);

}

Element& Queue::peak() const
{
	return getPriorityQueue()[0];
}
void Queue::deleteTheElementAtASpecificPos(int index)
{
	getPriorityQueue()[index].setValue(0);
	getPriorityQueue()[index].setRank(0);

	InsertionSortPriorityQueue(getPriorityQueue(), getSize());
	setSize(getSize() - 1);
}
Element Queue::getElementWithBiggestRank()
{
	Element el = peak();
	deleteTheElementAtASpecificPos(0);
	return el;
}




int main()
{
	Element e1(5, 2);
	Element e2(7, 3);
	Element e3(2, 1);
	Element e4(4, 2);
		
	Element* arr = new Element[7];
	arr[0] = e1;
	arr[1] = e2;
	arr[2] = e3;
	arr[3] = e4;
	InsertionSortPriorityQueue(arr, 4);
	
	Queue queue(arr, 4, 7);
	queue.printTheQueue();

	std::cout << "Plus one el:" << std::endl;
	Element e5(12, 9);
	queue.pushBack(e5);
	
	queue.printTheQueue();

	Element max = queue.getElementWithBiggestRank();
	std::cout << "after the delete: " << std::endl;
	queue.printTheQueue();
	
	delete[] arr;
	

	
}
