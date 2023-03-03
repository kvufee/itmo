#include <stdio.h>

int main() {
    int a, b;
    printf("1. Input a hexademical number: ");
    scanf("%x", &a);
    printf("2. Output an octal number: %o", a);
    printf("\n3. Output a hexademical number: %x", a << 2);
    printf("\n4. Output a hex (1) and : %x", ~a);
    printf("\nEnter hex number: ");
    scanf("%x", &b);
    printf("5. Or for a and b: %x", a | b);

    return 0;
}