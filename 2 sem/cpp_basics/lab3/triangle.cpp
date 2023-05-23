#include "triangle.h"

#include <cmath>

using namespace std;


Triangle::Triangle()
{
    float x1 = 0, y1 = 0;
    float x2 = 0, y2 = 0;
    float x3 = 0, y3 = 0;
    float perimeter = 0, square = 0;
}


float Triangle::heronSq(Triangle& trg)
{
    float a, b, c;

    a = pow((trg.x1 - trg.x2), 2) + pow((trg.y1 - trg.y2), 2);
    b = pow((trg.x2 - trg.x3), 2) + pow((trg.y2 - trg.y3), 2);
    c = pow((trg.x3 - trg.x1), 2) + pow((trg.y3 - trg.y1), 2);

    perimeter = a + b + c;

    square = sqrt((perimeter/2) * ((perimeter/2) - a) * ((perimeter/2) - b) * ((perimeter/2) * c));

    return square;
}

float Triangle::perimCount(Triangle &trg)
{
    float a, b, c;

    a = pow((trg.x1 - trg.x2), 2) + pow((trg.y1 - trg.y2), 2);
    b = pow((trg.x2 - trg.x3), 2) + pow((trg.y2 - trg.y3), 2);
    c = pow((trg.x3 - trg.x1), 2) + pow((trg.y3 - trg.y1), 2);

    perimeter = a + b + c;

    return perimeter;
}

bool Triangle::operator==(const Triangle& trg) const
{
    return (square == trg.square);
}

bool Triangle::operator!=(const Triangle& trg) const
{
    return (square != trg.square)
}

bool Triangle::operator<(const Triangle& trg) const
{
    return (square < trg.square);
}

bool Triangle::operator>(const Triangle& trg) const
{
    return (square > trg.square);
}