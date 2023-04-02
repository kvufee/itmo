#include <bits/stdc++.h>

using namespace std;

bool flag = false;


void dfs(vector <vector <int>> &adjList, vector <int> &visList, vector <int> currentComponent, int first, int second, int comp)
{
    visList[first] = 1;
    currentComponent[first] = comp;

    for (int i = 0; i < adjList[first].size(); ++i)
    {
        int vis = adjList[first][i];
        if (visList[vis] == 0)
        {
            dfs(adjList, visList, currentComponent, vis, first, comp);
        } 
    }

    visList[first] = 2;
}


int main()
{
    int n, m, comp = 0;
    cin >> n >> m;

    vector <vector <int>> adjList(n + 1);
    vector <int> visList(n + 1);
    vector <bool> traps(n, false);
    vector <int> currentComponent(n, -1);

    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }
    
    for (int i = 1; i <= n; i++) {
        char t;
        cin >> t;
        if (t == '1') {
            traps[i] = true;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int counter = 0;
        if (visList[i] == 0)
        {
            dfs(adjList, visList, currentComponent, i, 0, comp);
            ++counter;
            ++comp;
        }
    }

    

    return 0;
}
    