#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, find_max;
    cin >> n;

    vector<pair<int, int>> vectr(n + 1);
    vector<int> ansVector(n + 1);
    vector<int> result(n);

    for (int i = 1; i <= n; ++i)
    {
        int key, left, right;
        cin >> key >> vectr[i].first >> vectr[i].second;
    }

    for (int i = n; i > 0; --i)
    {   
        find_max = ((ansVector[vectr[i].first] < ansVector[vectr[i].second]) ? ansVector[vectr[i].second] : ansVector[vectr[i].first]);
        ansVector[i] = find_max + 1;
    }

    for (int i = 1; i <= n; ++i)
    {   
        result[i] = ansVector[vectr[i].second] - ansVector[vectr[i].first];
        cout << result[i] << "\n";
    }
    
    return 0;
}