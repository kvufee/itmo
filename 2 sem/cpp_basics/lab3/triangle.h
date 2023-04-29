#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


class Triangle
{
    float x1, y1;
    float x2, y2;
    float x3, y3;

    float perimeter;

    public:
        bool operator == (Triangle& trg);
        bool operator != (Triangle& trg);
        bool operator < (Triangle& trg);
        bool operator > (Triangle& trg);
        Triangle operator + (Vec& vec);

        float heronSq(Triangle& trg);
};

struct Vec
{
    float x, y;
};


#endif