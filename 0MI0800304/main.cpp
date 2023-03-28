#include <fstream>
#include<iostream>

struct Example {
    int data;
    char buff[8];
};
//
//int main() {
//        std::ofstream ifile("text.txt", std::ios::app | std::ios::binary);
//        int n = 0;
//        std::cin >> n;
//        Example* exampleArr = new Example[n];
//        for (size_t i = 0; i < n; i++){
//            std::cin >> exampleArr[i].data;
//            std::cin.getline(exampleArr[i].buff, 8);
//            ifile.write((char*)&exampleArr[i], sizeof(Example));
//        }
//        delete[] exampleArr;
//        ifile.close();
//    return 0;
//}
size_t examplesInFile(const char* filePath) {
	std::fstream infile(filePath, std::ios::app | std::ios::binary);
	if (!infile.is_open()) return 0;
	size_t count = 0 ;

	while (!infile.eof()){
		infile.seekg(sizeof(Example));
		count++;
	}
	return count++;
}


int main() {



	return 0;
}