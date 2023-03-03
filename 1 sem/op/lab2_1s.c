#include <stdio.h>
#include <math.h>

int main()
{
    double z_1, z_2, a;
    scanf("%lf", &a);

    double k, l, m, n, o;

    k = (a + 2)/(sqrt(2 * a));
    l = a / (sqrt(2 * a) + 2);
    m = 2 / (a - sqrt(2 * a));
    n = (sqrt(a) - sqrt(2)) / (a + 2);
    o = 1 / (sqrt(a) + sqrt(2));
    
    z_1 = (k - l + m) * n;
    z_2 = o;

    printf("z_1 = %lf", z_1);
    printf("\nz_2 = %lf", z_2);

    return 0;

}