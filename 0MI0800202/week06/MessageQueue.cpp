#include <iostream>
#include <fstream>
#include "MessageQueue.h"
#include <fstream>
#include <cstring>

void MessageQueue::sync()
{
    int counter = 0;
    while(true) {
        std::string toInsert;
        std::getline(file, toInsert, ' ');

        queue.insert(queue.begin(), toInsert);
        if (file.eof())
        {
            break;
        }
    }

}

MessageQueue::MessageQueue(const char *name, mode m)
{
    if (m == mode::create)
        file.open(name, std::ios::trunc);
    else
    {
        file.open(name, std::ios::app);
    }
}

void MessageQueue::open(const char *receivedName, mode m)
{
    strcpy(name, receivedName);
    if (m == mode::create)
        file.open(name, std::ios::trunc);
    else
    {
        file.open(name, std::ios::app);
    }
}
size_t MessageQueue::read()
{
    if (queue.empty())
    {
        sync();
        return 0;
    }
    int lastIndex = queue.size() - 1;
    std::string message = queue[lastIndex];
    queue.pop_back();
    return sizeof(message);
}
int main()
{
    MessageQueue pesho("funny.txt", mode::create);

}

