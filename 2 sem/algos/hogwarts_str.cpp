#include <bits/stdc++.h>

using namespace std;


void prefixFunction(vector<int>& pref, string& s)
{
    int i = 1, j = 0;

    while (s.size() > i)
    {
        if (s[j] == s[i])
        {
            pref[i] = j + 1;
            ++i;
            ++j;
        }
        else
        {
            if (0 < j)
            {
                j = pref[j - 1];
            }
            else
            {
                ++i;
                pref[i] = 0;
            }
        }
    }

    for (int i = 0; i < pref.size(); ++i)
    {
        cout << pref[i] << " ";
    }
}

int main()
{
    string text;
    cin >> text;

    vector<int> pref(text.size());

    prefixFunction(pref, text);

    return 0;
}