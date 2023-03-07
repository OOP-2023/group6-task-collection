#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

struct timestamp
{
    int hours;
    int minutes;
    int seconds;
};

union ip_address {
    uint32_t address;
    unsigned char octets[4];
};

struct Log
{
    char name[16];
    timestamp time;
    ip_address ip;
};

bool write_log(const Log& to_write, std::ofstream& out_file)
{
    out_file << to_write.name << " " << to_write.time.hours << " " << to_write.time.minutes
        << " " << to_write.time.seconds << " " << to_write.ip.address << endl;
    return true;
}

bool write_logs(Log* logs, size_t logs_count, std::ofstream& out_file)
{
    for (size_t i = 0; i < logs_count; i++)
    {
        write_log(logs[i], out_file);
    }
    return true;
}

bool read_log(Log& to_read, std::ifstream& in_file)
{
    char name[16];
    timestamp time;
    ip_address addr;

    in_file.getline(name, 16, ' ');
    in_file >> time.hours >> time.minutes >> time.seconds;
    in_file >> addr.address;

    to_read.ip = addr;
    to_read.time = time;
    strcpy(to_read.name, name);

    return true;
}

size_t logs_count(const char* file_path)
{
    ifstream input(file_path);

    size_t lines = 0;

    char buff[512];

    while (!input.eof())
    {
        input.getline(buff, 512);

        if (input.eof())
            break;

        lines++;
    }
    return lines;
}

size_t read_logs(Log* logs, const char* file_path)
{
    size_t count = logs_count(file_path);

    ifstream input(file_path);

    for (size_t i = 0; i < count; i++)
    {
        try {
            read_log(logs[i], input);
        }
        catch(exception e) {
            return 0;
        }
    }
    return count;

}

void print_log(const Log& log)
{
    cout << log.name << " " << log.time.hours << ":" << log.time.minutes << ":" << log.time.seconds
        << " " << (int)log.ip.octets[0] << "." << (int)log.ip.octets[1] 
        << "." << (int)log.ip.octets[2] << "." << (int)log.ip.octets[3] << endl;
}

void print_logs(const Log* logs, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        print_log(logs[i]);
    }
}

int main()
{
    Log read_user;

    Log* logs = new Log[3];
    logs[0] = { {'I','v','a','n','\0'}, {12,45,25}, 16777343 };
    logs[1] = { {'G','e','o','r', 'g', 'i','\0'}, {18,12,47}, 16820416 };
    logs[2] = { {'T', 'o', 'd', 'o', 'r','\0'}, {23,13,06}, 2069302329 };

    ofstream test_out("out.txt");
    ifstream test_in("out.txt");

    write_logs(logs, 3, test_out);

    Log* logs_from_file = new Log[3];

    size_t count = read_logs(logs_from_file, "out.txt");
    
    print_logs(logs_from_file, count);

    delete[] logs_from_file;
    delete[] logs;
    
}
