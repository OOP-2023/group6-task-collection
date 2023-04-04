#ifndef _MESSAGEQUEUE
#define _MESSAGEQUEUE
#include <string>
#include <vector>
#include <fstream>
#include <string>
enum modes
{
	open,
	create
};

class MessageQueue
{
private:
	std::vector<std::string> messages;
	std::fstream file;

	const std::string& pop();
	const std::string& peek();
	void push(const std::string& str);

public:
	MessageQueue(std::string, modes mode);
	~MessageQueue();
	void open(std::string, modes mode);
	size_t read(std::string&);
	void write(std::string, size_t size);
	void sync();
	std::string get_message_at(size_t pos);
};

#endif // !_MESSAGEQUEUE
