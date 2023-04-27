#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


class squarePoly
{
    int a, b, c;
    int min_point, max_point;

    public:
        squarePoly(int first, int second, int third)
        {
            first = a;
            second = b;
            third = c;
        }

        squarePoly(const squarePoly& debil)
        {
            a = debil.a;
            b = debil.b;
            c = debil.c;
        }
        
};

#endif