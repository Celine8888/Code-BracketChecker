// Implement a stack based on an array.
#ifndef DSSTACK_H
#define DSSTACK_H

#include <iostream>

using namespace std;

template <typename Object>
class DSStack
{
private:
    int size;
    int capacity;
    Object *array;

public:
    DSStack()
    {
        size = 0;
        capacity = 1;
        array = new Object[capacity];
    }
    DSStack(int capacity)
    {
        this.capacity = capacity;
        array = new Object[capacity];
        size = 0;
    }
    ~DSStack()
    {
        delete[] array;
    }
    DSStack(const DSStack &rhs)
    {
        size = rhs.size;
        capacity = rhs.capacity;
        array = new Object[capacity];
        for (int i = 0; i < size; i++)
        {
            array[i] = rhs.array[i];
        }
    }
    DSStack &operator=(const DSStack &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        delete[] array;
        size = rhs.size;
        capacity = rhs.capacity;
        array = new Object[capacity];
        for (int i = 0; i < size; i++)
        {
            array[i] = rhs.array[i];
        }
        return *this;
    }

    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }

    bool empty() const
    {
        return (size == 0);
    }

    void clear()
    {
        delete[] array;
        size = 0;
        capacity = 1;
        array = new Object[1];
    }

    int find(const Object obj) const
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == obj)
            {
                return i;
            }
        }
        cout << obj << " is not found";
        return -1;
    }

    void push_back(const Object obj)
    {
        if (capacity == size)
        {
            Object *temp = array;
            capacity = capacity * 2;
            array = new Object[capacity];
            for (int i = 0; i < size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;
        }
        array[size] = obj;
        size++;
    }
    void push_front(const Object obj)
    {
        if (capacity == size)
        {
            Object *temp = array;
            capacity = capacity * 2;
            array = new Object[capacity];
            for (int i = 0; i < size; i++)
            {
                array[i + 1] = temp[i];
            }
            delete[] temp;
        }
        else
        {
            Object *temp = array;
            array = new Object[capacity];
            for (int i = 0; i < size; i++)
            {
                array[i + 1] = temp[i];
            }
            delete[] temp;
        }
        array[0] = obj;
        size++;
    }
    void pop_back()
    {
        if (size == 0)
        {
            cout << "Stack underflow\n";
        }
        else
        {
            size = size - 1;
        }
    }
    void display() const
    {
        cout << "List content: \n";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << '\n';
        }
    }
    Object top() const
    {
        return array[size - 1];
    }
};
#endif