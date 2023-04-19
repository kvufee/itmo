#include <bits/stdc++.h>

using namespace std;


int main()
{
    int large = INT_MAX;
    int n, k, v = 0;
    bool flag = true;

    cin >> n >> k;

    for (int i = n - 1; i >= 0; --i)
    {
        int n, m, counter = 1;
        cin >> n >> m;

        vector<tuple<int, int, int>> graph(m);
        vector<int> distance(n + 1, large);
        vector<int> ancestor(n + 1);
        vector<int> visList(n + 1, false);

        distance[1] = 0;

        for (int i = 0; i < m; ++i)
        {
            int first, second, weight;
            cin >> first >> second >> weight;

            graph[i] = make_tuple(first, second, weight);
        }


        for (int i = 0; i < n; ++i)
        {
            flag = false;

            for (int j = 0; j < m; ++j)
            {
                int first = get<0>(graph[j]);
                int second = get<1>(graph[j]);
                int weight = get<2>(graph[j]);

                if (distance[first] == large)
                {
                    continue;
                }

                if (distance[second] > weight + distance[first])
                {
                    distance[second] = weight + distance[first];
                    ancestor[second] = first;

                    if (i == n - 1)
                    {
                        v = second;
                    }

                    flag = true;
                }
            }

            if (!flag)
            {
                break;
            }

        }

        if (v == 0)
        {
            cout << "YES\n";
            continue;
        }

        visList[v] = ++counter;

        while (!visList[ancestor[v]])
        {
            visList[ancestor[v]] = ++counter;
            v = ancestor[v];
        }

        if (counter - visList[ancestor[v]] >= k)
        {
            cout << "NO\n";
        } else cout << "YES\n";
    }

    return 0;
}