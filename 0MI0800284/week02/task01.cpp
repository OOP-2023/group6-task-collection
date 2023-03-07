
#include <iostream>
using namespace std;

struct Transition
{
	size_t number;
	char ch;
};

struct State
{
	Transition trans[4];
};

struct StateInfo
{
	State data[50];
};

bool hasTransition(const StateInfo& arg, size_t from, char c)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (arg.data[from].trans[i].ch == c)
			return true;
	}
	return false;
}

bool addTransition(StateInfo& arg, size_t from, char c, size_t to)
{
	int count = 0;
	for (size_t i = 0; i < 4; i++)
	{
		if (arg.data[from].trans[i].ch == c)
		{
			break;
		}
		if (arg.data[from].trans[i].ch != '\0')
		{
			count++;
		}
	}
	if (count >= 4)
	{
		return false;
	}
	arg.data[from].trans[count].number = to;
	return true;
}

int getTransition(const StateInfo& arg, size_t from, char c)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (arg.data[from].trans[i].ch == c)
			return arg.data[from].trans[i].number;
	}
	return -1;
}

bool canRead(const StateInfo& arg, char* word, size_t from)
{
	size_t state = from;
	int length = strlen(word);
	for (size_t i = 0; i < length; i++)
	{
		state = getTransition(arg, state, word[i]);
		if (state == -1)
			return false;
	}
	return true;
}

bool removeTransition(StateInfo& arg, size_t from, char c)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (arg.data[from].trans[i].ch == c)
		{
			arg.data[from].trans[i].number = 0;
			arg.data[from].trans[i].ch = '\0';
			return true;
		}
	}
	return false;
}

int main()
{
	StateInfo stateinfo;
	stateinfo.data[1].trans[0] = { 3, 'a' };
	stateinfo.data[1].trans[1] = { 2, 'b' };

	stateinfo.data[2].trans[0] = { 3, 'b' };
	stateinfo.data[2].trans[1] = { 1, 'd' };


	stateinfo.data[3].trans[0] = { 4, 'a' };

	stateinfo.data[4].trans[0] = { 2, 'c' };
}
