#include <iostream>
#include <assert.h>
#include <stdlib.h>

const int DEFAULT_CAP = 5;

class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(const DynamicArray & other);

    ~DynamicArray();      

    void assign(const DynamicArray & other);
    int  at(const int index) const { return m_data[index]; }
    int  getSize() const           { return m_size; }
    int  getCapacity() const       { return m_capacity; }
    void push(const int item);
    bool remove(const int item);

private:
    void resize();
    int  m_size;
    int  m_capacity;
    int* m_data;
};

DynamicArray::DynamicArray()
{
    m_capacity = DEFAULT_CAP;
    m_size     = 0;
    m_data     = new int[m_capacity];
}

DynamicArray::~DynamicArray()
{
    delete[] m_data;
}

DynamicArray::DynamicArray(const DynamicArray & other)
{
    this->m_size     = other.getSize();
    this->m_capacity = other.getCapacity();
    this->m_data     = new int[this->m_capacity];
    for (int i = 0; i < this->m_size; i++)
        m_data[i] = other.at(i);
}

void DynamicArray::assign(const DynamicArray & other)
{
    delete[] this->m_data; // delete default memory allocated for this
    this->m_size     = other.getSize();
    this->m_capacity = other.getCapacity();
    this->m_data     = new int[this->m_capacity];
    for (int i = 0; i < this->m_size; i++)
        m_data[i] = other.at(i);
}

void DynamicArray::push(const int item)
{
    m_data[m_size++] = item;
    if (m_size >= m_capacity)
        resize();
}

void DynamicArray::resize()
{
    std::cout << "(resize) from " << m_capacity << " to " << 2*m_capacity << std::endl;
    m_capacity *= 2;
    m_data = (int*)realloc(m_data, m_capacity * sizeof(int));
}

bool DynamicArray::remove(const int index)
{
    if (index < 0 || index >= m_size)
        return false;
    for (int i = index; i < m_size; i++)
        m_data[i] = m_data[i + 1];
    m_size--;
    return true;
}

int main()
{
    int tcase;
    std::cin >> tcase;
    DynamicArray arr;
    switch (tcase)
    {
    // array constructor
    case 1:
    {
        assert(arr.getSize() == 0 && arr.getCapacity() == 5);
        break;        
    }
    // array push, no resize
    case 2:
    {
        for (int i = 0; i < 3; i++)
            arr.push(i);
        assert(arr.getSize() == 3 && arr.getCapacity() == 5 && arr.at(2) == 2);   
        break;    
    }
    // array push, with resizing
    case 3:
    {
        for (int i = 0; i < 8; i++)
            arr.push(i);
        assert(arr.getSize() == 8 && arr.getCapacity() == 10 && arr.at(7) == 7);   
        break;
    }
    // copy constructor
    case 4:
    {
        for (int i = 0; i < 3; i++)
            arr.push(i);
        DynamicArray b(arr);
        assert(b.getSize() == 3 && b.getCapacity() == arr.getCapacity() && b.at(2) == 2);  
        break;
    }
    // assign
    case 5:
    {
        for (int i = 0; i < 3; i++)
            arr.push(i);
        DynamicArray b;
        b.assign(arr);
        assert(b.getSize() == 3 && b.getCapacity() == arr.getCapacity() && b.at(2) == 2);  
        break;
    }
    // assign & copy constructor
    case 6:
    {
        DynamicArray b, c;
        for (int i = 0; i < 4; i++)
            b.push(4*i);
        DynamicArray d(b);
        c.assign(b);
        assert( c.getSize() == 4 && d.getSize() == 4 );
        assert( c.getCapacity() == 5 && d.getCapacity() == 5 );
        for ( int i = 0; i < c.getSize(); ++i )
        {
            assert(b.at(i) == c.at(i) && b.at(i) == d.at(i));
        }
    }
    // push and remove, without resizing
    case 7:
    {
        for (int i = 0; i < 4; i++)
            arr.push(i);
        assert(arr.getSize() == 4 && arr.getCapacity() == 5 && arr.at(2) == 2);   
        arr.remove(2);
        assert(arr.getSize() == 3 && arr.getCapacity() == 5);
        assert(arr.at(0) == 0 && arr.at(1) == 1 && arr.at(2) == 3);
        break;
    }
    // push and remove, with resizing
    case 8:
    {
        for (int i = 0; i < 8; i++)
            arr.push(i);
        assert(arr.getSize() == 8 && arr.getCapacity() == 10 && arr.at(6) == 6);   
        arr.remove(2);
        assert(arr.getSize() == 7 && arr.getCapacity() == 10);
        assert(arr.at(0) == 0 && arr.at(1) == 1 && arr.at(2) == 3 && arr.at(6) == 7);
        break;
    }
    // multi-resizing & multi-deletions
    case 9:
    {
        for (int i = 0; i < 23; i++)
            arr.push(100 - i);

        assert(arr.getSize() == 23 && arr.getCapacity() == 40);
        assert(arr.at(15) == 85 && arr.at(21) == 79); 

        arr.remove(15);
        arr.remove(0);
        assert(arr.getSize() == 21 && arr.getCapacity() == 40);
        assert(arr.at(0) == 99 && arr.at(20) == 78);
        break;
    }
    // all operations
    case 10:
    {

        for (int i = 0; i < 100; i++)
            arr.push(i+1);
        assert(arr.getSize() == 100 && arr.getCapacity() == 160);
        int sum = 0;   
        for (int i = 0; i < arr.getSize(); i++)
            sum += arr.at(i);
        assert(sum == 5050);
        arr.remove(0);
        arr.remove(98);
        assert(arr.getSize() == 98 && arr.getCapacity() == 160);
        int sum2 = 0;   
        for (int i = 0; i < arr.getSize(); i++)
            sum2 += arr.at(i);
        assert(sum2 == 4949);
        break;
    }
    default:
        break;
    }
    std::cout << tcase << std::endl;
}



