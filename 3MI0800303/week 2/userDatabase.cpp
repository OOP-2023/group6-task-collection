#include <iostream>;
#include <fstream>;

#pragma warning(disable : 4996)

const int MAX_SIZE = 32;

struct User {
    char username[32];
    char password[32];
    char email[32];
};

struct UserDatabase {
    User users[100]{0};
    size_t numberOfRecords = 0;
    char databasePath[1024];
};

bool validateUserUsername(const char* username) {
    size_t len = 0;
    while (*username) {
        if (!(
            (*username >= '1' && *username <= '9') ||
            (*username >= 'a' && *username <= 'z') ||
            (*username >= 'A' && *username <= 'Z') ||
            *username == '-' || *username == '_' || *username == '.')
            ) return false;

        username++;
        len++;
    }

    return len >= 6;
}

bool validateUserPassword(const char* password) {
    size_t len = 0;
    bool flags[3]{ 0 }; // 0 - lower, 1 - upper, 2 - digit

    while (*password) {
        if (*password >= 'a' && *password <= 'z') flags[0]++;
        if (*password >= 'A' && *password <= 'Z') flags[1]++;
        if (*password >= '1' && *password <= '9') flags[2]++;

        len++;
        password++;
    }

    return (len >= 6) && flags[0] && flags[1] && flags[2];
}

void printLogo() {
    system("CLS"); //windows
    //system("clear"); //linux
    std::cout << R"(
      _    _               _____        _        _                    
     | |  | |             |  __ \      | |      | |                   
     | |  | |___  ___ _ __| |  | | __ _| |_ __ _| |__   __ _ ___  ___ 
     | |  | / __|/ _ \ '__| |  | |/ _` | __/ _` | '_ \ / _` / __|/ _ \
     | |__| \__ \  __/ |  | |__| | (_| | || (_| | |_) | (_| \__ \  __/
      \____/|___/\___|_|  |_____/ \__,_|\__\__,_|_.__/ \__,_|___/\___|
    )" << '\n';
}

bool createUser(User& user) {

    char email[32];
    char username[32];
    char password[32];

    std::cin >> username >> password >> email;

    if (!validateUserPassword(password) || !validateUserUsername(username)) return false;
    strcpy(user.email, email);
    strcpy(user.username, username);
    strcpy(user.password, password);

    return true;
}

bool createUser(User& user, const char* email, const char* username, const char* password) {

    if (!validateUserPassword(password) || !validateUserUsername(username)) return false;
    strcpy(user.email, email);
    strcpy(user.username, username);
    strcpy(user.password, password);

    return true;
}


UserDatabase createUserDatabase() {
    UserDatabase udb;
    char databasePath[1024];
    std::cout << "Enter path > ";
    std::cin.getline(databasePath, 1024);
    strcpy(udb.databasePath, databasePath);
    return udb;
}

bool fileExists(const char* path) {
    std::ifstream file(path);
    return file.good();
}

int strsplit(char* dest, const char* str, char split) {
    int count = 0;
    while(*str != split){
        if (!*str) break;
        *dest = *str;

        count++;
        dest++;
        str++;
    }
    return count+1;
}

bool validateUnique(const UserDatabase& db, const User& user) {
    for (size_t i = 0; i < db.numberOfRecords; i++)
    {
        if (strcmp(db.users[i].username, user.username) == 0) return false;
        if (strcmp(db.users[i].email, user.email) == 0) return false;
    }
    return true;
}

void connectFile(UserDatabase& db) {
    if (!fileExists(db.databasePath)) {
        std::cout << "File does not exist, creating " << db.databasePath << "..." << std::endl;
        std::ofstream file(db.databasePath);
        file.close();
    }
    else {
        std::cout << "Loading " << db.databasePath << "..." << std::endl;
        std::fstream file;
        file.open(db.databasePath, std::fstream::in);
        while(!file.eof())
        {

            char information[3][MAX_SIZE]{0};
            
            char line[MAX_SIZE*3 + 2];
            char* ptr = line;
            file.getline(line, 1024);
            
            if (!*ptr) break;
            for (size_t i = 0; i < 3; i++)
            {
                int moved = strsplit(information[i], ptr, ',');
                ptr += moved;
            }
            

            User user;
            if(!createUser(user, information[0], information[1], information[2])) 
                throw std::invalid_argument("Error while parsing users, check for malformed data.");
            if(!validateUnique(db, user))
                throw std::invalid_argument("Duplicate of credentials.");
            db.users[db.numberOfRecords++] = user;
        }
        file.close();
    }

    std::cout << "Database initialized." << std::endl;
}



bool addUser(UserDatabase& db, const char* email, const char* username, const char* password) {
    std::fstream file;
    file.open(db.databasePath, std::fstream::app);

    User user;
    if(!createUser(user, email, username, password)) return false;
    db.users[db.numberOfRecords++] = user;
    file << user.email << "," << user.username << "," << user.password << '\n';

    return true;
}

int loginUser(UserDatabase& db, const char* username, const char* password) {
    for (size_t i = 0; i < db.numberOfRecords; i++)
    {
        if (strcmp(db.users[i].username, username) == 0) {
            if (strcmp(db.users[i].password, password) == 0)
                return i;
        }
    }

    return -1; //not found
}

void updateDatabaseFile(UserDatabase& db, const int fromIndex){
    std::ofstream file(db.databasePath);
    
    for (size_t i = 0; i < db.numberOfRecords; i++)
    {
        file << db.users[i].email << ',' << db.users[i].username << ',' << db.users[i].password << '\n';
    }
}

bool changePassword(UserDatabase& db, const char* newpassowrd, const int index) {
    if (!validateUserPassword(newpassowrd)) return false;
    strcpy(db.users[index].password, newpassowrd);
    updateDatabaseFile(db, index);
    return true;
}

void printUser(User& user) {
    std::cout << user.email << " " << user.username << " " << user.password << std::endl;
}

void printAllUsers(UserDatabase& db) {
    for (size_t i = 0; i < db.numberOfRecords; i++)
    {
        printUser(db.users[i]);
    }
}

void helpCommand() {

    std::cout << "Commands:" << std::endl;
    std::cout << "printAll" << std::endl;
    std::cout << "addUser [email] [username] [password]" << std::endl;
    std::cout << "login [username] [password]" << std::endl;
    std::cout << "loginOut" << std::endl;
    std::cout << "changePassword [new password]" << std::endl;
}

void getCommand(UserDatabase& db, bool& isLoggedIn, char* username, int& index) {

    char args[1024];
    std::cout << username << ">";
    std::cin.getline(args, 1024);
    char command[32]{0};
    int skipped = strsplit(command, args, ' ');


    if (strcmp("help", command) == 0) helpCommand();
    else if (strcmp("printAll", command) == 0) printAllUsers(db);
    else if (strcmp("addUser", command) == 0) {
        char information[3][MAX_SIZE]{0};
        char* ptr = (args + skipped);
        int moved = 0;
        moved = strsplit(information[0], ptr, ' ');
        ptr += moved;
        moved = strsplit(information[1], ptr, ' ');
        ptr += moved;
        strsplit(information[2], ptr, ' ');

        if(!addUser(db, information[0], information[1], information[2])) 
            std::cout << "Something went wrong" << std::endl;
    }
    else if (strcmp("login", command) == 0) {
        char information[3][MAX_SIZE]{ 0 };
        char* ptr = (args + skipped);
        int moved = 0;
        moved = strsplit(information[0], ptr, ' ');
        ptr += moved;
        moved = strsplit(information[1], ptr, ' ');

        int tryIndex = loginUser(db, information[0], information[1]);
        if (tryIndex != -1) {
            isLoggedIn = true;
            strcpy(username, information[0]);
            index = tryIndex;
        }
    }
    else if (strcmp("changePassword", command) == 0) {
        if (!isLoggedIn) {
            std::cout << "Must be logged in";
            return;
        }

        char information[3][MAX_SIZE]{ 0 };
        char* ptr = (args + skipped);
        char newpassword[32]{ 0 };
        strsplit(newpassword, ptr, ' ');
        if (!changePassword(db, newpassword, index)) std::cout << "Try another password.";
    }
    else if (strcmp("logOut", command) == 0) {
        isLoggedIn = false;
        strcpy(username, "");
        index = -1;
    }
}

void startDatabase(UserDatabase& db) {
    try
    {
        bool isLoggedIn = false;
        char username[32]{ 0 };
        int index = -1;

        connectFile(db);
        
        std::cout << "Type help for the list of commands" << std::endl;
        
        while (true) {
            getCommand(db, isLoggedIn, username, index);
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
}


int main() {

    printLogo();
    UserDatabase db = createUserDatabase();
    startDatabase(db);
}