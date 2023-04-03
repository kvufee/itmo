#include <bits/stdc++.h>

using namespace std;


void dfs(vector <vector <int>> &adjList, vector <bool> &visList, int first, vector <int> &tSort)
{
    visList[first] = true;

    for (int i = 0; i < adjList[first].size(); ++i)
    {
        int vis = adjList[first][i];

        if (!visList[vis])
        {
            dfs(adjList, visList, vis, tSort);
        }
    }

    tSort.push_back(first);
}


int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> adjList(n + 1);
    vector <bool> visList(n + 1);
    vector <int> tSort;
    vector <int> ans(n + 1);

    //adj
    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        adjList[first].push_back(second);
    }

    //vis
    for (int i = 1; i <= n; ++i)
    {
        if (!visList[i])
        {
            dfs(adjList, visList, i, tSort);
        }
    }

    reverse(tSort.begin(), tSort.end());

    for (int i = 1; i <= n; ++i)
    {
        ans[tSort[i - 1]] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}