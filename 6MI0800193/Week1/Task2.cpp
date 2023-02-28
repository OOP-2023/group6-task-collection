#include <iostream>
using namespace std;

struct Tuple {
    int first;
    int second;
};

void read_tuple(Tuple& x)
{
    cin >> x.first >> x.second;
}

bool compare_tuples(const Tuple& x, const Tuple& y) // x > y -> true
{
    return (x.first > y.first) || ((x.first == y.first) && (x.second > y.second));
}

Tuple get_biggest(const Tuple tuples[100])
{
    Tuple biggest = tuples[0];
    for (size_t i = 1; i < 100; i++)
    {
        if (compare_tuples(tuples[i], biggest))
        {
            biggest = tuples[i];
        }
    }
    return biggest;
}

void swap(Tuple& x, Tuple& y)
{
    Tuple temp = x;
    x = y;
    y = temp;
}

void sort_tuples(Tuple* tuples, size_t elements)
{
    int min_idx = 0;
    for (size_t i = 0; i < elements - 1; i++)
    {
        min_idx = i;
        for (size_t j = i + 1; j < elements; j++)
        {
            if (compare_tuples(tuples[min_idx], tuples[j]))
                min_idx = j;
        }

        if (min_idx != i)
        {
            swap(tuples[min_idx], tuples[i]);
        }
    }
}

int main()
{
    Tuple x, y;
    read_tuple(x);
    read_tuple(y);
    cout << compare_tuples(x, y) << endl;

    Tuple tuples[100] = { {0,0} };
    tuples[0] = x;
    tuples[1] = y;

    cout << get_biggest(tuples).second << endl;

    int n;
    cin >> n;
    Tuple* dyn_tup = new Tuple[n];

    for (size_t i = 0; i < n; i++)
    {
        read_tuple(dyn_tup[i]);
    }

    sort_tuples(dyn_tup, n);

    for (size_t i = 0; i < n; i++)
    {
        cout << dyn_tup[i].first << " " << dyn_tup[i].second << endl;
    }

    /*
    2 3
    2 5
    5
    2 3 
    1 5
    2 5
    8 9
    0 3
    */
    delete[] dyn_tup;
}
