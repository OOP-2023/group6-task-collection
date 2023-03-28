#include <iostream>
#include <fstream>


struct Example {
    int data;
    char buff[8];
};

void userInputForN(size_t& n)
{
    while (n < 1)
    {
        std::cout << "Enter a number for input > ";
        std::cin >> n;
    }
}

void userInputForNStructures(Example* arrayOfExamples, size_t size)
{
    std::cout << "Enter " << size << " Example structures: \n";
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arrayOfExamples[i].data;
        std::cin.getline(arrayOfExamples[i].buff, 8);
    }
}

void deleteDynamicArray(Example* array)
{
    delete[] array;
}

void writeAllExamples(std::ofstream& file, Example* array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        file.put(array[i].data);
        file.write(array[i].buff, 8);
        file << "\n";
    }
}

void readFromBinaryFile(std::ifstream& file, char* buffer, size_t sizeOfBuffer)
{
    while (file)
    {
        file.read(buffer, sizeOfBuffer);
        std::cout << buffer << std::endl;
    }
}

int main()
{
    

    size_t n = 0;

    userInputForN(n);

    Example* array = new Example[n];
 
    userInputForNStructures(array, n);

    char fileName[100];
    std::cout << "Enter name for File >";
    std::cin >> fileName;

    std::ofstream file(fileName, std::ios::binary | std::ios::out | std::ios::app);

    if (!file.is_open())
    {
        std::cerr << "Error when opening file! \n";
        return 0;
    }

    writeAllExamples(file, array, n);

    deleteDynamicArray(array);
    file.close();


    std::ifstream readFile(fileName, std::ios::in | std::ios::binary);
    char* buffer = new char[sizeof(Example)];
    readFromBinaryFile(readFile, buffer, sizeof(Example));
    readFile.close();

	return 0;
}