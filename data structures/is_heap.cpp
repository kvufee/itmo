#include <iostream>
using namespace std;

int main()
{    
    int n;
    cin >> n;

    int *array = new int [n + 1];
    
    for (int i = 1; i < n + 1; ++i)
        cin >> array[i];
    
    for (int i = 1; i < n + 1; ++i) {
        if (2 * i <= n && array[i] > array[2 * i]) {
            cout << "NO\n";
            return 0;
        } else if (2 * i + 1 <= n && array[i] > array[2 * i + 1]) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    
    delete [] array;
    
    return 0;
}