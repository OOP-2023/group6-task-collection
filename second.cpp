#include <iostream>
struct OrderedDoubles
{
    int first = 1;
    int second = 1;
};
bool compareOrderedDoubles(OrderedDoubles firstNum, OrderedDoubles secondNum)
{
    if (firstNum.first > secondNum.first)
    {
        return true;
    }
    else if (firstNum.first == secondNum.first && firstNum.second > secondNum.second)
    {
        return true;
    }
    return false;
}
OrderedDoubles biggestOrderedDouble(const OrderedDoubles arrayOfOrderedDoubles[5])
{
    OrderedDoubles biggestDouble = arrayOfOrderedDoubles[0];
    for (int i = 1; i < 5; ++i)
    {
        if (compareOrderedDoubles(arrayOfOrderedDoubles[i], biggestDouble))
        {
            biggestDouble = arrayOfOrderedDoubles[i];
        }
    }
    return biggestDouble;
}
void sortOrderedDoubles(OrderedDoubles* arrayOfOrderedDoubles, int maxRange)
{
    int i, j;
    for (i = 0; i < maxRange - 1; i++)
        for (j = 0; j < maxRange - i - 1; j++)
            if (compareOrderedDoubles(arrayOfOrderedDoubles[j], arrayOfOrderedDoubles[j + 1]))
                std::swap(arrayOfOrderedDoubles[j], arrayOfOrderedDoubles[j + 1]);
}
void inputOrderedDoubles(OrderedDoubles& num)
{
    std::cin >> num.first >> num.second;
}
int main()
{
//    OrderedDoubles x, y;
//    readInputOrderedDoubles(x);
//    readInputOrderedDoubles(y);
//    std::cout << compareOrderedDoubles(x, y);
//    OrderedDoubles arrayOfOrderedDoubles[5]= {{5, 2}, {5, 2},{5, 2}, {5, 2}};
//    std::cout << biggestOrderedDouble(arrayOfOrderedDoubles).first << biggestOrderedDouble(arrayOfOrderedDoubles).second;
    int countOfDoubles;
    std::cin >> countOfDoubles;
    OrderedDoubles* dynamicOrderedDoubles = new OrderedDoubles[countOfDoubles];
    for (int i = 0; i < countOfDoubles; ++i)
    {
        inputOrderedDoubles(dynamicOrderedDoubles[i]);
    }
    sortOrderedDoubles(dynamicOrderedDoubles, countOfDoubles);
    for (int i = 0; i < countOfDoubles; ++i)
    {
        std::cout << dynamicOrderedDoubles[i].first << dynamicOrderedDoubles[i].second;
    }
    return 0;
}
