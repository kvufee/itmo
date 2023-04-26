#include <bits/stdc++.h>

using namespace std;


typedef struct
{
    int curr;
    int price;
} Edge;


bool dfs(vector <vector <Edge>> &adjList, vector <bool> &visList, vector <int> &balance, int first)
{
    visList[first] = true;

    for (int i = 0; i < adjList[first].size(); ++i)
    {
        int vis = adjList[first][i].curr;

        int price = adjList[first][i].price;
        balance[vis] = balance[first] + price;

        if (balance[vis] < 0)
        {
            return true;
        }
        else if (!visList[vis] && dfs(adjList, visList, balance, vis))
        {
            return true;
        } 
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector <Edge>> adjList(n+1);
    vector<bool> visList(n+1, false);
    vector<int> balance(n+1, 0);

    for (int i = 0; i < m; ++i)
    {
        int first, second, third;
        cin >> first >> second >> third;
        adjList[first].push_back({second, -third});
        adjList[second].push_back({first, third});
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visList[i] && dfs(adjList, visList, balance, i))
        {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}