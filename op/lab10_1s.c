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


char * delete_space(char *string, int length) {
    char *new_string = malloc(sizeof(char) * length);
    int index = 0;
    for (int i = 0; i < length + 1; i++) {
        if (string[i] == ' ' && string[i-1] == ' ') {
            continue;
        }
        else if ((string[i-1] == '(' || string[i-1] == '{' || string[i-1] == '[' || string[i-1] == '"') && string[i] == ' ') {
            continue;
        }
        else if (string[i-1] == '.' && string[i] == ' ') {
            continue;
        }
        else {
            new_string[index] = string[i];
            index++;
        }
    }
    new_string[index] = '\0';
    return new_string;
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