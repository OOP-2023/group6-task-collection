#include <iostream>
using namespace std;

struct transition {
    size_t to;
    char c;
};

struct state {
    transition transitions[4];
    size_t num;
};

struct stateInfo {
    state data[50];
};

bool hasTransition(const stateInfo& arg, size_t from, char c) {
    size_t number = arg.data[from].num;
    for (int j = 0;j < number;j++) {
        if (arg.data[from].transitions[j].c == c) {
            return true;
        }
    }
}
bool addTransition(stateInfo& arg, size_t from, char c, size_t to) {
    size_t number = arg.data[from].num;
    if (number >= 4) {
        return false;
    }
    else {
        arg.data[from].transitions[number].c = c;
        arg.data[from].transitions[number].to = to;
    }
}
int getTransition(const stateInfo& arg, size_t from, char c) {
    size_t number = arg.data[from].num;
    for (int i = 0;i < number;i) {
        if (arg.data[from].transitions[i].c == c) {
            return i;
        }
    }
    return -1;
}
bool canRead(const stateInfo& arg, char* word, size_t from) {
    size_t pos = from;
    while (!*word) {
        if (hasTransition(arg, pos, *word)) {
            pos = arg.data[pos].transitions[getTransition(arg, pos, *word)].to;
            word++;
        }
        else {
            break;
        }
    }
    if (*word) {
        return true;
    }
    else {
        return false;
    }
}
bool removeTransition(stateInfo& arg, size_t from, char c) {
    if (hasTransition(arg, from, c)) {
        size_t pos = getTransition(arg, from, c);
        size_t number = arg.data[from].num;
        arg.data[from].transitions[pos].c = arg.data[from].transitions[number].c;
        arg.data[from].transitions[pos].to = arg.data[from].transitions[number].to;
        arg.data[from].num--;
        return true;
    }
    else {
        return false;
    }
}


int main() {
}