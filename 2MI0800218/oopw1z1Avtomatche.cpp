using namespace std;
#include <iostream>

struct transition {
    int stateN;
    char c;
};

struct state {
    transition transitions[4];
    int tranzitionsFromZero;
};

struct stateInfo {
    state data[50];
};

bool hasTransition(const stateInfo& si, size_t from, char c) {
    if (from > 49) {
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        if (si.data[from].transitions[i].c == c) {
            return true;
        }
    }
    return false;
}

bool addTransition(stateInfo& si, size_t from, char c, size_t to) {
    for (int i = 0; i < 4; i++)
    {
        if (si.data[from].transitions[i].c == c ||
            si.data[from].transitions[i].c == 0 && si.data[from].transitions[i].stateN == 0)
        {
            si.data[from].transitions[i].c = c;
            si.data[from].transitions[i].stateN = to;
            return true;
        }
    }
    return false;
}

int getTransition(const stateInfo& si, size_t from, char c) {
    for (size_t i = 0; i < 4; i++)
    {
        if (si.data[from].transitions[i].c == c) {
            return si.data[from].transitions[i].stateN;
        }
    }
    return -1;
}

bool canRead(const stateInfo& si, char* word, size_t from) {
    if (*word == '\0')
    {
        return 1;
    }

    for (size_t i = 0; i < 4; i++)
    {
        if (si.data[from].transitions[i].c == *word)
        {
             return canRead(si, word + 1, si.data[from].transitions[i].stateN);
        }
    }

    return 0;
}

bool removeTransition(stateInfo& si, size_t from, char c) {
    for (size_t i = 0; i < 4; i++)
    {
        if (si.data[from].transitions[i].c == c)
        {
            si.data[from].transitions[i].c = 0;
            si.data[from].transitions[i].stateN = 0;
            return true;
        }
    }
    return false;
}

int main()
{
    stateInfo stateinfo;
    stateinfo.data[0] = {};
    stateinfo.data[1] = { { {3, 'a'}, {2, 'b'} }, 0 };
    stateinfo.data[2] = { { {3, 'b'}, {1, 'd'}, {4, 'h'}, {2, 'c'}}, 0};
    stateinfo.data[3] = { {4, 'a'}, 0};
    stateinfo.data[4] = { {2, 'c'}, 0};

    //1
    {
        for (int i = 0; i < 5; i++)
        {
            cout << hasTransition(stateinfo, i, 'c') << '\n';
        }
        cout << "----\n";
    }

    //2
    {
        for (int i = 0; i < 5; i++)
        {
            cout << addTransition(stateinfo, i, 'a', 1) << '\n';
            for (int j = 0; j < 4; j++)
            {
                cout << stateinfo.data[i].transitions[j].c << " " << stateinfo.data[i].transitions[j].stateN << '\n';
            }
            cout << "--\n";
        }
        cout << "----\n";
    }

    //3
    {
        cout << "a:\n";
        for (int i = 0; i < 5; i++)
        {
            cout << getTransition(stateinfo, i, 'a') << endl;
        }
        cout << "----" << endl;
    }

    //4
    {
        char word1[] = "bcchc";
        char word2[] = "ccccccchb";
        cout << canRead(stateinfo, word1, 1) << " " << canRead(stateinfo, word2, 4) << endl;;
        cout << "----\n";
    }

    //5
    {
        cout << removeTransition(stateinfo, 2, 'h') << endl;
        cout << "2:" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << stateinfo.data[2].transitions[i].stateN << "  "
                << stateinfo.data[2].transitions[i].c << endl;
        }
        cout << "----" << endl;
    }
}