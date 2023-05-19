#include <bits/stdc++.h>

using namespace std;


const int cnst = INT_MIN;


struct stData
{
    list<pair<int, int>> data;

    int sum = 0, counter = 0, max_p = cnst;


    stData() : data(), sum(sum), counter(counter), max_p(max_p) {}


    void add(int id, int pts)
    {
        data.emplace_back(id, pts);

        sum += pts;
        max_p = max(max_p, pts);
        counter += 1;
    }

    void del(int id)
    {
        counter -= 1;

        for (auto elem = data.begin(); elem != data.end(); ++elem)
        {
            if (elem->first == id)
            {
                data.erase(elem);

                sum -= elem->second;
                max_p = cnst;

                if (elem->second != max_p)
                {
                    return;
                }

                break;
            }
        }
    }
};


int main()
{
    int m, q;
    cin >> m >> q;

    int sum = 0, counter = 0, max_p = cnst;


    vector<stData> stD(m);
    vector<int> grSum(m);
    vector<int> grAm(m);

    for (int i = 0; i < m; ++i)
    {
        sum += stD[i].second;
    }


    for (size_t i = 0; i < q; ++i)
    {
        char param;
        cin >> param;

        if (param == 'a')
        {
            int group;
            cin >> group;

            int avg = stD[group - 1];
        }
    }


    return 0;
}
