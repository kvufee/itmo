#include "hexagon.h"
#include "ellips.h"
#include <bits/stdc++.h>

using namespace std;


struct Figure: public ellips, public hexagon
{

};


int main()
{
    vector<Figure> contain;

    cout << "Enter ellips" << "\n";

    ellips ellips;
    ellips.InitFromDialog();
    ellips.draw();

    cout << "Enter hex" << "\n";

    hexagon hexagon;
    hexagon.InitFromDialog();
    hexagon.draw();

    return 0;
}