#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


class squarePoly
{
    int a, b, c, x;

    public:
        squarePoly(int first, int second, int third, int value)
        {
            a = first;
            b = second;
            c = third;
            x = value;
        }

        squarePoly(const squarePoly& debil)
        {
            a = debil.a;
            b = debil.b;
            c = debil.c;
            x = debil.x;
        }

        int getA() { return a; }
        int getB() { return b; }
        int getC() { return c; }
        int getX() { return x; }
        
};

#endif