#include <bits/stdc++.h>

using namespace std;


bool bfs(vector<vector<int>>& adjList, vector<int>& parList, int n)
{
    queue<int> qq;
    vector<bool> usedList(n + 1);

    qq.push(1);
    usedList[1] = true;
    parList[1] = -1;

    while (qq.empty() == false)
    {
        int vis = qq.front();
        qq.pop();

        for (int i = 0; i <= n; ++i)
        {
            if (usedList[i] == false && adjList[vis][i] > 0)
            {
                parList[i] = vis;

                if (i == n)
                {
                    return true;
                }

                qq.push(i);

                usedList[vis] = true;
            }
        }
    }
    return false;
}


int main()
{
    int n, m, res = 0;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1, vector<int>(n + 1));
    vector<int> visList(n + 1);
    vector<int> parList(n + 1);
    queue <int> qq;

    for (int i = 0; i < m; ++i)
    {
        int first, second, weight;
        cin >> first >> second >> weight;

        adjList[first][second] = weight;
    }

    while (bfs(adjList, parList, n) == true)
    {
        int k = INT_MAX;
        
        for (int v = n; v != 1; v = parList[v])
        {
            int u = parList[v];
            k = min(k, adjList[u][v]);
        }

        for (int v = n; v != 1; v = parList[v])
        {
            int u = parList[v];
            adjList[u][v] -= k;
            adjList[v][u] += k;
        }
        res += k;
    }

    cout << res;

    return 0;
}