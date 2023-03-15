#include <bits/stdc++.h>

using namespace std;

bool flag = false;

void dfs(vector <vector <int>> &adjList, vector <int> &visList, int first, int second)
{
    visList[first] = 1;

    for (int i = 0; i < adjList[first].size(); ++i)
    {
        int vis = adjList[first][i];

        if (second != vis && visList[vis] == 1)
        {
            flag = true;
            return;
        }
        else if (visList[vis] == 0)
        {
            dfs(adjList, visList, vis, first);
        } 
    }

    visList[first] = 2;
}


int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> adjList(n + 1);
    vector <int> visList(n + 1);

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
            dfs(adjList, visList, i, 0);
        }
    }

    if (flag == true)
    {
        cout << "YES";
        return 0;
    } 
    
    cout << "NO";

    return 0;
}