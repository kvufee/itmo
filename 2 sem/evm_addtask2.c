#include <stdio.h>


int main()
{
    FILE *file = fopen("evm2.txt", "r+b");

    int arr[1000];
    int tenItems[10];
    int num, element = 0, counter = 0;

    while (fscanf(file, "%d", &num) == 1 && element < 1000)
    {
        arr[element] = num;
        element++;
        counter++;
    }

    for (int j = 0; j < element; j++)
    {
        printf("%d ", arr[j]);
    }

    printf("\namount: ");
    printf("%d", counter);
    printf("\n");

    __asm__(
            "movq %0, %%r8 \n\t"
            "movq $0, %%r9 \n\t"
            "movq $0, %%rcx \n\t"
            "movq $0, %%rbx \n\t"

            "movq %0, %%r8 \n\t" // r8 == arr
            "movl %1, %%ecx \n\t" // ecx == counter
            "dec %%ecx \n\t"
            "leaq (%%r8, %%rcx, 4), %%rbx \n\t" // адрес указывает на конец массива
            "movq %%rbx, %%r8 \n\t" // рбх в р8
            "movq $0, %%rcx \n\t" //обнуляю рсх
            "movq %r8, %%rax \n\t" // адрес из р8 в рах
            "movl $9, %%ecx \n\t" // записываю в есх значение 9
            "leaq (%%rax, %%rcx,4), %%rbx \n\t" // адрес указывает на конец массива
            "movq %%rbx, %%rax \n\t" //
            "movq $0, %%rcx \n\t"
            "movl $10, %%ecx \n\t"  // если ecx ==

            "write: \n\t"
            "movl (%%r8), %%r9d \n\t"
            "movl %%r9d, (%%rax) \n\t"
            "subq $4, %%r8 \n\t"
            "subq $4, %%rax \n\t"

            "writeInLoop: \n\t"
            :
            :"D"(arr), "p"(counter), "a"(tenItems)
            :"%rbx", "%rcx", "r8", "r9", "r10");


    for (int j = 0; j < element; j++)
    {
        printf("%d ", arr[j]);
    }

    for (int i = 0; i < counter; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);


    return 0;
}