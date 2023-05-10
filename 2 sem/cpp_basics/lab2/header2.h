#pragma once


class squarePoly
{
    public:
        int a, b, c, x;

        squarePoly();
        
        squarePoly(int first, int second, int third, int value);

        void curPointValue(squarePoly& debil);
        void rootAmount(squarePoly& debil);
        void findRoots(squarePoly& debil);
        void findMinMax(squarePoly& debil);
        
};
