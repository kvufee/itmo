#include "header2.h"

class squarePoly
{

    public:
    
        int a, b, c, x;
        
        squarePoly (int first, int second, int third, int value)
        {
            a = first;
            b = second;
            c = third;
            x = value;
        }

        squarePoly (const squarePoly& debil)
        {
            a = debil.a;
            b = debil.b;
            c = debil.c;
            x = debil.x;
        }

        
};