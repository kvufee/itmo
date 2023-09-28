#include <stdio.h>

void asmSort(int *arr, int counter) {
    __asm__(
            "movq %0, %%r8 \n\t"        // запись переменной р8 (массив арр)
            "movq $0, %%r9 \n\t"        // запись переменной р9. р9 = 0

            "currCheck :\n\t"
            "cmpl $0, %%r10d \n\t"      // если р10 = 0,
            "je iterSecond \n\t"        // то переход на метку вторая итерация
            "jmp comp \n\t"             // иначе безусловный переход на comp

            "goToCurrCheck: \n\t"           // пометка выполнения блока первого цикла
            "dec %%r10d \n\t"           // уменьшение значения регистра на 1
            "subq $4, %%rax \n\t"       // переход к следующему элементу массива
            "jmp currCheck\n\t"         // БУ переход в

            "isFinished : \n\t"         // цикл для завершения
            "cmpl %%r9d, %1 \n\t"       // если р9 == counter тогда
            "je break \n\t"             // переход в метку break :
            "movq $0, %%r10 \n\t"       // запись переменной р10. р10 = 0
            "movq $0, %%rax \n\t"       // запись переменной рах. рах = 0
            "movq %%r8, %%rax \n\t"     // значение р8 записывается в регистр данных
            "movl %%r9d, %%r10d \n\t"   // значение р9 записывается в р10. буква д для 32бит регистра числа.
            "jmp currCheck \n\t"        // переход в первый цикл

            "goToNext : \n\t"         // пометка выполнения второго цикла
            "addq $4, %%r8 \n\t"        // увеличение р8 на 4, что значит переход к следующему элементу
            "inc %%r9d \n\t"            // увеличение р9 на 1
            "jmp goToFinished \n\t"       // БУ переход в

            "comp: \n\t"
            "movq $0, %%rbx \n\t"
            "movq $0, %%rcx \n\t"
            "movq $0, %%rdx \n\t"
            "lea -4(%%rax), %%rbx \n\t" // загрузка адреса в регистр рбх. вычисление адреса на 4 бита влево от rax
            "movl (%%rbx), %%ecx\n\t"   // запись из рбх в есх. смещение 32бит значение в регистр
            "movl (%%rax), %%edx \n\t"  // то же самое
            "cmpl %%edx, %%ecx \n\t"
            "jg swap \n\t"              // функция перехода, если едх > есх
            "jmp goToNext \n\t"       // иначе БУ переход во вторую итерацию

            "swap:\n\t"
            "movq $0, %%rbx \n\t"
            "movq $0, %%rcx \n\t"
            "movq $0, %%rdx \n\t"
            "movl (%%rax), %%ebx\n\t"   // запись 32бит в ебх
            "lea -4(%%rax), %%rcx\n\t"  // смещение значения рах на 4 бита влево и записть в рсх
            "movl (%%rcx), %%edx \n\t"  // запись 32бит рсх в едх
            "movl %%ebx, (%%rcx)\n\t"
            "movl %%edx, (%%rax) \n\t"
            "jmp goToCurr \n\t"        // безусловный переход на метку

            "break :"
            : //нет входных операндов
            :"D"(arr), "p"(counter) //"D" - связывает arr с регистром доступа к данным, "p" - размер rcx = counter
            :"%rax", "%rbx", "%rcx", "%rdx", "r8", "r9", "r10");
    //rax - хранение результатов операций, rbx - базовый регистр, rcx - счётчик цикла, rdx - регистр данных
    //r8.9.10 - просто регистры для чисел
}

int main()
{
    FILE *file = fopen("evm1.txt", "r");

    int arr[1000];
    int num, element = 0, counter = 0;

    while (fscanf(file, "%d", &num) == 1 && element < 1000)
    {
        arr[element] = num;
        element++;
        counter++;
    }

    for (int j = 0; j < element; j++) {
        printf("%d ", arr[j]);
    }

    fclose(file);

    printf("\n");

    asmSort(arr, counter);

    for (int j = 0; j < element; j++) {
        printf("%d ", arr[j]);
    }

    return 0;
}
