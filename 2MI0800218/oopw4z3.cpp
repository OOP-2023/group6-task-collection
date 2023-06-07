#include <fstream>
#include <iostream>

const size_t MAX_SIZE = 200;


//atoi(char *) => int 
//atoi(line)
//atoi(line+3)
//atoi(line+6)
// atof(char*) => double
//temp = atof(line+11)

int getYear(char line[MAX_SIZE]) {
    int y = (line[6] - '0') * 1000 + (line[7] - '0') * 100 + (line[8] - '0') * 10 + (line[9] - '0');
    return y;
}

int getDay(char line[MAX_SIZE]) {
    return (line[0] - '0') * 10 + (line[1] - '0');
}

int getMonth(char line[MAX_SIZE]) {
    return (line[3] - '0') * 10 + (line[4] - '0');
}

double getTemp(char line[MAX_SIZE]) {
    double t = -200;
    if (line[13] == '.')
        t = (line[11] - '0') * 10 + (line[12] - '0') + (line[14] - '0') / 10;
    else if (line[12] == '.')
        t = (line[11] - '0') + (line[13] - '0') / 10;

    return t;
}

bool z3(std::ifstream& inf, std::ofstream& outf) {
    if (!inf.is_open() || !outf.is_open())
        return false;

    char line[MAX_SIZE]{ 0 };
    outf << "Year, Avg.T, Min.T, Min.D" << std::endl;
    inf.getline(line, MAX_SIZE);
     

    while (!inf.eof())
    {
        inf.getline(line, MAX_SIZE);
        int year = getYear(line);
        double minT = getTemp(line);
        int minD = getDay(line);
        int minM = getMonth(line);

        double tSum = 0;
        int daysCounted = 0;
        int currentYear = year;
        while (currentYear == year)
        {
            daysCounted++;
            double currentTemp = getTemp(line);
            tSum += currentTemp;
            if (currentTemp < minT)
            {
                minD = getDay(line);
                minM = getMonth(line);
                minT = currentTemp;
            }

            inf.getline(line, MAX_SIZE);
            currentYear = getYear(line);

            if (inf.eof())
                break;
        }
        
        double avgT = tSum / daysCounted;
        outf << year << ", " << avgT << ", " << minT << ", " << minD << "/" << minM << "/" << std::endl;

    }
    outf.flush();
    return true;
}

int main()
{
    std::ifstream inf("z3in.csv");
    std::ofstream outf("z3out.csv");
    std::cout << z3(inf, outf);
    inf.close();
    outf.close();
}