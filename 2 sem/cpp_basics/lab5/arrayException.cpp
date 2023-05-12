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


template <typename T, int n>
T findMax(T arr[n])
{
    T ans = 0;
    for (int i : arr)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }

    return ans;
}

