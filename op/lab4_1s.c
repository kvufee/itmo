#include <stdio.h>

char* CheckNumber(int n) // функция проверки числа на принадлежность промежутку
{
    if ((n <= 1) && (n >= -77))
    {
        return "Correct";
    } else return "Incorrect";
}

int main()
{
    int a, b;
    scanf("%d", &a);

    printf("%s ", CheckNumber(a));
    
    scanf("%x", &b); // 2-е задание. ввод числа в 16-й СС
    
    printf("%d\n", (b >> 17) & 1); //побитовый сдвиг и проверка бита n18

    return 0;
}