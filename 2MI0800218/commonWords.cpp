#include <iostream>
#include <fstream>

const size_t MAX_LENGTH = 200;

class vector {
public:
    vector() {
        data = new char[8];
        size = 0;
        capacity = 8;
    }

    vector(const vector& other) {
        copy(other);
    }

    vector(vector&& other) {
        data = other.data;
        size = other.size;
        capacity = other.capacity;
    }

    vector& operator=(const vector& other) {
        if (this != &other)
        {
            free();
            copy(other);
        }

        return *this;
    }

    vector(char argCap) {
        data = new char[argCap];
        size = 0;
        capacity = argCap;
    }

    vector(char argCap, int argDef) {
        data = new char[argCap];
        size = 0;
        capacity = argCap;

        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef;
        }
    }

    char operator[](size_t index) const {
        return data[index];
    }

    char& operator[](size_t index) {
        return data[index];
    }

    void push_back(char n) {
        if (size == capacity)
            resize();

        data[size] = n;
        size++;
    }

    int pop_back() {
        if (size == 0)
            return 0;

        size--;
        return data[size + 1];
    }

    size_t getSize() const {
        return size;
    }

    ~vector() {
        free();
    }

private:
    char* data;      
    size_t size;     
    size_t capacity; 

    void free() {
        delete[] data;
    }

    void copy(const vector& other) {
        data = new char[other.capacity];

        for (size_t i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }

        size = other.size;
        capacity = other.capacity;
    }

    void resize() {
        char* nData = new char[capacity * 2];
        for (size_t i = 0; i < size; i++)
        {
            nData[i] = data[i];
        }

        capacity *= 2;
        free();
        data = nData;
    }
};

class Word {
    private:
        vector wordData;
        int line;
        int length;

    public:
        Word() {
            wordData = vector();
            line = 0;
            length = wordData.getSize();
        }

        Word(const Word& other) {
            wordData = vector(other.wordData);
        }

        Word(Word&& other) {
            wordData = other.wordData;
        }

        Word(const vector& v, const int lineArg) {
            wordData = v;
            line = lineArg;
            length = v.getSize();
        }

        Word& operator=(const Word& other) {
            if (this != &other)
            {
                wordData = other.wordData;
                length = other.getLength();
                line = other.getLine();
            }

            return *this;
        }

        vector getWord() {
            return wordData;
        }

        int getLine() const {
            return line;
        }

        int getLength() const {
            return length;
        }

        void setWord(vector& wData) {
            wordData = wData;
        }

        void setLine(const int ln) {
            line = ln;
        }

};

bool readLine(std::ifstream& fin, vector& v) {
    if (!fin.is_open())
        return false;

    char current = fin.get();
    while (!fin.eof() && current != '\n')
    {
        v.push_back(current);
        current = fin.get();
    }
    return true;
}

bool printWord(std::ofstream& fout, Word& word) {
    if (!fout.is_open())
        return false;
    
    size_t length = word.getLength();
    
    for (size_t i = 0; i < length; i++)
    {
        fout << word.getWord()[i];
    }
    fout.flush();
    return true;
}

int main()
{
    std::ifstream fin("common_words.txt");
    if (!fin.is_open())
        return -1;

    std::ofstream fout("longestWord.txt");
    if (!fout.is_open())
        return -1;

    Word maxWord;
    int lineIndex = 0;

    while (!fin.eof()) {
        lineIndex++;
        vector currentLine = readLine(fin, currentLine);

        Word currentWord = Word(currentLine, lineIndex);

        if (currentWord.getLength() > maxWord.getLength())
        {
            maxWord = currentWord;
        }
    }

    printWord(fout, maxWord);
    fout << "\n " << maxWord.getLength() << "\n" << maxWord.getLine();
    
}