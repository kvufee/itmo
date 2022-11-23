#include <stdio.h>
#include <string.h>


int main()
{
    //task 1//
    puts("Task 1");
    char s1[100];
    char s2[100];

    gets(s1, 100);
    char is1[100];
    memcpy(is1, s1, 100);

    gets(s2, 100);

    strcat(s1, s2);
    printf("%s \n \n", s1);

    memcpy(s1, is1, 100);


    //task 4//
    puts("Task 4");
    int count = 0, amount;
    scanf("%d", &amount);
    unsigned int len1 = strlen(s1);
    unsigned int len2 = strlen(s2);
    
    if (len1 < amount || len2 < amount)
    {
        printf("ERROR\n");
        return 0;
    }

    for (int i = 0; i < amount; ++i)
    {
        if (s1[i] == s2[i])
        {
            count += 1;
        }
    }

    if (amount == count)
    {
        printf("Correct\n");
    } else {
        printf("Incorrect\n");
    }
    printf("\n");


    //task 5//
    puts("Task 5");
    strcpy(s2, s1);
    printf("%s \n", s2);
    printf("\n");


    //task 8//
    puts("Task 8");
    char *reqch = strrchr(s1, 'c');

    if (reqch == NULL)
    {
        printf("ERROR");
    } else {
        printf("%ld", reqch - s1 + 1);
    }
    printf("\n \n");


    //task 11//
    puts("Task 11");
    char *istr;
    
    istr = strstr(s1, s2);

    if (istr == NULL)
    {
        printf("ERROR");
    } else {
        printf("%ld", istr - s1 + 1);
    }


    return 0;
}