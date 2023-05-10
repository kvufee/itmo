#pragma once

void roundFirst(float&);
void roundSecond(float*);


void negateFirst(float&);
void negateSecond(float*);


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

void moveSquareFirst(square &Square, vec &Vec);
void moveSquareSecond(square *Square, vec *Vec);


void replaceFirst(int *a, int *b);
void replaceSecond(int &a, int &b);