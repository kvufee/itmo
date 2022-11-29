#include "triangle.h"


double area(struct rightTriangle rTriangle)
{
    double hypotenuse;
    double area;

    hypotenuse = sqrt(pow(rTriangle.x2 - rTriangle.x1, 2) - pow(rTriangle.y2 - rTriangle.y1, 2));
    area = 0.5 * (rTriangle.x2 - rTriangle.x1) * (rTriangle.y2 - rTriangle.y1);
    
    return (area);
}


double perimeter(struct rightTriangle rTriangle)
{
    double hypotenuse;
    double perimeter;

    hypotenuse = sqrt(pow(rTriangle.x2 - rTriangle.x1, 2) - pow(rTriangle.y2 - rTriangle.y1, 2));
    perimeter = (rTriangle.x2 - rTriangle.x1) + (rTriangle.y2 - rTriangle.y1) + hypotenuse;

    return (perimeter);
}