#include <bits/stdc++.h>

using namespace std;


class HT
{
    long long size;
    vector<list<long long>> hTable;

public:
    HT(long long TS) : size(TS)
    {
        hTable.resize(size);
    }

    long long hashFunc(long long temp) const
    {
        return temp % size;
    }

    void add(long long temp)
    {
        long long index = hashFunc(temp);
        hTable[index].push_back(temp);
    }

    long long equal(const HT& htTemp) const
    {
        long long flag = 0;

        if (size != htTemp.size)
        {
            return flag;
        }

        for (int i = 0; i < size; ++i)
        {
            if (hTable[i].size() != htTemp.hTable[i].size())
            {
                return flag;
            }

            for (int i = 0; i < hTable[i].size(); ++i)
            {
                bool fl = false;

                for (int j = 0; j < htTemp.hTable[i].size(); ++j)
                {
                    if (i == j)
                    {
                        fl = true;
                        break;
                    }
                }

                if (fl == false)
                {
                    return flag;
                }
            }
        }

        flag = 1;
        return flag;
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