#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main()
{
    long long n;
    cin >> n;

    if (!n) cout << "YES";

    vector <long long> vectr(n);
    min(n, -10000), max(n, 100000);

    for (int i = 0; i < n; i++)
    {
        long long key, left, right;
        cin >> key >> left >> right;

        vectr[i] = key;
        if (max[i] <= vectr[i] || min[i] >= vectr[i])
            cout << "NO";
        
        if (left != 0)
        {
            max[left - 1] = ::min(max[i], key);
            min[left - 1] = min[i];
        }
        
        if (right != 0)
        {
            min[right - 1] = ::max(min[i], key);
            max[right - 1] = max[i];
        }
    }

    cout << "YES" << "\n";

    return 0;
}