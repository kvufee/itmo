#include <stdio.h>


int main()
{
    FILE *file = fopen("evm2.txt", "r+b");

    int arr[1000];
    int topTen[10];
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
            "movq %0, %%r8 \n\t"        // запись переменной р8 (массив арр)
            "movq $0, %%r9 \n\t"        // запись переменной р9. р9 = 0

            "loopSecond : \n\t"         // цикл для завершения
            "cmpl %%r9d, %1 \n\t"       // если р9 == counter тогда
            "je break \n\t"             // переход в метку break :
            "movq $0, %%r10 \n\t"       // запись переменной р10. р10 = 0
            "movq $0, %%rax \n\t"       // запись переменной рах. рах = 0
            "movq %%r8, %%rax \n\t"     // значение р8 записывается в регистр данных
            "movl %%r9d, %%r10d \n\t"   // значение р9 записывается в р10. буква д для 32бит регистра числа.
            "jmp loopFirst \n\t"        // переход в первый цикл

            "loopFirst :\n\t"
            "cmpl $0, %%r10d \n\t"      // если р10 = 0,
            "je iterSecond \n\t"        // то переход на метку вторая итерация
            "jmp comp \n\t"             // иначе безусловный переход на comp

            "comp: \n\t"
            "movq $0, %%rbx \n\t"       // rbx = 0
            "movq $0, %%rcx \n\t"       // rcx = 0
            "movq $0, %%rdx \n\t"       // rdx = 0
            "lea -4(%%rax), %%rbx \n\t" // загрузка адреса в регистр рбх. вычисление адреса на 4 бита влево от rax
            "movl (%%rbx), %%ecx\n\t"   // запись из рбх в есх. смещение 32бит значение в регистр
            "movl (%%rax), %%edx \n\t"  // то же самое
            "cmpl %%edx, %%ecx \n\t"    // сравнение значений едх и есх
            "jl swap \n\t"              // функция перехода, если едх > есх
            "jmp iterSecond \n\t"       // иначе БУ переход во вторую итерацию

            "swap:\n\t"                 //
            "movq $0, %%rbx \n\t"       // рбх = 0
            "movq $0, %%rcx \n\t"       // рсх = 0
            "movq $0, %%rdx \n\t"       // рдх = 0
            "movl (%%rax), %%ebx\n\t"   // запись 32бит в ебх
            "lea -4(%%rax), %%rcx\n\t"  // смещение значения рах на 4 бита влево и записть в рсх
            "movl (%%rcx), %%edx \n\t"  // запись 32бит рсх в едх
            "movl %%ebx, (%%rcx)\n\t"   // запись ебх в рсх
            "movl %%edx, (%%rax) \n\t"  // запис едх в рах
            "jmp iterFirst \n\t"        // безусловный переход на метку

            "iterFirst: \n\t"           // пометка выполнения блока первого цикла
            "dec %%r10d \n\t"           // уменьшение значения регистра на 1
            "subq $4, %%rax \n\t"       // по сути переход к следующему элементу массива
            "jmp loopFirst\n\t"         // БУ переход в

            "iterSecond : \n\t"         // пометка выполнения второго цикла
            "addq $4, %%r8 \n\t"        // увеличение р8 на 4, что значит переход к следующему элементу
            "inc %%r9d \n\t"            // увеличение р9 на 1
            "jmp loopSecond \n\t"       // БУ переход в

            "break :"
            : //нет входных операндов
            :"D"(arr), "p"(counter)
            :"%rax", "%rbx", "%rcx", "%rdx", "r8", "r9", "r10");


    __asm__(
            "movq $0, %%r8 \n\t"
            "movq $0, %%r9 \n\t"
            "movq $0, %%rcx \n\t"
            "movl $0, %%rbx \n\t"
            "movq %0, %%r8 \n\t"
            "movl %1, %%ecx \n\t"
            "dec %%ecx \n\t"
            "leaq (%%r8), %%rbx \n\t"
            "movq %%rbx, (%%r8) \n\t"
            "movq $0, %%rcx \n\t"
            "movq %2, %%rax \n\t"
            "movl $9, %%ecx \n\t"
            "leaq %%rax, %%rbx \n\t"
            "movq %%rbx, %%rax \n\t"
            "movq $0, %%rcx \n\t"
            "movl $10, %%ecx \n\t"

            "put: \n\t"
            "movl (%%r8), %%r9d \n\t"
            "movl %%r9d, (%%rax) \n\t"
            "addq $4, %%r8 \n\t"
            "addq $4, %%rax \n\t"

            "break :\n\t"
            :
            :"D"(arr), "D"(counter), "p"(topTen)
            :"%rax", "%rbx", "%rcx", "%rdx", "r8", "r9", "r10");

    for (int j = 0; j < 10; j++)
    {
        printf("%d ", arr[j]);
    }

    for (int i = 0; i < 10  ; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);


    return 0;
}