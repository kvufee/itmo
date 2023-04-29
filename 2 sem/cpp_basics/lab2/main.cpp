#include "header2.h"
#include <bits/stdc++.h>

using namespace std;


squarePoly::squarePoly()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int x = 0;
}

squarePoly::squarePoly(int a, int b, int c, int x) : a(a), b(b), c(c), x(x) {}


void squarePoly::curPointValue(squarePoly& debil)
{   
    int answer;

    answer = debil.a * pow(debil.x, 2) + debil.b * debil.x + debil.x;
    
    cout << "current amount is: " << answer << "\n";
}

void squarePoly::rootAmount(squarePoly& debil)
{
    int discr, count = 0;
    
    discr = pow(debil.b, 2) - 4 * debil.a * debil.c;

    if (discr == 0 || discr > 0)
    {
        count = 2;
    }

    cout << "amount of roots: " << count << "\n";
}

void squarePoly::findRoots(squarePoly& debil)
{
    int root1, root2;
    int discr;

    discr = pow(debil.b, 2) - 4 * debil.a * debil.c;

    if (discr == 0)
    {
        root1 = -debil.b / (2 * debil.a);

        cout << "x1 = x2 = " << root1 << "\n";
    } else if (discr > 0)
    {
        root1 = (-debil.b + sqrt(discr)) / (2 * debil.a);
        root2 = (-debil.b - sqrt(discr)) / (2 * debil.a);

        cout << "x1: " << root1 << "\n" << "x2: " << root2 << "\n";
    } else cout << "No roots" << "\n";
}

void squarePoly::findMinMax(squarePoly& debil)
{
    int min_value, max_value, discr, vertex;

    discr = pow(debil.b, 2) - 4 * debil.a * debil.c;

    if (discr == 0 || discr > 0)
    {
        vertex = -(debil.b)/(2 * debil.a);

        min_value = vertex;

        max_value = debil.a * pow(vertex, 2) + debil.b * vertex + debil.c;

        cout << "min: " << min_value << "\n" << "max: " << max_value << "\n";
    }
    else if (discr < 0)
    {
        cout << "No min/max" << "\n";
    }
}


int main()
{
    squarePoly SP;

    cin >> SP.a >> SP.b >> SP.c >> SP.x;

    SP.curPointValue(SP);
    SP.rootAmount(SP);
    SP.findRoots(SP);
    SP.findMinMax(SP);

    return 0;
}