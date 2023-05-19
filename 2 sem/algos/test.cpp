#include <bits/stdc++.h>

using namespace std;

const int cnst = INT_MIN;

struct stData
{
    list<pair<int, int>> data;

    int sum, counter, max_p;


    stData() : sum(0), counter(0), max_p(cnst), data(){}


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

                if (elem->second != max_p)
                {
                    return;
                }

                max_p = cnst;
                
                break;
            }
        }

        for (auto elem = data.begin(); elem != data.end(); ++elem)
        {
            max_p = max(max_p, elem->second);
        }
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, q;
    cin >> m >> q;


    vector<stData> stD(m);


    for (size_t i = 0; i < q; ++i)
    {
        char param;
        cin >> param;

        if (param == 'a')
        {
            int group;
            cin >> group;

            int index = group - 1;

            cout << stD[index].sum / stD[index].counter << "\n";
        }
        else if (param == '-')
        {
            int group, id;
            cin >> group >> id;

            int index = group - 1;

            stD[index].del(id);
        }
        else if (param == '+')
        {
            int group, id, pts;
            cin >> group >> id >> pts;

            int index = group - 1;

            stD[index].add(id, pts);
        }
        else
        {
            int group;
            cin >> group;

            int index = group - 1;

            cout << stD[index].max_p << "\n";
        }
    }

    return 0;
}
