#include <iostream>
#include <vector>

using namespace std;


int main()
{
    long long n, maxel = 0;
    
    cin >> n;

    if (!n) cout << 0;
    
    vector <long long> vectr(n);

    for (int i = 0; i < n; ++i)
    {
        long long key, left, right;
        cin >> key >> left >> right;

        if (left != 0)
            vectr[left - 1] = vectr[i] + 1;

        if (right != 0)
            vectr[right - 1] = vectr[i] + 1;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (vectr[i] > maxel)
            maxel = vectr[i];
    }


    cout << maxel + 1;


    return 0;
}