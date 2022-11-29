#include <stdio.h>
#include "triangle.h"


int main()
{
    struct rightTriangle rTriangle;

    scanf("%lf %lf", &rTriangle.x1, &rTriangle.y1);
    scanf("%lf %lf", &rTriangle.x2, &rTriangle.y2);

    printf("Perimeter = %.2lf \n", perimeter(rTriangle));
    printf("Squart = %.2lf \n", area(rTriangle));

    return 0;
}