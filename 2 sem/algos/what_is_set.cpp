#include <bits/stdc++.h>

using namespace std;


bool areSetsEqual(const vector<int>& set1, const vector<int>& set2)
{
    if (set1.size() != set2.size())
    {
        return false;
    }

    for (int i = 0; i < set1.size(); ++i)
    {
        if (set1[i] != set2[i])
        {
            return false;
        }
    }

    return true;
}


int main()
{
    int n;
    cin >> n;

    vector<int> set1(n + 1);
    vector<int> set2(n + 1);

    for (int i = 0; i < n; ++i)
    {
        cin >> set1[i];
    }


    for (int i = 0; i < n; ++i)
    {
        cin >> set2[i];
    }

    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    if (areSetsEqual(set1, set2))
    {
        cout << "YES" << "\n";
    } else
    {
        cout << "NO" << "\n";
    }

    return 0;
}
