#ifndef VECTOR_HEADER
#define VECTOR_HEADER

/// @brief ����, ����� ������������
/// ��������� �����
class vector {
public:
    /// @brief ������� ������ ��������� � capacity 8.
    vector() {
        data = new int[8];
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

    /// @brief ������� ���������.
    /// @param argCap ���������� �� ����������.
    vector(int argCap) {
        data = new int[argCap];
        size = 0;
        capacity = argCap;
    }

    /// @brief ������� ���������.
    /// @param argCap ���������� �� ����������.
    /// @param argDef ��������� �������� �� ������ ��������.
    vector(int argCap, int argDef) { // ������� ��������� � argCap �������� ���� ����� ������� � ����� �� argDef.
        data = new int[argCap];
        size = 0;
        capacity = argCap;

        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef;
        }
    }

    /// @brief ����� ����� �� ������ �������.
    /// @param  ��������� �� ����� ������ �� �����.
    int operator[](size_t index) const {
        return data[index];
    }

    /// @brief ����� ����� �� �������� ������� � ��������� ��������� ��.
    /// @param  ��������� �� ����� �� ����� ��� � ����� �� �����
    int& operator[](size_t index) {
        return data[index];
    }


    /// @brief ������ ������� � ����������.
    /// @param  ��������, ����� ��������.
    void push_back(int n) {
        if (size == capacity)
            resize();

        data[size] = n;
        size++;
    }

    /// @brief �������� ��������� ������� �� ����������
    /// @return ��������� ������� �� ����������
    int pop_back() {
        if (size == 0)
            return INT_MIN;

        size--;
        return data[size + 1];
    }

    ~vector() {
        free();
    }

private:
    int* data;       // < �������, � ����� ������ ������������
    size_t size;     // < ���� �������� � ����������
    size_t capacity; // < ����������� ���� ��������, ����� ���������� ��������

    /// @brief ������� �������
    void free() {
        delete[] data;
    }

    /// @brief ������ �����
    void copy(const vector& other) {
        data = new int[other.capacity];

        for (size_t i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }

        size = other.size;
        capacity = other.capacity;
    }

    /// @brief ������� ������� �� ������. 
    void resize() {
        int* nData = new int[capacity * 2];
        for (size_t i = 0; i < size; i++)
        {
            nData[i] = data[i];
        }

        capacity *= 2;
        free();
        data = nData;
    }
};

#endif