#include <bits/stdc++.h>


std::vector <long long> left;
std::vector <long long> right;


void filling(int i, int* arr, int& count)
{
    if (left[i] != -1)
    {
        filling(left[i], arr, count);
        count++;
    }

    arr[i] = count;

    if (right[i] != -1)
    {
        count++;
        filling(right[i], arr, count);
    }
}


int main()
{   
    long long n;
    int current;
    std::cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> current;
        left.push_back(current - 1);

        std::cin >> current;
        right.push_back(current - 1);
    }

    int count = 1;

    filling(0, arr, count);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    
    return 0;
}