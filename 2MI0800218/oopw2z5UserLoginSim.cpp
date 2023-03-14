using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <assert.h>
#include <iostream>

const size_t MAX_SIZE = 32;
const size_t MAX_USERS = 100;
const char* FILE_PATH = "users.csv";

struct User {
    char name[MAX_SIZE];
    char password[MAX_SIZE];
    char email[MAX_SIZE];
};

struct Users {
    size_t usersCount = 0;
    User users[MAX_USERS] = { 0 };
};

bool validName(const char* name) {
    size_t length = strlen(name);
    if (length > MAX_SIZE)
        return false;
    for (size_t i = 0; i < length; i++)
    {
        if (name[i] != 45 && name[i] != 46 && name[i] != 95 &&
            name[i] < 48 && name[i] > 57 &&
            name[i] < 65 && name[i] > 90 &&
            name[i] < 97 && name[i] > 122)
            return false;
    }
    return true;
}

bool validPassword(const char* password) {
    size_t length = strlen(password);
    if (length > MAX_SIZE || length < 8)
        return false;

    bool pContainsDigit = false, pContainsLower = false, pContainsUpper = false;
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        if (password[i] >= 45 && password[i] <= 57)
            pContainsDigit = true;
        if (password[i] >= 65 && password[i] <= 90)
            pContainsUpper = true;
        if (password[i] >= 97 && password[i] <= 122)
            pContainsLower = true;
    }
    return (pContainsDigit && pContainsUpper && pContainsLower);
}

bool validEmail(const char* email) {
    return strlen(email) <= MAX_SIZE;
}

bool validUserData(const char* name, const char* password, const char* email) {
    return (validName(name) && validPassword(password) && validEmail(email));
}

bool initUser(User& toInit, const char* name, const char* password, const char* email) {
    if (!validUserData(name, password, email))
        return false;
    strcpy(toInit.name, name);
    strcpy(toInit.password, password);
    strcpy(toInit.email, email);
    return true;
}

bool addUser(const User& toAdd, Users& arr, std::ofstream& outF) {
    if (!validUserData(toAdd.name, toAdd.password, toAdd.email))
        return false;

    if (!outF.is_open())
        return false;

    if (arr.usersCount >= 100)
        return false;

    arr.users[arr.usersCount] = toAdd;
    arr.usersCount++;

    outF << toAdd.name << "," << toAdd.password << "," << toAdd.email << "\n";
    outF.flush();
    return true;
}

void getUserName(const char* userData, char* name) {
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        if (userData[i] == ',')
        {
            name[i] = '\0';
            break;
        }
        name[i] = userData[i];
    }
}

void getUserPassword(const char* userData, char* password) {
    int commas = 0;

    while (commas < 2 && *userData != '\0')
    {
        if (*userData == ',')
        {
            commas++;
            userData++;
            continue;
        }
        if (commas < 1) 
        {
            userData++; 
            continue;
        }
        *password = *userData;
        password++;
        userData++;
    }
    *password = '\0';
}

bool login(const char* name, const char* password, const char* filePath) {
    ifstream inF(filePath);
    if (!inF.is_open())
        return false;

    while (true)
    {
        char currentUser[MAX_SIZE];
        int max = 3 * MAX_SIZE + 2;
        inF.getline(currentUser, max);
        
        char currentName[MAX_SIZE];
        getUserName(currentUser, currentName);
        if (strcmp(currentName, name) == 0)
        {
            char currentPassword[MAX_SIZE];
            getUserPassword(currentUser, currentPassword);
            if (strcmp(currentPassword, password) == 0)
                return true;
        }

        if (inF.eof())
            break;
    }
    return false;
}

void loginSim() {
    cout << "Username: ";
    char username[MAX_SIZE];
    cin >> username;
    cout << "Password: ";
    char password[MAX_SIZE];
    cin >> password;

    if (login(username, password, FILE_PATH))
        cout << "Welcome, " << username << "!" << endl;
    else
        cout << "Invalid username and/or password.";
}

int main()
{
    Users users;

    ofstream outF(FILE_PATH);
    if (!outF.is_open())
        return 0;

    User u1;
    if (initUser(u1, "Pesho", "peshkata1A", "peshosmail"))
        addUser(u1, users, outF);
    User u2;
    if (initUser(u2, "Ivo", "vanka100TOPa", "ivosmail"))
        addUser(u2, users, outF);
    loginSim();
}