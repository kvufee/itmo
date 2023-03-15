#include <bits/stdc++.h>

using namespace std;

bool flag = false;

void dfs(vector <vector <int>> &adjList, vector <bool> &visList, int first)
{
    visList[first] = 1;

    for (int i = 0; i < adjList[first].size(); ++i)
    {
        int vis = adjList[first][i];

        if (!visList[vis])
        {
            dfs(adjList, visList, vis);
        } 
    }
}


int main()
{
    int n, m;
    int cntr1 = 0, cntr2 = 0, deg = 0;
    cin >> n >> m;

    if (m < n - 1)
    {
        cout << "NO";
        return 0;
    }

    vector <vector <int>> adjList(n + 1);
    vector <bool> visList(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (adjList[i].size() > 2)
        {
            flag = 0;
        }
        else if (adjList[i].size() == 0)
        {
            flag = 0;
        }

        if (adjList[i].size() == 1)
        {
            cntr1++;
            deg = i;
        }
        else if (adjList[i].size() == 2)
        {
            cntr2++;
        }
    }

    if (cntr1 != 2) 
    {
        cout << "NO";
        return 0;
    } else if (cntr2 != n - 2)
    {
        cout << "NO";
        return 0;
    }

    dfs(adjList, visList, deg);

    for (int i = 1; i < n + 1; ++i)
    {
        if (!visList[i])
        cout << "NO";
        return 0;
    }

    cout << "YES";

    return 0;
}