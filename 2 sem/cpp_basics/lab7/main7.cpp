#include <bits/stdc++.h>

#include "buffer.h"

using namespace std;


int main()
{
    CBuffer<int> c(4);
    c.pushFront(13);
    c.pushFront(2);
    c.pushFront(-3);
    c.pushFront(25);

    c.checkTail();

    return 0;
}