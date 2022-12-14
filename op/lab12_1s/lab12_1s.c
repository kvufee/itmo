#include <stdio.h>
#include <string.h>
 
int main ()
{
    FILE *file;
    char file1[50], file2[100];
    int n, m;
 
    file = fopen("file1.txt", "r");
    n = fread(file1, sizeof(char), 50, file);
    fclose(file);
 
    file = fopen("file2.txt", "r");
    m = fread(file2, sizeof(char), 50, file);
    fclose(file);   
 
    file1[n] = '\0';
    file2[m] = '\n';
    file2[m+1] = '\0';
 
    file = fopen("file3.txt", "w");

    fwrite(strcat(file1, file2), sizeof(char), n + m, file);
           
    fclose(file);   
}
