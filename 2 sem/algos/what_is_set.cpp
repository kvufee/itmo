#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;

    const int c = INT_MAX;

    int first, second;
    int set1 = 0, set2 = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> first;
        set1 += first * INT_MAX;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> second;
        set2 += second * INT_MAX;
    }

    if (set1 == set2)
    {
        cout << "YES";
    } else cout << "NO";


    return 0;
}
