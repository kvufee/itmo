#include <bits/stdc++.h>

using namespace std;


void dfs(vector <vector <int>> &adjList, vector <int> &visList, int first, int link_comp)
{
    visList[first] = link_comp;

    for (int i = 0; i < adjList[first].size(); ++i)
    {
        int vis = adjList[first][i];

        if (!visList[vis])
        {
            dfs(adjList, visList, vis, link_comp);
        }
    }
}


int main()
{
    int n, m, link_comp = 0;
    bool trap;
    cin >> n >> m;

    vector <vector <int>> adjList(n + 1);
    vector <int> visList(n + 1);
    vector <int> trapList(n + 1);
    vector <bool> isTrap(link_comp + 1, true);


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
            dfs(adjList, visList, i, ++link_comp);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> trapList[i];
    }
    
    for (int i = 1; i <= n; ++i)
    {
        trap = 1 - trapList[i];
        
        isTrap[visList[i]] = trap && isTrap[visList[i]];
    }

    cout << link_comp << "\n";

    for (int i = 1; i <= n; ++i)
    {
        cout << visList[i] << " ";
    }

    cout << "\n";

    for (int i = 1; i <= link_comp; ++i)
    {
        trap = 1 - isTrap[i];
        cout << trap << " ";
    }

    return 0;
}