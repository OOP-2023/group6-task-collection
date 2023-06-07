#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

/* union IPv4
{
    u_int32_t address;
    u_int8_t arg[4];
};

union Time {
    u_int32_t time;
    struct {
        u_int8_t hours;
        u_int8_t minutes;
        u_int8_t seconds;
        u_int8_t millis;
    }S;
    //i saw online that this is undefined behavior, but i wanted to try it because it seems interesting
};

Time createTime(u_int8_t hours, u_int8_t minutes, u_int8_t seconds, u_int8_t millis) {
    return Time{ .S = {hours,minutes,seconds,millis} };
}
Time createTime(u_int32_t time) {
    return Time{ .time = time };
}

IPv4 createIp(u_int8_t ip1, u_int8_t ip2, u_int8_t ip3, u_int8_t ip4) {
    return IPv4{ .arg = {ip1,ip2,ip3,ip4} };
}
IPv4 createIp(u_int32_t ip) {
    return IPv4{ .address = ip };
} */

struct IPv4 {
    int addr[4];
};

struct Time {
    int nums[4];
};

struct Log {
    char name[16] = "";
    IPv4 ip;
    Time time;
};

IPv4 readIP(char* ip) {
    IPv4 res;
    for (int i = 0;i < 4;i++) {
        char addr[4];
        char* ptr = addr;
        do {
            *ptr = *ip;
            ptr++;
            ip++;
        } while (*ip != '.' && *ip);
        if (*ip != '\0') {
            ip++;
        }
        *ptr = '\0';
        res.addr[i] = atoi(addr);
    }
    return res;
}
Time readTime(char* time) {
    Time res;
    for (int i = 0;i < 4;i++) {
        char addr[4];
        char* ptr = addr;
        do {
            *ptr = *time;
            ptr++;
            time++;
        } while (*time != ':' && *time);
        if (*time != '\0') {
            time++;
        }
        *ptr = '\0';
        res.nums[i] = atoi(addr);
    }
    return res;
}

bool writeLog(const Log& toWrite, std::ofstream& outFile) {
    if (!outFile.is_open()) {
        cout << "Error";
        return 0;
    }
    outFile << toWrite.name << "|";

    for (int i = 0;i < 4;i++) {
        outFile << toWrite.ip.addr[i];
        if (i != 3) {
            outFile << ".";
        }
    }
    outFile << " ";

    outFile << toWrite.time.nums[0] << ":";
    outFile << toWrite.time.nums[1] << ":";
    outFile << toWrite.time.nums[2] << ":";
    outFile << toWrite.time.nums[3] << " \n";

    return 1;
}
bool writeLogs(Log* logs, size_t size, const char* filePath) {
    ofstream file(filePath);
    if (!file.is_open()) {
        cout << "Error";
        return 0;
    }
    for (size_t i = 0; i < size; i++)
    {
        writeLog(logs[i], file);
    }
    file.close();
    return 1;
}

bool readLog(Log& toRead, std::ifstream& inFile) {
    if (!inFile.is_open()) {
        cout << "Error";
        return 0;
    }
    char name[16];
    inFile.getline(name, 15, '|');

    char ip[17];
    inFile >> ip;
    IPv4 ipv4 = readIP(ip);

    char timeStr[13];
    inFile >> timeStr;
    Time time = readTime(timeStr);
    strcpy(toRead.name, name);
    toRead.time = time;
    toRead.ip = ipv4;

    return 1;
}

int main() {
    Log log1 = { "real n", {5,254,255,254}, {23,49,49,99} };
    Log log2 = { "real n2", {1,1,1,1 }, { 23,59,59,99 } };
    Log logs[2] = { log1,log2 };
    writeLogs(logs, 2, "zad4.txt");
    ifstream file("zad4.txt");
    readLog(log2, file);
    Log logs2[2] = { log1,log2 };
    file.close();
    writeLogs(logs2, 2, "zad4.txt");

}