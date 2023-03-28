#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

struct Listing
{
    char name[25];
    int programmers_count;
    int paid_leave;
    int salary;
};

void input_listing(Listing& list)
{
    cin.ignore();
    cin.getline(list.name, 25);
    cin >> list.programmers_count;
    cin >> list.paid_leave;
    cin >> list.salary;
}

void input_listings(Listing* list, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        input_listing(list[i]);
    }
}

void write_listings(const Listing* lists, int n, const char* file_path)
{
    ofstream outfile(file_path, ios::binary | ios::app);

    if (!outfile.is_open())
        return;

    outfile.write((char*)&lists, n * sizeof(Listing));

    outfile.close();
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    Listing* lists = new Listing[n];

    input_listings(lists, n);

    write_listings(lists, n, "data.dat");

    delete[] lists;
}
/*
3
Firma1
10
5
2000
Firam2
15
10
6000
Firam3
1
2
3

*/