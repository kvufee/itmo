#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, m;
    long long ans = 0;
    cin >> n >> m;

    vector<char> s(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    for (int i = 0; i < m; ++i)
    {
        bool flag = true;

        int first, second, size;
        cin >> first >> second >> size;

        --first;
        --second;

        for (int j = 0; j < size; ++j)
        {
            if (s[j + first] != s[j + second])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ++ans;
        }
    }

    cout << ans;

    return 0;
}