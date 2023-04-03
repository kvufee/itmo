#include <bits/stdc++.h>

using namespace std;

bool flag = false;


void dfs(vector <vector <int>> &adjList, vector <int> &visList, int first, int comp)
{
    visList[first] = comp;

    for (int i = 0; i < adjList[first].size(); ++i)
    {
        if (visList[i] == false)
        {
            dfs(adjList, visList, first, comp);
        }
    } 
}


int main()
{
    int n, m, comp = 0;
    cin >> n >> m;

    vector <vector <int>> adjList(n + 1);
    vector <int> visList(n + 1);
    vector <int> trapList(n + 1);
    vector <bool> isTrap(comp + 1, 0);

    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (visList[i] == 0)
        {
            dfs(adjList, visList, i, ++comp);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> trapList[i];
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (trapList[i] == 0)
        {
            isTrap[visList[i]] = isTrap[visList[i]] && (1 - trapList[i]) == 1;
        }
    }

    cout << comp << "\n";

    for (int i = 1; i <= n; ++i)
    {
        cout << visList[i] << " ";
    }

    cout << "\n";

    for (int i = 1; i <= comp; ++i)
    {
        cout << (1 - isTrap[i]) << " ";
    }

    return 0;
}
    