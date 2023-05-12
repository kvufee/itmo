#include <bits/stdc++.h>

using namespace std;


class invalidIndex : public exception
{
public:
    const char* error() const throw()
    {
        return "Element with given index doesn't exist";
    }
};

class arrayIsEmpty : public exception
{
public:
    const char* error() const throw()
    {
        return "Array is empty";
    }
};

class arrayOverflow : public exception
{
public:
    const char* error() const throw()
    {
        return "Array overflow";
    }
};

class negativeSizeOfArray : public exception
{
public:
    const char* error() const throw()
    {
        return "Size of array should be more than 0";
    }
};


template <typename T, int N>
T findMax(T arr[N])
{
    T ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }

    return ans;
}

