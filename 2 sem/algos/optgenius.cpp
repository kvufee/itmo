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
    int n, m, res = 0;
    cin >> n >> m;

    bool flag = false;

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


    return 0;
}