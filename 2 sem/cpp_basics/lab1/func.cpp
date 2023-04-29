#include "header1.h"
#include <bits/stdc++.h>

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
void mltpMatrixLinesFirst(int mx[], int num)
{

    for (int i = 0; i < 9; ++i)
    {
        mx[i] *= num;
    }   
}

void readMatrixFirst(int mx[])
{
    for (int i = 0; i < 9; ++i)
    {   
        cin >> mx[i];
    }
}

void mltpMatrixLinesSecond(int *mx, int num)
{
    for (int i = 0; i < 9; ++i)
    {   
        cin >> mx[i];
    }

    for (int i = 0; i < 9; ++i)
    {
        mx[i] *= num;
    }
}

void readMatrixSecond(int mx[])
{
    for (int i = 0; i < 9; ++i)
    {   
        cin >> mx[i];
    }
}