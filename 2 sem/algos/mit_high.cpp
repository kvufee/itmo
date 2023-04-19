#include <bits/stdc++.h>

using namespace std;


void fw(vector<vector<int>> &graph, int n, int large)
{
    for (int u = 0; u < n; ++u)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (graph[i][u] != large && graph[u][j] != large)
                graph[i][j] = min(graph[i][j], graph[i][u] + graph[u][j]);
            }
        }
    }
}

int main()
{
    int large = INT_MAX;
    int n, m, max_length = 0;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, large));
    
    for (int i = 0; i < n; ++i)
    {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; ++i)
    {
        int first, second, time;
        cin >> first >> second >> time;

        graph[first - 1][second - 1] = time;
        graph[second - 1][first - 1] = time;

        assert(time >= 0);
    }

    fw(graph, n, large);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) 
        {
            if (graph[i][j] != large && i != j)
            {
                if (max_length < graph[i][j])
                {
                    max_length = graph[i][j];
                }
            }
        }
    }
    
    cout << max_length;

    return 0;
}