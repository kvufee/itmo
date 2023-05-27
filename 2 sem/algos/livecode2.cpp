#include <bits/stdc++.h>

using namespace std;


string restoreString(vector<int>& prefix, int n)
{
    string s(n, 'a');


    for (int i = 1; i < n; ++i)
    {
        int j = prefix[i - 1];

        while (j > 0 && s[i] != s[j])
        {
            j = prefix[j - 1];
        }

        if (s[i] == s[j])
        {
            ++s[i];
        }

        prefix[i] = j;
    }

    return s;
}


int main()
{
    int n;
    cin >> n;

    vector<int> prefix(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> prefix[i];
    }

    string restoredString = restoreString(prefix, n);
    cout << restoredString;

    return 0;
}