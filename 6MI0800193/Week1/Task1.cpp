#include <iostream>
using namespace std;
struct transition
{
    size_t to_go;
    char way;
};

struct state
{
    size_t current;
    size_t transitions_count = 0;
    transition transitions[4];
};

struct state_info
{
    state data[50];
};

bool has_transition(const state_info& arg, size_t from, char c)
{
    for (size_t i = 0; i < arg.data[from].transitions_count; i++)
    {
        if (arg.data[from].transitions[i].way == c)
            return true;
    }
    return false;
}

bool add_transition(state_info& arg, size_t from, char c, size_t to)
{
    if (arg.data[from].transitions_count >= 4)
        return false;

    if (has_transition(arg, from, c))
        return true;

    size_t& current_way = arg.data[from].transitions_count;
    
    arg.data[from].transitions[current_way].to_go = to;
    arg.data[from].transitions[current_way].way = c;
    current_way++;
}

int getTransition(const state_info& arg, size_t from, char c)
{
    for (size_t i = 0; i < arg.data[from].transitions_count; i++)
    {
        if (arg.data[from].transitions[i].way == c)
            return arg.data[from].transitions[i].to_go;
    }
    return -1;
}

bool canRead(const state_info& arg, const char* word, size_t from)
{
    if (*word == '\0')
        return true;

    for (int i = 0; i < arg.data[from].transitions_count; i++)
    {
        if (arg.data[from].transitions[i].way == *word)
            return canRead(arg, word + 1, arg.data[from].transitions[i].to_go);
    }
    return false;
}

bool remove_transition(state_info& arg, size_t from, char c)
{
    int i = getTransition(arg, from, c);

    if (i == -1)
        return false;

    std::swap(arg.data[from].transitions[i - 1], arg.data[from].transitions[i]);

    arg.data[from].transitions_count--;

    return true;
}

int main()
{
    state_info stateInfo;

    stateInfo.data[1] = { 1, 2, {{3, 'a'},{2, 'b'}} };
    stateInfo.data[2] = { 2, 2, {{3, 'b'},{1, 'd'}} };
    stateInfo.data[3] = { 3, 1, {{4, 'a'}} };
    stateInfo.data[4] = { 4, 1, {{2, 'c'}} };

    cout << "From 3 with a: " << has_transition(stateInfo, 3, 'a') << endl;
    cout << "From 3 with k: " << has_transition(stateInfo, 3, 'k') << endl;
    cout << "From 3 with x: " << has_transition(stateInfo, 3, 'x') << endl;
    
    add_transition(stateInfo, 3, 'x', 2);

    cout << "From 3 with k (where?): " << getTransition(stateInfo, 3, 'k') << endl;
    cout << "From 3 with a (where?): " << getTransition(stateInfo, 3, 'a') << endl;
    cout << "From 3 with x (where?): " << getTransition(stateInfo, 3, 'x') << endl;

    cout << "Can read (aac): " << canRead(stateInfo, "aac", 1) << endl;
    cout << "Can read (xyz): " << canRead(stateInfo, "xyz", 1) << endl;

    remove_transition(stateInfo, 3, 'x');
    cout << "From 3 with x: " << has_transition(stateInfo, 3, 'x') << endl;



}
