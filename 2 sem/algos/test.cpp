#include <bits/stdc++.h>

using namespace std;


struct stData
{
    list<pair<int, int>> data;

    int sum, counter, max_p;


    stData() : data(), sum(0), counter(0), max_p(INT_MIN) {}


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

                max_p = INT_MIN;
                
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

            cout << stD[group - 1].sum / stD[group - 1].counter << "\n";
        }
        else if (param = '-')
        {
            int group, id;
            cin >> group >> id;

            stD[group - 1].del(id);
        }
        else if (param = '+')
        {
            int group, id, pts;
            cin >> group >> id >> pts;

            stD[group - 1].add(id, pts);
        }
        else if (param == 'm')
        {
            int group;
            cin >> group;

            cout << stD[group - 1].max_p << "\n";
        }
    }


    return 0;
}
