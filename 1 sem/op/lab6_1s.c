#include <stdio.h> 
#include <stdlib.h>

int main(void)
{ 
    int i;
    int arr[4] = {1000, 1001, 1002, 1003};
    
    int *ptr1 = arr;
    
    for (i = 0; i <=3; i++)
    { 
        printf("%d ", *ptr1++);
    }
    
    printf("\n");
    
    
    int *ptr2;
    ptr2 = (int *)malloc(4 * sizeof(int));
    
    for (i = 0; i < 4; ++i)
    {
        scanf("%d", &ptr2);
    }
    
    for (i = 0; i < 4; ++i)
    {
        printf("%d ", i, ptr2[i]);
    }
    
    
    return 0;
    
}