#include "header.h"
#include <bits/stdc++.h>

using namespace std;


void curPointValue(squarePoly& debil, int answer)
{   
    answer = debil.getA() * pow(debil.getX(), 2) + debil.getB() * debil.getX() + debil.getC();
    
    cout << "current amount is: " << answer << "\n";
}

void rootAmount(squarePoly& debil, int count)
{
    int discr;
    
    discr = pow(debil.getB(), 2) - 4 * debil.getA() * debil.getC();

    if (discr == 0 || discr > 0)
    {
        count = 2;

        cout << "amount of roots: " << count << "\n";
    }
}

void findRoots(squarePoly& debil, int root1, int root2)
{
    int discr;

    discr = pow(debil.getB(), 2) - 4 * debil.getA() * debil.getC();

    if (discr == 0)
    {
        root1 = -debil.getB() / (2 * debil.getA());

        cout << "x1 = x2 = " << root1 << "\n";
    } else if (discr > 0)
    {
        root1 = (-debil.getB() + sqrt(discr)) / (2 * debil.getA());
        root2 = (-debil.getB() - sqrt(discr)) / (2 * debil.getA());

        cout << "x1: " << root1 << "\n" << "x2: " << root2 << "\n";
    }
}

void findMinMax(squarePoly& debil)
{
    int min_value, max_value, discr, vertex;

    discr = pow(debil.getB(), 2) - 4 * debil.getA() * debil.getC();

    if (discr < 0)
    {
        cout << "No min/max" << "\n";
    } else if (discr == 0)
    {
        vertex = -(debil.getB())/(2 * debil.getA());

        min_value = vertex;

        max_value = debil.getA() * pow(vertex, 2) + debil.getB() * vertex + debil.getC();

        cout << "min: " << min_value << "\n" << "max: " << max_value << "\n";
    }
}


int main()
{

    return 0;
}