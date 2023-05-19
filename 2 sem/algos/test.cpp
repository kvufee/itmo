#include <bits/stdc++.h>

using namespace std;

struct stData
{
    long long id;
    long long points;
    long long group;
    long long counter;
    long long sum;
    long long max_p;

    stData(long long id, long long points, long long group,
           long long counter, long long sum, long long max_p) :
            id(id), points(points), group(group),
            counter(counter), sum(sum), max_p(max_p) {}
};

class HT
{
    long long size;
    vector<stData> hTable;

public:
    HT(long long TS) : size(TS)
    {
        hTable.resize(size);
    }

    long long hashFunc(long long temp) const
    {
        return temp % size;
    }

    void add(long long& group, long long& id, long long& points)
    {
        long long index = hashFunc(id);
        hTable[index].emplace_back(group, id, points);
    }

    void del();

    long long avg(const HT& htTemp) const
    {
        
    }
};


int main()
{
    int n;
    cin >> n;

    HT set1(n + 1);
    HT set2(n + 1);

    long long first, second;

    for (int i = 0; i < n; ++i)
    {
        cin >> first;
        set1.add(first);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> second;
        set2.add(second);
    }

    if (set1.equal(set2) == 1)
    {
        cout << "YES";
    } else cout << "NO";


    return 0;
}
