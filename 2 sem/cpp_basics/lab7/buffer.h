#include <bits/stdc++.h>

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
    class Iterator : public iterator<random_access_iterator_tag, T>
    {
    private:
        T *s;
    public:
        Iterator(T *data)
        {
            s = data;
        }

        Iterator operator+(int x)
        {
            return Iterator(s+x);
        }

        T  operator-(CBuffer buf)
        {
            return s - buf.s;
        }

        Iterator operator-(int x)
        {
            return Iterator(s-x);
        }

        Iterator &operator+=(int x)
        {
            s += x;

            return *this;
        }

        Iterator &operator-=(T x)
        {
            s -= x;

            return *this;
        }

        Iterator &operator++()
        {
            ++s;

            return *this;
        }

        Iterator &operator--()
        {
            --s;

            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp = *this;

            ++(*this);

            return tmp;
        }

        Iterator operator--(T)
        {
            Iterator t(*this);

            --s;

            return t;
        }


        T &operator*() const
        {
            return *s;
        }

        T *operator->() const
        {
            return *s;
        }

        T &operator[](const int x)
        {
            return s[x];
        }

        bool operator==(const Iterator &x) const
        {
            return x.s == s;
        }

        bool operator!=(const Iterator &x) const
        {
            return x.s != s;
        }

        bool operator<(const Iterator &x) const
        {
            return x.s < this->s;
        }

        bool operator>(const Iterator &x) const
        {
            return x.s > this->s;
        }

        bool operator<=(const Iterator &x) const
        {
            return x.s <= this->s;
        }

        bool operator>=(const Iterator &x) const
        {
            return x.s >= this->s;
        }

        T operator-(const Iterator &x)
        {
            return (s - x.s);
        }

        Iterator operator+(const Iterator &x)
        {
            return (s + x.s);
        }
    };


    CBuffer(unsigned capacity) :
            buffer(new T[capacity]),
            size(capacity),
            current_size(0),
            start(0),
            end_(0) {}

    ~CBuffer()
    {
        delete[] buffer;
    }

    Iterator begin() const
    {
        return Iterator(buffer + start);
    }

    Iterator end() const
    {
        return Iterator(buffer + end_);
    }

    T operator[](int id)
    {
        return buffer[id % size];
    }

    void popFront()
    {
        buffer[start] = 0;
        ++start;
    }

    void pushBack(const T &x)
    {
        if (end_ == size)
        {
            --end_;
        }

        if (end_ == size + 1)
        {
            end_ -= 2;
        }

        buffer[end_] = x;

        if (end_ != size + 1)
        {
            ++end_;
        }
    }

    void popBack()
    {
        buffer[end_] = 0;
        --end_;
    }

    void pushInSpecifiedPlace(Iterator curr, T val)
    {
        for(auto i = Iterator(buffer + end_); i != curr - 1; --i)
        {
            *(i + 1) = *i;
        }
        *curr = val;
    }

    void removeByIndex(Iterator curr, T val)
    {
        for(auto i = curr; i != Iterator(buffer + start) - 1; ++i)
        {
            *(i + 1) = *i;
        }

        *curr = val;
    }

    void resize(const int &n)
    {
        T *tmp = new T[n];

        for (int i = 0; i < n; ++i)
        {
            tmp[i] = i < size ? buffer[i] : 0;
        }

        delete[] buffer;
        buffer = tmp;
        size = n;
    }

    void pushFront(const T &x)
    {
        if (end_ == size)
        {
            buffer[start] = x;

            return;
        }

        for(int i = end_; i >= start; --i)
        {
            buffer[i + 1] = buffer[i];
        }

        buffer[start] = x;

        ++end_;

        return;
    }
};