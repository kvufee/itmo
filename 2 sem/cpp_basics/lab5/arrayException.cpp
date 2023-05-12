#include <bits/stdc++.h>

using namespace std;


class invalidIndex : public exception
{
public:
    const char* reason() const throw()
    {
        return "Element with given index doesn't exist";
    }
};

class arrayIsEmpty : public exception
{
public:
    const char* reason() const throw()
    {
        return "Array is empty";
    }
};

