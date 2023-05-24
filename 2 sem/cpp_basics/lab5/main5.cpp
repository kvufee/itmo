#include "stack.h"

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
    Stack<int, 10> stack;

    try
    {
        stack.add(1);
        stack.add(5);
        stack.add(12);
        stack.add(-33);
        stack.add(-1);
        stack.add(11);

        stack.del();
        stack.del();
    } catch (const overflow_error& error)
    {
        cout << error.what() << "\n";
    } catch (const underflow_error& error)
    {
        cout << error.what() << "\n";
    }


    int a = 100, b = -3;
    auto minval = findMin(a, b);

    return 0;
}