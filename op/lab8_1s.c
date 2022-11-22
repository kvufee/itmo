#include <stdio.h>
#include <string.h>


int main()
{
    //task 1
    char s1[100];
    char s2[100];

    gets_s(s1, 100);
    char is1[100];
    memcpy(is1, s1, 100);

    gets_s(s2, 100);

    strcat(strcat(s1, " "), s2);
    printf("%s \n \n", s1);

    memcpy(s1, is1, 100);


    //task 4
    int count = 0, amount;
    scanf("%d", &amount);
    unsigned int len1 = strlen(s1);
    unsigned int len2 = strlen(s2);
    
    if (len1 < amount || len2 < amount)
    {
        printf("ERROR");
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
        printf("Correct");
    } else 
        printf("Incorrect");


    //task 9
    char *reqch = strrchr(s2, 'a');

    if (reqch == NULL)
    {
        printf("ERROR");
    } else {
        printf("%d", reqch - s2 + 1);
    }

    return 0;
}