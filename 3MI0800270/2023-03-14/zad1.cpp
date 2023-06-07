#include "vector.h"
using namespace std;

int main() {
    try {
        Vector a = Vector();
        for (int i = 0;i < 20;i++) {
            a.push_back(i);
            int m = a[i];
            cout << m << endl;
        }
        cout << endl;
        for (int i = 0;i < 20;i++) {
            cout << a[i] << endl;
        }
    }
    catch (exception e) {
        cout << e.what();
    }
}