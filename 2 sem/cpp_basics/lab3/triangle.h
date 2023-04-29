#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


class triangle
{
    public:
        triangle();

        triangle(float x1, float y1, float x2, float y2, float x3, float y3);

        float x1, y1;
        float x2, y2;
        float x3, y3;

        float perimeter;

        bool operator == (triangle& trg);
        bool operator != (triangle& trg);
        bool operator < (triangle& trg);
        bool operator > (triangle& trg);
        triangle operator + (Vec& vec);

        void heronSq(triangle& trg);
};

struct Vec
{
    float x, y;
};


#endif