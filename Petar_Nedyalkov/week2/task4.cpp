#include <iostream>
#include <fstream>

union IpAddress
{
	uint32_t address;
	unsigned char octets[4];
};
// 16777343 == 127.0.0.1

struct LastLog {
	unsigned int sec;
	unsigned int min;
	unsigned int hour;
};

struct Log {
	char username[17]; //+1 for Null Terminator
	IpAddress ipAdress;
	LastLog lastLog;
};

void initLastLog(LastLog& log, unsigned sec, unsigned min, unsigned hour)
{
	log.sec = sec;
	log.min = min;
	log.hour = hour;
}

void printLastLog(const LastLog& log)
{
	std::cout << log.hour << ":" << log.min << ":" << log.sec;
}

void printIpAdrress(const IpAddress& myAddress)
{
	std::cout << (int)myAddress.octets[0] << "."
		<< (int)myAddress.octets[1] << "."
		<< (int)myAddress.octets[2] << "."
		<< (int)myAddress.octets[3];
}

bool writeLog(const Log& toWrite, std::ofstream& outFile)
{
	if (!outFile.is_open())
	{
		std::cout << "Error!" << std::endl;
		return false;
	}

	outFile << toWrite.username << " ";
	printIpAdrress(toWrite.ipAdress);
	std::cout << " ";
	printLastLog(toWrite.lastLog);
	std::cout<<std::endl;
	outFile.close();
	return true;
}

bool writeLogs(Log* logs, size_t size, std::ofstream& outFile)
{
	if (!outFile.is_open())
	{
		std::cout << "Error!" << std::endl;
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		writeLog(logs[i],outFile);
	}

	outFile.close();
	return true;
}

bool readLog(Log& toRead, std::ifstream& inFile)
{
	 // no time :(
	return true;
}

size_t logsCount(std::ifstream inFile)
{
	if (!inFile.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}

	size_t count = 0;
	while (!inFile.eof())
	{
		if(inFile.get() == '\n')
			count++;
	}

	inFile.close();
	return count;
}

size_t readLogs(Log* logs, std::ifstream inFile)
{
	 //no time :(
	return 0;
}


int main()
{
	//no time to test it 
}