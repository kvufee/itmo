#include <stdio.h>
#include <string.h>
 
int main (int argc, char* argv[])
{
    FILE *f1, *f2, *f3;
    char file1[100], file2[100];
    int n, m;

    f1 = fopen(argv[1], "r");
    n = fread(file1, sizeof(char), 100, f1);
    fclose(f1);

    f2 = fopen(argv[2], "r");
    m = fread(file2, sizeof(char), 100, f2);
    fclose(f2);   
 
    file1[n] = '\0';
    file2[m] = '\n';
    file2[m+1] = '\0';
 
    f3 = fopen(argv[3], "w");
    fwrite(strcat(file1, file2), sizeof(char), n + m, f3);   
    fclose(f3);

    return 0;
}
