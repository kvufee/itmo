#include <bits/stdc++.h>

using namespace std;


void fw(vector<vector<int>> &graph, int n, int large, int k)
{
    for (int u = 0; u < n; ++u)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (graph[i][u] != large 
                    && abs(i - u) <= k 
                    && graph[u][j] != large
                    && abs(u - j)<= k)
                graph[i][j] = min(graph[i][j], graph[i][u] + graph[u][j]);
            }
        }
    }
}

int main()
{
    int large = INT_MAX;
    int n, m, k, q;
    cin >> n >> m >> k;

    vector<vector<int>> graph(n, vector<int>(n, large));
    
    for (int i = 0; i < n; ++i)
    {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int first, second, time;
        cin >> first >> second >> time;

        graph[first - 1][second - 1] = time;

        assert(time >= 0);
    }

    fw(graph, n, large, k);

    cin >> q;

    for (int i = q - 1; i >= 0; --i)
    {
        int a, b;
        cin >> a >> b;

        --a;
        --b;

        if (graph[a][b] == large)
        {
            cout << "-1\n";
        } else cout << graph[a][b] << "\n";
    }

    return 0;
}