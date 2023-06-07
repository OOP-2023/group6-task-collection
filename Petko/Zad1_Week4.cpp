// Zad1_Week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Time {
public:
	Time();
	Time(int hrs, int minutes, int seconds);
	Time(size_t n);
	int getHours();
	int getMinutes();
	int getSeconds();
	void setHours(int);
	void setMinutes(int);
	void setSeconds(int);
	bool compareTime(const Time& other);
	int elapsedTime() const;
	Time remainingTime();
private:
	int hours;
	int mins;
	int secnds;
};
Time::Time() {
	hours = 0;
	mins = 0;
	secnds = 0;
}
Time::Time(int hrs, int minutes, int seconds) {
	hours = hrs;
	mins = minutes;
	secnds = seconds;
}
Time::Time(size_t n) {
	hours = n / 3600;
	mins = (n % 3600)/60;
	secnds = (n % 3600) % 60;
}
int Time::getHours() {
	return hours;
}
int Time::getMinutes() {
	return mins;
}
int Time::getSeconds() {
	return secnds;
}
void Time::setHours(int hrs) {
	hours = hrs;
}
void Time::setMinutes(int minutes) {
	mins = minutes;
}
void Time::setSeconds(int seconds) {
	secnds = seconds;
}
int Time::elapsedTime() const {
	return hours * 3600 + mins * 60 + secnds;
}
bool Time::compareTime(const Time& other)
{
	return elapsedTime() < other.elapsedTime();
}
Time Time::remainingTime() {
	return Time(24 * 3600 - elapsedTime());
}
int main()
{
 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
