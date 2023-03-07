#include <iostream>
#pragma warning(disable: 4996)
struct transition
{};


//zad 2
struct pair
{
    int firstInt;
    int secondInt;  
};
void inputIntsOfPair(pair& pair1)
{
    std::cout << "First integer: ";
    std::cin >> pair1.firstInt;
    std::cout << "Second integer: ";
    std::cin >> pair1.secondInt;
}
bool isBigger(const pair& firstPair, const pair& secondPair)
{
    return firstPair.firstInt > secondPair.firstInt ||
        (firstPair.firstInt == secondPair.firstInt && firstPair.secondInt > secondPair.secondInt);
}
pair biggestPair(const pair* pairs, size_t size)
{
    size_t indexOfBiggestPair = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (isBigger(pairs[i], pairs[indexOfBiggestPair]))
            indexOfBiggestPair = i;
    }
    return pairs[indexOfBiggestPair];
}
void swap(pair& pair1, pair& pair2)
{
    pair temp = pair2;
    pair2 = pair1;
    pair1 = temp;
}
void sortPairs(pair* pairs, size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        pair biggestPair1 = biggestPair(pairs + i, size - i);
        if (isBigger(biggestPair1, pairs[i - 1]))
            swap(biggestPair1, pairs[i - 1]);
        //std::cout << (pairs + i)->secondInt << " " << size - 1;
    }
}



//zad 3
enum class classes
{
    first,
    second,
    third,
    fourth
};
struct Student
{
    char* name;
    size_t facultyNumber;
    classes studentClasses;
    float grade;
};
void classesToChar(char* classesChar, const classes& cl)
{
    if (cl == classes::first)
    {
        strcpy(classesChar, "first");
        return;
    }
    if (cl == classes::second)
    {
        strcpy(classesChar, "second");
        return;
    }
    if (cl == classes::third)
    {
        strcpy(classesChar, "third");
        return;
    }
    if (cl == classes::fourth)
    {
        strcpy(classesChar, "fourth");
        return;
    }
}
void printStudent(const Student& toPrint)
{
    char classesChar[10];
    classesToChar(classesChar, toPrint.studentClasses);
    std::cout << toPrint.name << " " << toPrint.facultyNumber << " " <<
        classesChar << " " << toPrint.grade << " " << std::endl;
}
int main()
{
    //pair p1, p2;
    //p1.firstInt = p2.firstInt = p2.secondInt = 1;
    //p1.secondInt = 2;
    //pair pairs[2] = { p1, p2 };
    //sortPairs(pairs, 2);

    Student st;
    st.facultyNumber = 123456;
    st.grade = 5.2f;
    char name[16] = "Pavel";
    st.name = name;
    st.studentClasses = classes::first;
    printStudent(st);
}