#include <bits/stdc++.h>

using namespace std;


int main()
{
    int weight, amount;
    cin >> weight >> amount;

    int curr[amount + 1];
    int backpack[amount + 1][weight + 1];


    for (int i = 1; i <= amount; ++i)
        cin >> curr[i];

    for (int i = 0; i <= amount; ++i)
    {
        for (int j = 0; j <= weight; ++j)
        {
            backpack[i][j] = 0;
        }
    }

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 1; j <= weight; j++)
        {
            if (j >= curr[i])
            {
                backpack[i][j] = max(backpack[i - 1][j], backpack[i - 1][j - curr[i]] + curr[i]);
            }
            else
                backpack[i][j] = backpack[i-1][j];
        }
    }

    cout << backpack[amount][weight];

    return 0;
}