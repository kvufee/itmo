#include "array.cpp"

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int arr[] {12, 35, 66, 223, -300, -22};
    cout << findMax<int, 6>(arr);

    Array <int, 5> data;
    data.add(5);
    data.add(-3);
    data.add(12);
    data.del();
    data.add(-222);
    data.sortArr();


    return 0;
}