#include <iostream>

using namespace std;


template<class T>
class CBuffer
{
private:
    T *buffer;
    unsigned size;
    unsigned current_size;
    unsigned start;
    unsigned end_;
public:
    explicit CBuffer(unsigned capacity) :
            buffer(new T[capacity]),
            size(capacity),
            current_size(0),
            start(0),
            end_(0) {}

    ~CBuffer()
    {
        delete[] buffer;
    }

    unsigned nextIndex(unsigned index) const
    {
        return (index + 1) % size;
    }

    unsigned prevIndex(unsigned index) const
    {
        return (index + size - 1) % size;
    }

    bool isEmpty() const
    {
        if (current_size == 0)
        {
            cout << "Stack is empty";
            return current_size == 0;
        }
    }

    bool ifFull() const
    {
        if (current_size == size)
        {
            cout << "Stack is full";
            return current_size == size;
        }
    }

    void pushFront(const T &value)
    {
        if (current_size == size)
        {
            popBack();
        }

        start = (start + size - 1) % size;
        buffer[start] = value;
        current_size++;
    }

    void pushBack(const T &value)
    {
        if (current_size == size)
        {
            popFront();
        }

        buffer[end_] = value;
        end_ = (end_ + 1) % size;
        current_size++;
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "Buffer is empty\n";
            return;
        }


        start = (start + 1) % size;
        current_size--;
    }

    void popBack()
    {
        if (isEmpty())
        {
            cout << "Buffer is empty\n";
            return;
        }

        end_ = (end_ + size - 1) % size;
        current_size--;
    }

    void checkHead()
    {
        if (isEmpty())
        {
            cout << "Buffer is empty\n";
            return;
        }

        cout << buffer[start] << "\n";
    }

    void checkTail()
    {
        if (isEmpty())
        {
            cout << "Buffer is empty\n";
            return;
        }

        cout << buffer[end_ - 1] << "\n";
    }

    void checkSpecifiedPos(unsigned index)
    {
        if (index >= current_size)
        {
            cout << "Index out of range\n";
            return;
        }

        cout << buffer[(start + index) % size] << "\n";
    }

    void pushInSpecifiedPlace(unsigned index, const T &value)
    {
        if (index >= current_size)
        {
            cout << "Index out of range\n";
            return;
        }

        unsigned current = prevIndex(start) + index;

        if (current >= size)
        {
            current -= size;
        }

        if (current_size == size)
        {
            buffer[current] = value;
        }
        else
        {
            move_backward(buffer + current, buffer + prevIndex(end_), buffer + prevIndex(end_) + 1);
            buffer[current] = value;
            end_++;
            current_size++;
        }
    }

    void removeByIndex(unsigned index)
    {
        if (index >= current_size)
        {
            cout << "Index out of range\n";
            return;
        }

        unsigned current = prevIndex(start) + index;

        if (current >= size)
        {
            current -= size;
        }

        for (unsigned i = index + 1; i < current_size; i++)
        {
            unsigned next = prevIndex(start) + index;
            buffer[current] = buffer[next];
            current = next;
        }

        end_--;
        current_size--;
    }

    void resize(unsigned new_size)
    {
        T *new_buffer = new T[new_size];

        for (int i = 0; i < current_size; i++)
        {
            new_buffer[i] = buffer[(start + i) % size];
        }

        delete[] buffer;
        buffer = new_buffer;
        size = new_size;
        start = 0;

        if (size < end_)
        {
            end_ = size;
        }
    }

    typedef T *iterator;

    iterator begin()
    {
        return iterator(&buffer[start]);
    }

    iterator end()
    {
        return iterator(&buffer[(end_ - 1 + size) % size]);
    }
};