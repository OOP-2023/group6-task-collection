#ifndef VECTOR_HEADER
#define VECTOR_HEADER

/// @brief ����, ����� ������������
/// ��������� �����
class vector {

public:
    /// @brief ������� ������ ��������� � capacity 8.
    vector() :vector(8) {}

    vector(const vector &a) :vector(a)
    {
        for(int i=0; i<size; i++){
            data[i]=a.data[i];
        }
    }
    vector(vector &&);

    vector &operator=(const vector &a){
        if(&a==this)
            return *this;
        int* newData = new int[a.capacity];
        for(int i=0; i<size; i++){
            newData[i]=a.data[i];
        }
        delete [] data;
        data = newData;
        size=a.size;
        capacity=a.capacity;
        return *this;

    }

    /// @brief ������� ���������.
    /// @param argCap ���������� �� ����������.
    vector(int argCap){
        size=0;
        capacity=argCap;
        data = new int[argCap];
    }

    /// @brief ������� ���������.
    /// @param argCap ���������� �� ����������.
    /// @param argDef ��������� �������� �� ������ ��������.
    vector(int argCap, int argDef): vector(argCap){
        //data = new int[argCap];
        //size=argCap;
        //capacity=argCap;
        for(int i=0; i<capacity; i++, size++){
            data[i]=argDef;
        }
    } // ������� ��������� � argCap �������� ���� ����� ������� � ����� �� argDef.

    /// @brief ����� ����� �� ������ �������.
    /// @param  ��������� �� ����� ������ �� �����.
    int operator[](size_t) const;

    /// @brief ����� ����� �� �������� ������� � ��������� ��������� ��.
    /// @param  ��������� �� ����� �� ����� ��� � ����� �� �����
    int &operator[](size_t);

    /// @brief ������ ������� � ����������.
    /// @param  ��������, ����� ��������.
    void push_back(int push){
        if(size==capacity){
            resize();
        }
        data[size]=push;
        size++;
    }

    /// @brief �������� ��������� ������� �� ����������
    /// @return ��������� ������� �� ����������
    int pop_back();

    ~vector();
private:
    int *data;       // < �������, � ����� ������ ������������
    size_t size;     // < ���� �������� � ����������
    size_t capacity; // < ����������� ���� ��������, ����� ���������� ��������

    /// @brief ������� �������
    void free
        delete [] data;
    }

    /// @brief ������ �����
    void copy(const vector &);

    /// @brief ������� ������� �� ������.
    void resize(){

        int* data1=new int[capacity*2];
        for(int i=0; i<capacity; i++){
            data1[i]=data[i];
        }
        delete [] data;
        data=data1;
        capacity = capacity * 2;
    }
};

#endif
