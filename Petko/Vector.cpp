#ifndef VECTOR_HEADER
#define VECTOR_HEADER

/// @brief ����, ����� ������������
/// ��������� �����
class vector {
public:
    /// @brief ������� ������ ��������� � capacity 8.
    vector();

    vector(const vector&);
    vector(vector&&);

    vector& operator=(const vector&);

    /// @brief ������� ���������.
    /// @param argCap ���������� �� ����������.
    vector(int argCap);

    /// @brief ������� ���������.
    /// @param argCap ���������� �� ����������.
    /// @param argDef ��������� �������� �� ������ ��������.
    vector(int argCap, int argDef); // ������� ��������� � argCap �������� ���� ����� ������� � ����� �� argDef.

    /// @brief ����� ����� �� ������ �������.
    /// @param  ��������� �� ����� ������ �� �����.
    int operator[](size_t) const;

    /// @brief ����� ����� �� �������� ������� � ��������� ��������� ��.
    /// @param  ��������� �� ����� �� ����� ��� � ����� �� �����
    int& operator[](size_t);

    /// @brief ������ ������� � ����������.
    /// @param  ��������, ����� ��������.
    void push_back(int);

    /// @brief �������� ��������� ������� �� ����������
    /// @return ��������� ������� �� ����������
    int pop_back();

    ~vector();
private:
    int* data;       // < �������, � ����� ������ ������������
    size_t size;     // < ���� �������� � ����������
    size_t capacity; // < ����������� ���� ��������, ����� ���������� ��������

    /// @brief ������� �������
    void free();

    /// @brief ������ �����
    void copy(const vector&);

    /// @brief ������� ������� �� ������. 
    void resize();
};

vector::vector() : vector(8) {}

vector::vector(int argCap) {
    this->size = 0;
    this->capacity = argCap;
    this->data = new int[this->capacity];
}
vector::vector(int argCap, int argDef)
{
    this->size = 0;
    this->capacity = argCap;
    this->data = new int[this->capacity];
    for (int i = size; i < capacity; i++)
    {
        this->data[i] = argDef;
    }
}
int vector::pop_back() {
    this->data[size] = 0;
    this->size--;
}
void vector::free() {
    delete[] data;
}
void vector::resize()
{
    this->capacity *= 2;
    this->data = new int[this->capacity];
}
void vector::copy(const vector& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new int[this->capacity];
    for (size_t i = 0; i < other.size; i++) {
        this->data[i] = other[i];
    }
}
int vector::operator[](size_t pos)const {
            return this->data[pos];
}
int& vector::operator[](size_t pos) {
    return this->data[pos];
}
void vector::push_back(int el) {
    if (this->size == this->capacity)
        resize();
    this->data[size] = el;
    this->size++;
}
vector::~vector() {
    free();
}

vector::vector(vector&& other) {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

vector::vector(const vector& other) {
    copy(other);
}

vector& vector::operator=(const vector& other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}

#endif

