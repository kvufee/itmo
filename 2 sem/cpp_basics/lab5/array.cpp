#include <bits/stdc++.h>

using namespace std;


template <class T, int n>
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