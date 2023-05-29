#include <bits/stdc++.h>

#include "buffer.tpp"
#include "buffer.hpp"

using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    CBuffer<int> c(4);
    c.pushFront(1);
    c.pushFront(2);
    c.pushFront(4);
    c.pushFront(3);
    cout << c[0] << c[1] << c[2] << c[3] << "\n";
    sort(c.begin(),c.end());
}