size_t examplesInFile(const char* filePath) {
    ifstream f("filePath.txt", ios::binary | ios::in);
    size_t currPos = f.tellg();
    f.seekg(0, ios::end);
    size_t size = f.tellg();
    f.seekg(currPos);
    return size / sizeof(Example);
}
