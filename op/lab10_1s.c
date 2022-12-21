#include <stdio.h>
#include <stdlib.h>


int sum(int num)
{
    if (num == 0) return 0;

    return num%10 + sum(num/10);
}


int main()
{
    puts("Task 3");
    int number;
    scanf("%d", &number);
    int digits[10];
    
    for (int i = 9; i >= 0; i--)
    {
        digits[i] = number % 10;
        number = number / 10;
    }
    
    for (int i = 0; i < 10; ++i)
    {
        if (digits[i] != 0)
            printf("%d ", digits[i]);
    }
    printf("\n");

    puts("Task 4");
    int num;
    scanf("%d", &number);

    printf("%d", sum(number));

    return 0;
}