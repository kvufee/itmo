#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, m, start, finish;
    cin >> n >> m;
    vector <vector <int>> g(n + 1);
    vector <int> lenght(n + 1, -1);
    queue <int> qq;

    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        g[first].push_back(second);
        g[second].push_back(first);
    }

    cin >> start >> finish;

    lenght[start] = 0;

    qq.push(start);
    while (qq.size() >= 1)
    {
        int vis = qq.front();
        qq.pop();
        for (auto& curr : g[vis])
        {
            if (lenght[curr] == -1)
            {
                return cout << -1, 0;
            }
            else
            {
                lenght[curr] = lenght[vis] + 1;
                qq.push(curr);
            }
        }
    }

    cout << lenght[finish];

    return 0;
}