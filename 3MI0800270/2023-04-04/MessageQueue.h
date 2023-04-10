#pragma once
#include <vector>
#include <string>

enum class Mode {
    open,
    create
};

class MessageQueue {
    std::vector<std::string> messages;
    char* filename;
    Mode mode;
public:
    MessageQueue(const char*, Mode);
    void open(const char*, Mode);
    unsigned read(char*);
    void write(const char* msg, unsigned size);
    void sync();
};