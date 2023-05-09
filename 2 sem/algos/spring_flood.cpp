#include <bits/stdc++.h>

using namespace std;


bool operator<(tuple<int, int, int>& tup1, tuple<int, int, int>& tup2)
{
    return get<2>(tup1) < get<2>(tup2);
}

int findParent(vector<int>& visList, int first)
{
    if (visList[first] == first)
    {
        return first;
    }
    
    return visList[first] = findParent(visList, visList[first]);
}

void merge(vector<int>& visList, vector<int>& priorList, int first, int second)
{
    first = findParent(visList, first);
    second = findParent(visList, second);

    if (first == second)
    {
        return;
    }

    if (priorList[first] < priorList[second])
    {
        swap(first, second);
    }

    visList[second] = first;

    if (priorList[first] == priorList[second])
    {
        ++priorList[first];
    }
}


int main()
{
    int n, m, result = 0;
    cin >> n >> m;

    vector<tuple<int, int, int>> graph(m);
    vector<int> visList(n + 1);
    vector<int> priorList(n + 1);
    
    for (int i = 0; i <= n; ++i)
    {
        visList[i] = i;
        priorList[i] = 1;
    }

    for (int i = 0; i < m; ++i)
    {
        int first, second, weight;
        cin >> first >> second >> weight;

        graph[i] = make_tuple(first, second, weight);
    }

    sort(graph.begin(), graph.end());

    for (int i = 0; i < m; ++i)
    {
        int first = get<0>(graph[i]);
        int second = get<1>(graph[i]);
        int weight = get<2>(graph[i]);

        if (findParent(visList, first) == findParent(visList, second))
        {
            continue;
        }

        merge(visList, priorList, first, second);

        result += weight;
    }

    cout << result;

    return 0;
}