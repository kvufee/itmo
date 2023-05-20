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

    long long hashFunc(long long temp)
    {   
        if (temp < 0)
        {
            return size - abs(temp);
        }

        return temp % size;
    }

    void add(long long temp)
    {
        long long index = hashFunc(temp);
        hTable[index].emplace_back(temp, 0);
    }

    
};
{
    vector<int> first;
    vector<int> second;

    int ans;

    chairs() : ans(0), first(), second() {}

    int calculate(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;

            if (tmp < i)
            {
                ans += first[i - tmp];
                ++first[i - tmp];
            }
            else
            {
                ans += second[tmp - i];
                ++second[tmp - i];
            }
        }

        return ans;
    }
};


int main()
{
    int n;
    cin >> n;



    return 0;
}

