#include <iostream>
using namespace std;

void siftdown(int * arr, int n, int i)
{
    int min = i;
    if (2 * i + 1 < n && arr[min] < arr[2 * i + 1]) {
        min = 2 * i + 1;
    }

    if (2 * i + 2 < n && arr[min] < arr[2 * i + 2]) {
        min = 2 * i + 2;
    }

    if (i != min) {
        swap(arr[i], arr[min]);
        siftdown(arr, n, min);
    }
}


void buildheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i) {
        siftdown(arr, n, i);
    }
}


void heapsort(int arr[], int n)
{
    buildheap(arr, n);
    
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);

        siftdown(arr, i, 0);
    }
}


int main()
{
    int n, arr[n];

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    heapsort(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}