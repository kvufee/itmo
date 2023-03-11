#include <bits/stdc++.h>

using namespace std;

void dfs(vector <vector <long long>> &adjList, vector <long long> &visList, long long first, long long second)
{
    visList[first] = 1;
    bool flag = false;

    for (int i = 0; i < adjList.size(); ++i)
    {
        if (visList[i] == 0)
        {
            dfs(adjList, visList, i, first);
        } 
        else if (visList[i] == 1 && first != second)
        {
            flag = true;
        }
    }

    visList[first] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool flag = false;

    long long n, m, first, second;
    cin >> n >> m;

    vector <vector <long long>> adjList(n);
    vector <long long> visList(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> first >> second;
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }

    for (int i = 0; i < n; ++i)
    {
        if (visList[i] == 0)
        {
            dfs(adjList, visList, i, first);
        }
    }

    if (flag == true)
    {
        cout << "YES";
    } else cout << "NO";

    return 0;
}