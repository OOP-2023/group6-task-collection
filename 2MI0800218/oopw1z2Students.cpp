#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

enum class Course {
    first,
    second,
    third,
    fourth
};

struct Student {
    char name[16];
    Course currentCourse;
    int facNumber;
    double avgGrade;
};

void printStudent(const Student& toPrint) {
    cout << toPrint.name << ", " << (int)toPrint.currentCourse << " year, " << toPrint.facNumber << ", " << toPrint.avgGrade << endl;
}

bool initStudent(Student& toInit, char name[16], int facNumber, Course course, double avgGr) {
    if (avgGr < 3 || avgGr > 6 || facNumber % 10000 < 1)
        return false;
    toInit.avgGrade = avgGr;
    toInit.facNumber = facNumber;
    toInit.currentCourse = course;
    strcpy(toInit.name, name);
    return true;
}

void swapStudents(Student& a, Student& b) {
    char tempNm[16];
    strcpy(tempNm, a.name);
    strcpy(a.name, b.name);
    strcpy(b.name, tempNm);
    Course tempCrs = a.currentCourse;
    a.currentCourse = b.currentCourse;
    b.currentCourse = tempCrs;
    int tempFN = a.facNumber;
    a.facNumber = b.facNumber;
    b.facNumber = tempFN;
    double tempGr = a.avgGrade;
    a.avgGrade = b.avgGrade;
    b.avgGrade = tempGr;
}

enum class SortBy {
    course,
    facNumber,
    avgGrade
};

bool compareSt(Student& a, Student& b, SortBy sortBy) {
    switch (sortBy) {
    case SortBy::avgGrade: return a.avgGrade > b.avgGrade;
    case SortBy::course: return (int)a.currentCourse > (int)b.currentCourse;
    case SortBy::facNumber: return a.facNumber > b.facNumber;
    default: return true;
    }
}

int maxStudentIndex(Student* students, size_t length, SortBy sortBy) {
    int maxInd = 0;
    for (size_t i = 1; i < length; i++)
    {
        if (compareSt(students[i], students[maxInd], sortBy))
            maxInd = i;
    }
    return maxInd;
}

void sortStudentsDescBy(Student* students, size_t length, SortBy sortBy) {
    for (size_t i = 0; i < length - 1; i++)
    {
        int maxStIndex = i + maxStudentIndex(students + i, length - i, sortBy);
        if (maxStIndex != 1)
            swapStudents(students[maxStIndex], students[i]);
    }
}

void printScholars(Student* students, size_t length, double average) {
    sortStudentsDescBy(students, length, SortBy::avgGrade);
    for (size_t i = 0; i < length; i++)
    {
        if (students[i].avgGrade > average)
        {
            printStudent(students[i]);
        }
    }
}

int main()
{
    Student students[4] = {
        {"G", Course::first, 56789, 4.35},
        {"H", Course::second, 34567, 5.5},
        {"I", Course::third, 67890, 3.99},
        {"J", Course::fourth, 12345, 6}
    };
    double avg = 4;
    printScholars(students, 4, avg);
}
