#ifndef VECTOR_HEADER
#define VECTOR_HEADER

using namespace std;

class vector {
public:
    vector()
    {
        size = 0;
        capacity = 8;
        data = new int [capacity];
    }

    vector(const vector &);
    vector(vector &&);
    vector &operator=(const vector &);

    vector(int argCap);
    {
        size=0;
        capacity = argCap;
        data = new int [capacity];
    }

    vector(int argCap, int argDef);
    {
        size = 0;
        capacity = argCap;
        data = new int [capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef;
        }
    }

    int operator[](size_t pos) const
    {
      return data[pos];
    }
    int &operator[](size_t pos)
    {
      return &operator = data[pos];
    }

    void push_back(int addedEl)
    {
            if(size < capacity){
                data[capacity+1] = addedEl;
                size+=1;
            }
            else{
                resize();
                data[capacity+1] = addedEl;
                size+=1;
            }
        
            data[capacity+1] = addedEl;
    }

    int pop_back()
    {
      int element = data[size];
      size-=1;
      return element;
    }
    ~vector();

private:
    int *data;      
    size_t size;     
    size_t capacity; 
    void free();
    void copy(const vector &);
    void resize();
};

void vector :: copy(const vector& that);
{
    this->size = that.size;
    this->capacity = that.capacity;
    this->data = new int [this->capacity];

    for (size_t i = 0; i < that.size; i ++){
        this->data[i] = that.data[i];
    }
}

void vector::free(){
    delete[] this->data;
}
vector :: vector(const vector& that){
         copy(that);
}

vector& vector::operator=(const vector& that){
    if(this != &that){
        free();
        copy(that);
    }
}
vector::vector(vector&& that){
    this->size = that.size;
    this->data = that.data;
    this->capacity = that.capacity;

    that.size = 0;
    that.capacity = 0;
    that.data = nullptr;
}
vector::~vector(){
    free();
}
void vector::resize(){
    if(this->size < this->capacity){
        return;
        }
        
        int newCapacity = this->capacity*2;
        int* newData = new int [newCapacity];
        for(int i =0; i < size; i++){
            newData[i] = this-> data[i];
        }
        
        free();

        this->data = newData;
        this->capacity = newCapacity;
    }
int main()
{
    vector x(vector());
   
}
#endif
