#include "MessageQueue.h"
using namespace std;
MessageQueue::MessageQueue(std::string path, modes mode)
{
	if (mode == modes::open)
	{
		this->file.open(path, std::ios::in | std::ios::out);
	}
	else
	{
		this->file.open(path, std::ios::in | std::ios::out | std::ios::trunc);
	}
	sync();
}

MessageQueue::~MessageQueue()
{
	file.close();
}

void MessageQueue::open(std::string path, modes mode)
{
	if (mode == modes::open)
	{
		this->file.open(path, std::ios::in | std::ios::out);
	}
	else
	{
		this->file.open(path, std::ios::in | std::ios::out | std::ios::trunc);
	}
	sync();
}

const string& MessageQueue::pop()
{
	string first = messages[0];

	for (size_t i = 0; i < messages.size() - 1; i++)
	{
		messages[i] = messages[i + 1];
	}

	messages.pop_back();

	return first;
}

const string& MessageQueue::peek()
{
	return messages[0];
}

void MessageQueue::push(const std::string& str)
{
	messages.push_back(str);
}

void MessageQueue::sync()
{
	this->file.seekg(ios::beg);

	while (!file.eof())
	{
		string line = "";
		char sym = file.get();

		if (file.eof())
			return;

		while (sym != '\n')
		{
			line += sym;
			sym = file.get();
		}
		this->messages.push_back(line);
	}
}

size_t MessageQueue::read(std::string& msg)
{
	msg = peek();
	return msg.size();
}

void MessageQueue::write(std::string mes, size_t size)
{
	push(mes);
	file << mes << '\n';
	file.flush();
}
std::string MessageQueue::get_message_at(size_t pos)
{
	return messages[pos];
}
