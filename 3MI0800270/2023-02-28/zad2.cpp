#include <iostream>
using namespace std;

struct Tuple {
    int first;
    int second;

    void input() {
        cin >> first;
        cin >> second;
    };
};

int compareTuples(const Tuple& a, const Tuple& b) {
    if (a.first > b.first || (a.first == b.first && a.second > b.second)) {
        return 1;
    }
    else if (a.first == b.first && a.second == b.second) {
        return 0;
    }
    else {
        return -1;
    }
}
int biggestTuple(const Tuple tuples[100]) {
    int index = 0;
    Tuple currBig = tuples[0];
    for (int i = 1;i < 100;i++) {
        if (compareTuples(tuples[i], currBig) == 1)
        {
            currBig = tuples[i];
            index = i;
        }
    }
    return index;
}

void sortTuples(Tuple* tuples, size_t size) {
    for (int i = 0;i < size - 1;i++) {
        for (int j = i + 1;j < size;j++) {
            if (compareTuples(tuples[j], tuples[i]) == -1)
            {
                swap(tuples[i], tuples[j]);
            }
        }
    }
}

int main() {

    const Tuple tuples[100] = { {0,1},{2,1},{1,1} };
    Tuple* tuples2 = new Tuple[3];
    for (int i = 0;i < 3;i++) {
        tuples2[i].input();
    }
    sortTuples(tuples2, 3);
    for (int i = 0;i < 3;i++) {
        cout << tuples2[i].first << ' ' << tuples2[i].second << endl;
    }
    delete[] tuples2;
}