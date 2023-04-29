#include "triangle.h"
#include "triangle.cpp"
#include <bits/stdc++.h>

using namespace std;


int main()
{
    triangle trg1;
    triangle trg2;

    cout << "triangle 1: ";
    cin >> trg1.x1 >> trg1.y1 >> trg1.x2 >> trg1.y2 >> trg1.x3 >> trg1.y3;
    trg1.heronSq(trg1);
    
    cout << "triangle 2: ";
    cin >> trg2.x1 >> trg2.y1 >> trg2.x2 >> trg2.y2 >> trg2.x3 >> trg2.y3;
    trg2.heronSq(trg2);

    cout << "\n";

    if (trg1.heronSq(trg1) == trg2.heronSq(trg2))
    {
        cout << "trg1 == trg2" << "\n";
    } else if (trg1.heronSq(trg1) != trg2.heronSq(trg2))
    {
        cout << "trg1 != trg2" << "\n";
    }

    if (trg1.heronSq(trg1) > trg2.heronSq(trg2))
    {
        cout << "trg1 > trg2" << "\n";
    } else if (trg1.heronSq(trg1) < trg2.heronSq(trg2))
    {
        cout << "trg1 < trg2" << "\n";
    }

    /////////////////////////////////////////

    


    return 0;
}