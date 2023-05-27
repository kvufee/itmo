#include "triangle.h"
#include "stack.h"

#include <bits/stdc++.h>

using namespace std;

int main()
{
    Triangle trg1;
    Triangle trg2;

    cout << "triangle 1: ";
    cin >> trg1.x1 >> trg1.y1 >> trg1.x2 >> trg1.y2 >> trg1.x3 >> trg1.y3;
    trg1.square = trg1.heronSq(trg1);
    trg1.perimeter = trg1.perimCount(trg1);

    cout << "Heron Square of 1st triangle: " << trg1.square << "\n";
    cout << "Perimeter of 1st triangle: " << trg1.perimeter << "\n";

    cout << "triangle 2: ";
    cin >> trg2.x1 >> trg2.y1 >> trg2.x2 >> trg2.y2 >> trg2.x3 >> trg2.y3;
    trg2.square = trg2.heronSq(trg2);
    trg2.perimeter = trg2.perimCount(trg2);

    cout << "Heron Square of 2nd triangle: " << trg2.square << "\n";
    cout << "Perimeter of 1st triangle: " << trg2.perimeter << "\n";

    cout << "\n";


    if (trg1 == trg2)
    {
        cout << "trg1 == trg2" << "\n";
    } else if (trg1 != trg2)
    {
        cout << "trg1 != trg2" << "\n";
    }

    if (trg1 > trg2)
    {
        cout << "trg1 > trg2" << "\n";
    } else if (trg1 < trg2)
    {
        cout << "trg1 < trg2" << "\n";
    }


    Stack stack;

    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        stack.push(x);
    };

    for (int i = 0; i < 2; i++)
    {
        stack.pop();
    };

    stack.show_stack(stack);


    return 0;
}