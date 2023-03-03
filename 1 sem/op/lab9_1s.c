#include <stdio.h>


int main()
{
    //task 3
    puts("Task 3");
    int number;
    scanf("%d", &number);

    switch(number)
    {

        case 0:
            printf("Zero");
            break;

        case 1:
            printf("One");
            break;

        case 2:
            printf("Two");
            break;

        case 3:
            printf("Three");
            break;
        
        case 4:
            printf("Four");
            break;

        case 5:
            printf("Five");
            break;

        case 6:
            printf("Six");
            break;

        case 7:
            printf("Seven");
            break;

        case 8:
            printf("Eight");
            break;
        
        case 9:
            printf("Nine");
            break;

        default:
            printf("Incorrect");
            break;
    }
    printf("\n \n");


    //task 5
    puts("Task 5");
    int deposit, percent, month;
    scanf("%d %d %d", &deposit, &percent, &month);
    
    for (int i = 1; i < month + 1; ++i) 
    {
        deposit = deposit * (1 + percent/100);
        printf("%d", deposit);
        printf("\n");
    }

    return 0;
}