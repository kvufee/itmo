#include <stdio.h>

static unsigned int k = 0;

void arrayOfDigits(int *arr, int n)
{
    int i = 0;
    while (n > 0)
    {
        arr[i++] = n % 10;
        n /= 10;
        k++;
    }
    arr[i] = -1;
}


void extraSpaces(char *str, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if(str[i])
            {
                str[i] = str[i+k];
        
                if(str[i] == ' ')
                {
                    k++;
                    i--;
                }

                i++;

                extraSpaces(str, n);
            }
    }
}


int main()
{
    puts("Task 3");

    int arr[256];
    int n;

    scanf("%d", &n);

    arrayOfDigits(arr, n);

    for (int i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
    }
       

    puts("Task 5");

    char str[100];

    

    return 0;
}