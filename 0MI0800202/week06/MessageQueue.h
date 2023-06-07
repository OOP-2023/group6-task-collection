#ifndef WEEK06_MESSAGEQUEUE_H
#define WEEK06_MESSAGEQUEUE_H

#include <vector>

enum class mode{
    open,
    create
};
class MessageQueue
{
private:
    char name[128];
    std::fstream file;
    std::vector<std::string> queue;
public:
    MessageQueue(const char* name, mode m);
    void open(const char* name, mode m);
    void sync();
    size_t read();
};

#endif