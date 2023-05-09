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
        qq.pop();

        for (int i = 0; i <= n; ++i)
        {
            if (usedList[i] == false && adjList[qq.front()][i] > 0)
            {
                parList[i] = qq.front();

                if (i == n)
                {
                    return true;
                }

                qq.push(i);

                usedList[qq.front()] = true;
            }
        }
    }

    return false;
}


int main()
{
    int n, m, k = 1e9, res = 0;
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
        for (int i = n; i != 1; i = parList[i])
        {
            int j = parList[i];
            k = min(k, adjList[j][i]);
        }

        for (int i = n; i != 1; i = parList[i])
        {
            int j = parList[i];
            adjList[j][i] -= k;
            adjList[i][j] += k;
        }
        res += k;
    }

    cout << res;

    return 0;
}