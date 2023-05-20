#include <bits/stdc++.h>

using namespace std;


struct chairs
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

            if (i > tmp)
            {
                ans += first[i - tmp];
                first[i - tmp]++;
            }
            else
            {
                ans += second[tmp - i];
                second[tmp - i]++;
            }
        }

        return ans;
    }
};


int main()
{


    return 0;
}

