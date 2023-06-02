#include <bits/stdc++.h>

#include "buffer.h"

using namespace std;


int main()
{
    CBuffer<int> c(4);

    c.pushBack(13);
    c.pushBack(2);
    c.pushBack(-3);
    c.pushBack(25);

    for (auto i : c)
    {
        cout << i << " ";
    }

    cout << "\n";

    sort(c.begin(), c.end());

    for (auto i : c)
    {
        cout << i << " ";
    }

    cout << "\n";

    c.popBack();

    for (auto i : c)
    {
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}