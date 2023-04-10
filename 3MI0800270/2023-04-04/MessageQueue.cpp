#include "MessageQueue.h"
#include <fstream>
#include <cstring>

MessageQueue::MessageQueue(const char* filename, Mode mode) {
    this->filename = new char[strlen(filename)];
    strcpy(this->filename, filename);

    this->mode = mode;

    open(filename, mode);
}

void MessageQueue::open(const char* filename, Mode mode) {
    std::ifstream file;
    if (mode == Mode::open) {
        file.open(filename, std::fstream::app | std::fstream::binary);
    }
    if (mode == Mode::create) {
        file.open(filename, std::fstream::binary);
    }
    if (!file.is_open()) {
        throw std::runtime_error("filename error");
    }
    while (!file.eof()) {
        std::string buf;
        getline(file, buf);
        messages.push_back(buf);
    }
}

unsigned MessageQueue::read(char* msg) {

}

void MessageQueue::write(const char* msg, unsigned size) {

}
int main() {

}