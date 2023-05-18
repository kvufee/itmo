#include "triangle.h"
#include <iostream>
#include <cmath>

using namespace std;


triangle::triangle()
{
    float x1 = 0, y1 = 0;
    float x2 = 0, y2 = 0;
    float x3 = 0, y3 = 0;
}

triangle::triangle(float x1, float y1, float x2, float y2, float x3, float y3) : 
                   x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}


float triangle::heronSq(triangle& trg)
{
    float square;

    float a, b, c;

    a = pow((trg.x1 - trg.x2), 2) + pow((trg.y1 - trg.y2), 2);
    b = pow((trg.x2 - trg.x3), 2) + pow((trg.y2 - trg.y3), 2);
    c = pow((trg.x3 - trg.x1), 2) + pow((trg.y3 - trg.y1), 2);

    perimeter = a + b + c;

    square = sqrt((perimeter/2) * ((perimeter/2) - a) * ((perimeter/2) - b) * ((perimeter/2) * c));

    return square;
}

float triangle::perimCount(triangle &trg)
{
    float perimeter;

    float a, b, c;

    a = pow((trg.x1 - trg.x2), 2) + pow((trg.y1 - trg.y2), 2);
    b = pow((trg.x2 - trg.x3), 2) + pow((trg.y2 - trg.y3), 2);
    c = pow((trg.x3 - trg.x1), 2) + pow((trg.y3 - trg.y1), 2);

    perimeter = a + b + c;

    return perimeter;
}