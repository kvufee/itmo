#include "stack.h"
#include "stack.cpp"

#include <bits/stdc++.h>

using namespace std;


template <typename T>
T findMin(T a, T b)
{
    if (a < b)
    {
        return a;
    } else return b;
}


int main()
{
    Stack<int, 5> stack;

    cout << "Enter stack elements: " << '\n';
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        stack.push(x);
    };

    for (int i = 0; i < 6; i++)
    {
        stack.pop();
    };

    return 0;
}