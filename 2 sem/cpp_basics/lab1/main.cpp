#include "header1.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


//round
void roundFirst(float& value)
{
    value = static_cast<int>(value);
}

void roundSecond(float* value)
{
    *value = static_cast<int>(*value);
}   


//negate
void negateFirst(float& value)
{
    value *= -1;
}

void negateSecond(float* value)
{
    *value *= -1;
}


//square moving
void moveSquareFirst(square &Square, vec &Vec)
{
    Square.x1 += Vec.x;
    Square.y1 += Vec.y;

    Square.x2 += Vec.x;
    Square.y2 += Vec.y;

    Square.x3 += Vec.x;
    Square.y3 += Vec.y;

    Square.x4 += Vec.x;
    Square.y4 += Vec.y;
}

void moveSquareSecond(square *Square, vec *Vec)
{
    Square->x1 += Vec->x;
    Square->y1 += Vec->y;

    Square->x2 += Vec->x;
    Square->y2 += Vec->y;

    Square->x3 += Vec->x;
    Square->y3 += Vec->y;

    Square->x4 += Vec->x;
    Square->y4 += Vec->y;
}


//multiply
void mltpMatrixLinesFirst(vector<int> &mx, int num)
{
    for (int i = 0; i < 9; ++i)
    {
        mx[i] *= num;
    }
}

void mltpMatrixLinesSecond(vector<int> *mx, int num)
{
    for (int i = 0; i < mx->size(); ++i)
    {
        (*mx)[i] *= num;
    }
}


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

    int num;
    cin >> num;
    vector<int> mx1;
    vector<int> mx2;

    for (int i = 0; i < 9; ++i)
    {   
        int a;
        cin >> a;
        mx1.push_back(a);
        mx2.push_back(a);
    }

    mltpMatrixLinesFirst(mx1, num);
    mltpMatrixLinesSecond(&mx2, num);

    for (int i = 0; i < 9; ++i)
    {
        cout << mx1[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i < 9; ++i)
    {
        cout << mx2[i] << " ";
    }

    return 0;
}