#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
 

void roundFirst(float&);
void roundSecond(float*);

void negateFirst(int&);
void negateSecond(int*);

struct square
{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
};

struct vec
{
    int x, y;
};

void moveSquareFirst(square );
void moveSquareSecond();
 

#endif