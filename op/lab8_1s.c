#include <stdio.h>


//task1
char* sumstrings(char *s1, char *s2)
{

    unsigned int len1 = strlen(s1);
    unsigned int len2 = strlen(s2);                      

    char *result = malloc(len1 + len2 + 1);

    memcpy(result, s1, len1); //переносит в result, берёт из s1, размер len1
    memcpy(result + len1, s2, len2 + 1); //переносит в  result + len1, берёт из s2, размер len2 + 1

    return result;
}


//task 4
char* samestrings(char *s1, char *s2)
{
    

    return result;
}


//task 5
char* copystrings()
{

}


//task 8
char* firstappear()
{

}


//task 11
char* substring()
{

}



int main()
{


    return 0;
}