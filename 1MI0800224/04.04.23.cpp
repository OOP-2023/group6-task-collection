#include <iostream>
#include<vector>
#include<string>
#include <fstream>

enum class mode{
    open,
    create
};

std::ios_base::openmode asIOSMode(mode m) {
    if (m == mode::open) {
        return std::ios::in | std::ios::out | std::ios::app;
    }
    else {
        return std::ios::in | std::ios::out | std::ios::trunc;
    }
}

class MessageQueue{
private:
    std::vector<std::string> data;
    size_t head;
    size_t tail;

public:
    MessageQueue(const char*, mode m);
    void open(const char*, mode q);
    size_t read(const char* msg);
    void write(const char* msg, size_t size);
    void sync();
};

MessageQueue::MessageQueue(const char* filepath, mode mode = mode::open){

}

int main(){
    std::string str = "hello";

    std::string fstHalf = std::string(str.begin(), str.begin() + str.size() / 2);
    //std::string fstHalf = str.substr(0, str.size() / 2);
    std::cout << fstHalf;
}
