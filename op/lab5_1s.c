#include <stdio.h>

int main()
{
    int arr[3][3] = {77, 12, 74, 34, 56, 78, 234, 678};
    
    printf("%d %d %d\n", arr[0][0], arr[0][1], arr[0][2]);
    printf("%d %d %d\n", arr[1][0], arr[1][1], arr[1][2]);
    printf("%d %d\n", arr[2][0], arr[2][1]);


    int mx1[2][2], mx2[2][2], res[2][2];
    
    printf("\nmx1 input");
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        {
            scanf("%d", &mx1[i][j]);
        }
    
    printf("\nmx2 input");
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            scanf("%d", &mx2[i][j]);
        }
    }
    
    printf("res mx");
    for(int i = 0; i < 2; ++i)    
    {    
        for(int j = 0; j < 2; ++j)    
        {    
            res[i][j] = 0;
            for(int k = 0; k < 2; ++k)    
            {
                res[i][j] += mx1[i][k] * mx2[k][j];    
            }    
        }    
    }   
    
    
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            printf("%d %d ", res[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}