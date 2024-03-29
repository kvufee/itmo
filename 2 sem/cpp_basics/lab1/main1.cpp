    #include "header1.h"

#include <bits/stdc++.h>

using namespace std;


int main()
{
    float value_first, value_second;
    cin >> value_first >> value_second;

    roundFirst(value_first);
    roundSecond(&value_second);

    cout << "round reference: " << value_first << "\n";
    cout << "round pointer: " << value_second << "\n";

    ///////////////////////////////////////////////

    float num_first, num_second;
    cin >> num_first >> num_second;

    negateFirst(num_first);
    negateSecond(&num_second);

    cout << "negate reference: " << num_first << "\n";
    cout << "negate pointer: " << num_second << "\n";

    ////////////////////////////////////////////////
    
    square Square1, Square2;
    vec Vec1, Vec2;

    cin >> Square1.x1 >> Square1.y1 >>
           Square1.x2 >> Square1.y2 >>
           Square1.x3 >> Square1.y3 >>
           Square1.x4 >> Square1.y4 >>
           Vec1.x >> Vec1.y;
    
    cin >> Square2.x1 >> Square2.y1 >>
           Square2.x2 >> Square2.y2 >>
           Square2.x3 >> Square2.y3 >>
           Square2.x4 >> Square2.y4 >>
           Vec2.x >> Vec2.y;

    moveSquareFirst(Square1, Vec1);
    moveSquareSecond(&Square2, &Vec2);
    
    cout << "square movement reference: " << "\n" << 
            Square1.x1 << " " << Square1.y1 << "\n" <<
            Square1.x2 << " " << Square1.y2 << "\n" <<
            Square1.x3 << " " << Square1.y3 << "\n" <<
            Square1.x4 << " " << Square1.y4 << "\n";

    cout << "square movement pointer: " << "\n" << 
            Square2.x1 << " " << Square2.y1 << "\n" <<
            Square2.x2 << " " << Square2.y2 << "\n" <<
            Square2.x3 << " " << Square2.y3 << "\n" <<
            Square2.x4 << " " << Square2.y4 << "\n";

    ////////////////////////////////////////////////

    int a, b;

    cin >> a >> b;

    replaceFirst(&a,&b);
    cout << "replace pointer: " << a  << " " << b << "\n";

    replaceSecond(a,b);
    cout << "replace reference: " << a << " " << b << "\n";

    return 0;
}