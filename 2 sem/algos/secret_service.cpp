#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    cin.ignore(1);

    for (int i = 0; i < m; ++i)
    {
        bool flag = true;

        string s;
        getline(cin, s);

        regex rx("^([A-Z][a-z]* ){3}[0-9]{2} ([+]7|[7,8])[(]?[0-9]{3}[)]?[-]?[0-9]{3}[-]?[0-9]{2}[-]?[0-9]{2} g.[A-Z]{3}, ul.[A-Z][a-z]*, d.[0-9]{2,}$");
        
        if (regex_match(s, rx))
        {
            flag = true;
        }
        else
        {
            flag = false;
        }

        if (flag)
        {
            cout << "YES\n";
        } else
        {
            cout << "NO\n";
        }
    }

  return 0;
}