#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, m, start, finish;
    cin >> n >> m;

    vector <vector <int>> adjList(n + 1);
    vector <int> lenght(n + 1, -1);
    queue <int> qq;

    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }

    cin >> start >> finish;

    lenght[start] = 0;

    qq.push(start);

    while (qq.size() != 0)
    {
        int vis = qq.front();
        qq.pop();

        for (int i = 0; i < adjList[vis].size(); ++i)
        {
            int curr = adjList[vis][i];

            if (lenght[curr] != -1) continue;

            lenght[curr] = lenght[vis] + 1;
            qq.push(curr);
        }
    }

    cout << lenght[finish];

    return 0;
}