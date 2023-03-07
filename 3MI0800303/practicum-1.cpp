#include <iostream>
#pragma warning(disable : 4996)

struct OrderedTwo {
    int firstNumber;
    int secondNumber;
    bool isBigger(OrderedTwo& ordered) const;
};

inline bool OrderedTwo::isBigger(OrderedTwo& cmp) const {
    if (firstNumber == cmp.firstNumber) return secondNumber > cmp.secondNumber;
    if (firstNumber < cmp.firstNumber) return false;
    return true;
}

int getBiggest(OrderedTwo ords[100]) {
    for (size_t i = 0; i < 100; i++) {
        for (size_t j = i + 1; j < 100; j++) {
            if (ords[i].isBigger(ords[j])) std::swap(ords[i], ords[j]);
        }
    }

    return 0;
}

enum class Course {
    first,
    second,
    third,
    fourth
};

struct Student {
    char name[16];
    int fn_number;
    Course course;
    double avg_grade;
    void printStudents() const;
};

void Student::printStudents() const {
    char courseChar[7];
    switch (course) {
    case Course::first: strcpy(courseChar, "first"); break;
    case Course::second: strcpy(courseChar, "second"); break;
    case Course::third: strcpy(courseChar, "third"); break;
    case Course::fourth: strcpy(courseChar, "fourth"); break;
    }

    std::cout << "Name: " << name << " Fn Number: " << fn_number << " course: " << courseChar << " grade: " << avg_grade << std::endl;
    //std::cout << "Name:" << x << " Fn Number: %"
}

bool initStudent(Student& toInit, char name[16], int facNumber, Course currentCourse, double grade) {
    if (facNumber <= 99999 || facNumber > 999999) return false;
    if (grade < 2 && grade > 6) return false;

    strcpy(toInit.name, name);
    toInit.avg_grade = grade;
    toInit.course = currentCourse;
    toInit.fn_number = facNumber;
    return true;
}

void printScholars(Student* students, size_t length, double average) {
    for (size_t i = 0; i < length; i++)
    {
        if (students[i].avg_grade > average) students[i].printStudents();
    }
}

struct Transition { //using NULL as a default value to check if a cell is free in State
    int to = NULL;
    char with = NULL;
};

struct State {
    Transition transitions[4];
};

struct StateInfo {
    State data[50];
    bool hasTransition(int from, char c) const;
    void addTransition(size_t from, char c, int to);
    int getTransition(size_t from, char c) const;
    bool canRead(const char* word, size_t from) const;
    void removeTransition(size_t from, char c);
};

bool StateInfo::hasTransition(int from, char c) const {
    for (size_t i = 0; i < 4; i++)
    {
        if (data[from].transitions[i].with == c) return true;
    }

    return false;
}

void StateInfo::addTransition(size_t from, char c, int to) {
    for (size_t i = 0; i < 4; i++)
    {
        if (data[from].transitions[i].to == NULL) {
            data[from].transitions[i] = { to, c };
            break;
        }
    }
}

int StateInfo::getTransition(size_t from, char c) const {
    for (size_t i = 0; i < 4; i++)
    {
        if (data[from].transitions[i].with == c) return data[from].transitions[i].to;
    }

    return -1;
}

bool StateInfo::canRead(const char* word, size_t from) const {
    if (!*word) return true;
    for (size_t i = 0; i < 4; i++)
    {
        if (data[from].transitions[i].with == *word) {
            return canRead(++word, data[from].transitions[i].to);
        }
    }

    return false;
}

void StateInfo::removeTransition(size_t from, char c) {
    for (size_t i = 0; i < 4; i++)
    {
        if (data[from].transitions[i].with == c) data[from].transitions[i] = { NULL, NULL };
    }
}

int main()
{
    StateInfo sinfo;
    sinfo.data[1].transitions[0] = { 3, 'a' };
    sinfo.data[1].transitions[1] = { 2, 'b' };
    sinfo.data[2].transitions[0] = { 3, 'b' };
    sinfo.data[2].transitions[1] = { 1, 'd' };
    sinfo.data[3].transitions[0] = { 4, 'a' };
    sinfo.data[4].transitions[0] = { 2, 'c' };

    sinfo.addTransition(2, 'a', 4);
}