#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, res = 0;
    cin >> n;

    vector<int> first(10000010);
    vector<int> second(10000010);

    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;

        if (input < i)
        {
            int temp1 = first[i - input];

            res += temp1;
            ++first[i - input];
        } else 
        {
            int temp2 = second[input - i];

            res += temp2;
            ++second[input - i];
        }
    }

    cout << res;

    return 0;
}

