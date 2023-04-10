#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;



class Date {
public:
    int day;
    int month;
    int year;
    float temp;
    Date(int day, int month, int year, float temp) {
        this->day = day;
        this->month = month;
        this->year = year;
        this->temp = temp;
    }
    Date():Date(0, 0, 0, 0) {};
};

Date readDate(ifstream& file) {
    if (!file.is_open() || file.eof()) {
        throw out_of_range("error");
    }
    Date date = Date();
    char row[16] = "";
    file.getline(row, 16);
    cout << row << endl;
    date.day = (row[0] - '0') * 10 + (row[1] - '0');
    date.month = (row[3] - '0') * 10 + row[4] - '0';
    date.year = (row[6] - '0') * 1000 + (row[7] - '0') * 100 + (row[8] - '0') * 10 + row[9] - '0'; //evil bithack magix

    char temp[5] = "";
    strcpy(temp, row + 11);
    date.temp = atof(temp);

    return date;
}

class TableRow {
public:
    int year;
    float avg_temp;
    float min_temp;
    int min_day;
    float max_temp;
    int max_day;

    TableRow(int year, float avg_temp, float min_temp, int min_day, float max_temp, int max_day) {
        this->year = year;
        this->avg_temp = avg_temp;
        this->min_temp = min_temp;
        this->min_day = min_day;
        this->max_temp = max_temp;
        this->max_day = max_day;
    }
    TableRow():TableRow(0, 0, 0, 0, 0, 0) {}
};

void createRows(const char* filename) {
    ifstream file(filename);
    Date date = readDate(file);
    int currYear = date.year;
    TableRow row;
}

int main() {
    ifstream file("dates.txt");
    //cout << file.is_open();
    Date date = readDate(file);
}