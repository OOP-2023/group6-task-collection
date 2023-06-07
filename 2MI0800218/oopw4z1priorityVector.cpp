#include <iostream>

/// @brief ����, ����� ������������
/// ��������� �����
class vector {
public:
    /// @brief ������� ������ ��������� � capacity 8.
    vector() {
        data = new std::pair<int, int>[8];
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
        data = new std::pair<int, int>[argCap];
        size = 0;
        capacity = argCap;
    }

    /// @brief ������� ���������.
    /// @param argCap ���������� �� ����������.
    /// @param argDef ��������� �������� �� ������ ��������.
    vector(int argCap, std::pair<int, int> argDef) { // ������� ��������� � argCap �������� ���� ����� ������� � ����� �� argDef.
        data = new std::pair<int, int>[argCap];
        size = 0;
        capacity = argCap;

        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef;
        }
    }

    /// @brief ����� ����� �� ������ �������.
    /// @param  ��������� �� ����� ������ �� �����.
    std::pair<int, int> operator[](size_t index) const {
        return data[index];
    }

    /// @brief ����� ����� �� �������� ������� � ��������� ��������� ��.
    /// @param  ��������� �� ����� �� ����� ��� � ����� �� �����
    std::pair<int, int>& operator[](size_t index) {
        return data[index];
    }


    /// @brief ������ ������� � ����������.
    /// @param  ��������, ����� ��������.
    void push_back(std::pair<int, int> p) {
        if (size == capacity)
            resize();

        data[size] = p;
        size++;
    }

    /// @brief �������� ��������� ������� �� ����������
    /// @return ��������� ������� �� ����������
    std::pair<int, int> pop_back() {
        if (size == 0)
            return { INT_MIN, INT_MIN };

        size--;
        return data[size + 1];
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    ~vector() {
        free();
    }

private:
    std::pair<int, int>* data;       // < �������, � ����� ������ ������������
    size_t size;     // < ���� �������� � ����������
    size_t capacity; // < ����������� ���� ��������, ����� ���������� ��������

    /// @brief ������� �������
    void free() {
        delete[] data;
    }

    /// @brief ������ �����
    void copy(const vector& other) {
        data = new std::pair<int, int>[other.capacity];

        for (size_t i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }

        size = other.size;
        capacity = other.capacity;
    }

    /// @brief ������� ������� �� ������. 
    void resize() {
        std::pair<int, int>* nData = new std::pair<int, int>[capacity * 2];
        for (size_t i = 0; i < size; i++)
        {
            nData[i] = data[i];
        }

        capacity *= 2;
        free();
        data = nData;
    }
};

class priorityVector {
public:
        priorityVector() {
            v = vector();
        }

        priorityVector(const priorityVector& other) {
            v = vector(other.v);
        }

        priorityVector(priorityVector&& other) {
            v = other.v;
        }

        priorityVector(int argCap) {
            v = vector(argCap);
        }

        priorityVector(int argCap, const std::pair<int, int> argDef) {
            v = vector(argCap, argDef);
        }

        vector getVector(const priorityVector& pV) {
            return pV.v;
        }

        void swapPairs(std::pair<int, int>& p1, std::pair<int, int>& p2) {
            int temp = p1.first;
            p1.first = p2.first;
            p2.first = temp;
            temp = p1.second;
            p1.second = p2.second;
            p2.second = temp;
        }

		void enqueue(int elem, size_t rank) {
            v.push_back({ elem, rank });
            for (int i = v.getSize() - 1; i >= 1; i--)
            {
                if (v[i].second < v[i - 1].second)
                    swapPairs(v[i], v[i - 1]);
                else
                    break;
            }
		}

		int peak() const {
            return v[v.getSize() - 1].first;
		}

		int dequeue() {
            return v.pop_back().first;
		}

		private:
            vector v;
};

int main()
{
    
}
