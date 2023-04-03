#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;


void dfs(vector<vector<int>>& adjList, vector<int>& visList, int node, int component)
{
    visList[node] = component;
    for (int neighbor : adjList[node])
    {
        if (visList[neighbor] == 0)
        {
            dfs(adjList, visList, neighbor, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int component = 0;

    vector<vector<int>> adjList(n + 1);
    vector<int> visList(n + 1);
    vector<int> traps(n + 1);
    vector<bool> isTrap(n + 1, true);

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
            dfs(adjList, visList, i, ++component);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> traps[i];
        isTrap[visList[i]] = !traps[i] && isTrap[visList[i]];
    }

    cout << component << "\n";

    for (int i = 1; i <= n; ++i)
    {
        cout << visList[i] << " ";
    }

    cout << "\n";

    for (int i = 1; i <= component; ++i)
    {
        cout << !isTrap[i] << " ";
    }

    return 0;
}