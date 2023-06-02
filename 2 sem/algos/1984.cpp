#include <bits/stdc++.h>

using namespace std;


void prefixFunction(vector<int>& pref, string& s)
{
    int i = 1, j = 0;

    while (i < s.size())
    {
        if (s[i] == s[j])
        {
        pref[i] = j + 1;
        ++i;
        ++j;
        }
        else
        {
        if (j > 0)
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
}


void KMP(vector<int>& pref, vector<int>& curr, const string& text, const string& pattern)
{
    int i = 0, j = 0;
    
    int n = text.size(); 
    int m = pattern.size();

    while (n > i)
    {
        if (pattern[j] == text[i])
        {
            ++i;
            ++j;
        }
        else
        {
            if (j > 0)
            {
                j = pref[j - 1];
            }
            else
            {
                ++i;
            }
        }
        if (m == j)
        {
            curr.push_back(i - m);
            j = pref[j - 1];
        }
    }
}

int main()
{
    string text, patt;
    cin >> text >> patt;

    vector<int> pref(patt.size() + 1);
    vector<int> curr;

    prefixFunction(pref, patt);
    KMP(pref, curr, text, patt);

    cout << curr.size() << "\n";

    for (int i = 0; i < curr.size(); ++i)
    {
        cout << curr[i] << " ";
    }

    return 0;
}