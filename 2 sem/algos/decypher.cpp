#include <bits/stdc++.h>

using namespace std;

void parser(vector<pair<char, int>>& data, int n)
{
    string row(n, ' ');

    for (int i = 0; i < n; ++i)
    {
        cin >> row[i];
    }

    int i = 0;

    while (i < n)
    {
        int j = i;
        int number = 0;
        while (i + 1 < n && row[i + 1] >= '0' && row[i + 1] <= '9')
        {
            number *= 10;
            number += (row[i + 1] - '0');
            i++;
        }  
        data.emplace_back(row[j], number);
        ++i;
    }
}

int main()
{
    int first, second, diff;
    cin >> first >> second >> diff;

    int counter = 0;

    vector <pair<char, int>> masha;
    vector <pair<char, int>> sasha;

    int i = 0, j = 0;

    if (first > second)
    {
        parser(sasha, first);
        parser(masha, second);
        swap(first, second);
    }

    while (i < masha.size() && j < sasha.size())
    {
        if (masha[i].first != sasha[j].first)
        {
            counter += min(masha[i].second, sasha[j].second);
        }

        if (masha[i].second < sasha[j].second)
        {
            sasha[j].second -= masha[i].second;
            ++i;
        }
        else if (masha[i].second > sasha[j].second)
        {
            masha[i].second -= sasha[j].second;
            ++j;
        } else {
            ++i;
            ++j;
        }
    }

    if (counter < diff)
    {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}