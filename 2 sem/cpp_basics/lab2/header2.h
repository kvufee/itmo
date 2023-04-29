#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


class squarePoly
{
    int a, b, c, x;

    public:
        squarePoly();
        
        squarePoly(int first, int second, int third, int value);

        void curPointValue(squarePoly& debil);
        void rootAmount(squarePoly& debil);
        void findRoots(squarePoly& debil);
        void findMinMax(squarePoly& debil);

        int getA();
        int getB();
        int getC();
        int getX();
        
};

#endif