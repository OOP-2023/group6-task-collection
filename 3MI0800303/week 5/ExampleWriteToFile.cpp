    #include <iostream>
    #include <fstream>
    #include <cstring>

    struct Example {
        int data;
        char buff[8];
    };

    void WriteNEntries(){
        int n;
        std::cin >> n;
        Example* exp = new Example[n];
        for (size_t i = 0; i < n; i++)
        {
            std::cin >> exp[i].data;
            std::cin.ignore();
            std::cin.getline(exp[i].buff, 8);
        }

        std::ofstream of("file.txt", std::ios::app | std::ios::binary);
        of.write((char *)exp, n*sizeof(Example));
        delete[] exp;
    }

    int countOfEntries(){
        std::ifstream fi("file.txt", std::ios::binary);
        size_t curr_pos = fi.tellg();
        fi.seekg(0, std::ios::end);
        size_t size = fi.tellg();
        fi.seekg(curr_pos);

        return size/sizeof(Example);
    }

    void findExample(const char* pattern){
        std::ifstream fi("file.txt", std::ios::binary);
        int count = 0;
        Example buff;
        while (true)
        {
            if(fi.eof()) break;
            fi.read((char *)&buff, sizeof(buff));
            if(strcmp(buff.buff, pattern) == 0) break;
        }

        std::cout << buff.data << std::endl;
    }

    int main(){
        WriteNEntries();
        // std::cout << countOfEntries() << std::endl;
        findExample("test");
    }