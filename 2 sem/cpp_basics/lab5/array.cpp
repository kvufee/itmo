#include "arrayException.cpp"

#include <bits/stdc++.h>

using namespace std;


template <class T, int N>
class Array
{
public:
    Array()
    {
        if (N < 0)
        {
            throw negativeSizeOfArray();
        }

        n = N;
        arr = new T[n];
        index = -1;
        count = 0;
    }

    ~Array()
    {
        delete[] arr;
    }

    void add(T a)
    {
        if (count > N)
        {
            throw arrayOverflow();
        }

        ++index;
        arr[index] = a;

        ++count;
    }

    T del()
    {
        if (index == -1)
        {
            throw arrayIsEmpty();
        }

        --index;

        return arr[index + 1];
    }

    T sortArr()
    {
        if (index == -1)
        {
            throw arrayIsEmpty();
        }

        return sort(arr.begin(), arr.end());
    }

private:
    T arr;
    int count;
    int n;
    int index;
};
