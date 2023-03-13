#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const char FILE_PATH[10] = "zad5.txt";

struct User {
    char username[33];
    char password[33];
    char email[33];
};

int getTableSize(const char* filepath) {
    ifstream file(filepath);
    int count = 0;
    while (!file.eof()) {
        char ch = file.get();
        if (ch == '\n') {
            count++;
        }
    }
    file.close();
    return count;
}

void readUser(User& user, ifstream& file) {
    char str[100];
    char* ptr = str;

    if (!file.eof()) {
        file.getline(str, 99, '\n');
    }
    char username[33];
    char* ptrT = username;
    while (*ptr != ',') {
        *ptrT = *ptr;
        ptrT++;
        ptr++;
    }
    *ptrT = '\0';
    ptr++;
    char password[33];
    ptrT = password;
    while (*ptr != ',') {
        *ptrT = *ptr;
        ptrT++;
        ptr++;
    }
    *ptrT = '\0';
    ptr++;
    char email[33];
    ptrT = email;
    while (*ptr != '\0') {
        *ptrT = *ptr;
        ptrT++;
        ptr++;
    }
    *ptrT = '\0';

    strcpy(user.username, username);
    strcpy(user.password, password);
    strcpy(user.email, email);
}

bool isUsernameFree(const char* username, const char* filepath) {
    int size = getTableSize(filepath);
    ifstream file(filepath);
    for (int i = 0;i < size;i++) {
        User temp;
        readUser(temp, file);
        if (!strcmp(username, temp.username)) {
            file.close();
            return 0;
        }
    }
    file.close();
    return 1;
}
bool isEmailFree(const char* email, const char* filepath) {
    int size = getTableSize(filepath);
    ifstream file(filepath);
    for (int i = 0;i < size;i++) {
        User temp;
        readUser(temp, file);
        //cout << temp.email << "/" << email << endl;
        if (!strcmp(email, temp.email)) {
            file.close();
            return 0;
        }
    }
    file.close();
    return 1;
}


bool validateUsername(const char* username, const char* filepath) {
    int length = 0;
    const char* beg = username;
    while (*username) {
        if ((*username >= 'a' && *username <= 'z') || (*username >= 'A' && *username <= 'Z') || *username == '-' || *username == '_'
            || *username == '.' || (*username >= '0' && *username <= '9')) {
            username++;
            length++;
        }
        else {
            return 0;
        }
    }
    return length > 0 && length <= 32 && isUsernameFree(beg, filepath);
}

bool validatePassword(const char* password) {
    int length = 0;
    bool upper = 0;
    bool lower = 0;
    bool digit = 0;
    while (*password) {
        if (*password >= 'a' && *password <= 'z') {
            lower = 1;
        }
        else if (*password >= 'A' && *password <= 'Z') {
            upper = 1;
        }
        else if (*password >= '0' && *password <= '9') {
            digit = 1;
        }
        password++;
        length++;
    }
    return upper && lower && digit && length >= 8 && length <= 32;
}

bool validateEmail(const char* email, const char* filepath) {
    int length = 0;
    const char* beg = email;
    while (*email) {
        email++;
        length++;
    }
    return length <= 32 && isEmailFree(beg, filepath);
}

bool initUser(User& user, const char* username, const char* password, const char* email, const char* filepath) {
    if (validateUsername(username, filepath) && validatePassword(password) && validateEmail(email, filepath)) {
        strcpy(user.username, username);
        strcpy(user.password, password);
        strcpy(user.email, email);
        return 1;
    }
    else {
        return 0;
    }
}
bool initUser(User& user, const char* username, const char* password, const char* email) {
    strcpy(user.username, username);
    strcpy(user.password, password);
    strcpy(user.email, email);
    return 1;
}



void initDB(const char* filepath) {
    ofstream file(filepath);
    file << "";
    file.close();
}

void writeUser(ofstream& file, const User& user) {
    file << user.username << ",";
    file << user.password << ",";
    file << user.email << "\n";
}

bool writeUsers(User users[], int size, const char* filepath) {
    {
        if (getTableSize(filepath) + size > 100) {
            return 0;
        }
    }
    ofstream file(filepath);
    for (int i = 0;i < size;i++) {
        writeUser(file, users[i]);
    }
    file.close();
    return 1;
}

bool addUser(User user, const char* filepath) {
    int size = getTableSize(filepath);
    User* users = new User[size + 1];
    ifstream file(filepath);
    for (int i = 0;i < size;i++) {
        readUser(users[i], file);
    }
    file.close();
    initUser(users[size], user.username, user.password, user.email, filepath);
    return writeUsers(users, size + 1, filepath);
}

bool removeUser(User user, const char* filepath) {
    int size = getTableSize(filepath);
    User* users = new User[size];
    ifstream file(filepath);
    int index = 0;
    for (int i = 0;i < size;i++) {
        readUser(users[i], file);
        //cout << users[i].username << " " << user.username << endl;
        if (strcmp(users[i].username, user.username) == 0) {
            cout << users[i].username << endl;
            index = i;
        }
    }
    swap(users[index], users[size - 1]);
    file.close();
    return writeUsers(users, size - 1, filepath);
}

bool registerStart(User& user) {
    User temp;
    while (true) {
        cout << "Please enter your username, password and email\n- потребителско име - дължина до 32 символа, може да съдържа букви, цифри, -, _, .\n- парола - най - малко 8 символа, най - много 32, трябва да съдържа поне една главна буква, малка буква и цифра\n- имейл адрес - дължина до 32 символа" << endl;
        char username[33];
        char password[33];
        char email[33];
        cin >> username >> password >> email;

        if (initUser(temp, username, password, email, FILE_PATH)) {
            if (addUser(temp, FILE_PATH)) {
                cout << "Welcome" << endl;
                initUser(user, temp.username, temp.password, temp.email);
                return 1;
            }
            else {
                cout << "DB is full" << endl;
                return 0;
            }
        }
        else {
            cout << "Your information does not fulfill the requirments, try again." << endl;
        }
    }
}

bool loginStart(User& user) {
    int size = getTableSize(FILE_PATH);
    ifstream file(FILE_PATH);
    while (true)
    {
        cout << "Please enter your username and password" << endl;
        char username[33];
        char password[33];
        cin >> username >> password;
        for (int i = 0;i < size;i++) {
            User temp;
            readUser(temp, file);
            if (!strcmp(username, temp.username) && !strcmp(username, temp.username)) {
                file.close();
                cout << "Login Successful" << endl;
                initUser(user, temp.username, temp.password, temp.email);
                return 1;
            }
        }
        cout << "Login Unsuccessful. Try again." << endl;
    }

}

void changePassword(User& user) {
    while (true) {
        cout << "Enter new password: ";
        char pass[33];
        cin >> pass;
        if (validatePassword(pass)) {
            initUser(user, user.username, pass, user.email);
            removeUser(user, FILE_PATH);
            addUser(user, FILE_PATH);
            cout << "Password changed." << endl;
            break;
        }
    }
}

void cliStart() {
    User currUser;
    cout << "Hello user, would you like to register? [y/n]" << endl;
    char answer[2];
    cin >> answer;
    if (!strcmp(answer, "y")) {
        registerStart(currUser);
    }
    else {
        cout << "Would you like to login? [y,n]" << endl;
        cin >> answer;
        if (!strcmp(answer, "y")) {
            loginStart(currUser);
        }
        else {
            return;
        }
    }
    while (true) {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1: Change Password" << endl;
        cout << "2: Exit" << endl;
        cout << "Enter the number of your option of choice:" << endl;
        int opt;
        cin >> opt;
        if (opt == 1) {
            changePassword(currUser);
        }
        else if (opt == 2) {
            break;
        }
    }
}
int main() {
    initDB(FILE_PATH);
    User u1;
    User u2;

    initUser(u1, "babayaga", "cutterUp1", "haunted@house.bg", FILE_PATH);
    initUser(u2, "luhgeeky", "Kr4nkyKr4nky", "racks@tonka.net", FILE_PATH);

    User users[2] = { u1,u2 };

    writeUsers(users, 2, FILE_PATH);

    cliStart();

    /*goooberrr
    guguGAGA1
    sadadsasd@ff.dsa */
}