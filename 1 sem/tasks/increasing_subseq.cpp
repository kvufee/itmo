#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n + 1], prev[n + 1], curr[n + 1];
    int length = 0, rcvr_counter = 0;

    for (int i = 1; i <= n; ++i)
        cin >> arr[i];


    for (int i = 0; i <= n; ++i)
    {   
        prev[i] = 0;
        curr[i] = 1;
    }

    curr[0] = 0;
    prev[1] = -1;

    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j] && curr[i] < curr[j] + 1)
            {
                curr[i] = curr[j] + 1;
                prev[i] = j;

                if (length < curr[i])
                    rcvr_counter = i;

                length = max(length, curr[i]);
            }
        }
    }

    cout << length << "\n";
    int p = rcvr_counter, j = 0;
    int answer[length];

    while (p != 0)
    {
        answer[j++] = arr[p];
        p = prev[p];
    }

    for (int i = length - 1; i >= 0; --i)
        cout << answer[i] << " ";

    return 0;
}