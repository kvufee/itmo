#include "triangle.h"
#include <bits/stdc++.h>

using namespace std;


float Triangle::heronSq(Triangle& trg)
{
    float square;

    float a, b, c;

    a = pow((trg.x1 - trg.x2), 2) + pow((trg.y1 - trg.y2), 2);
    b = pow((trg.x2 - trg.x3), 2) + pow((trg.y2 - trg.y3), 2);
    c = pow((trg.x3 - trg.x1), 2) + pow((trg.y3 - trg.y1), 2);

    perimeter = a + b + c;

    square = sqrt((perimeter/2) * ((perimeter/2) - a) * ((perimeter/2) - b) * ((perimeter/2) * c));
}


int main()
{
    
}