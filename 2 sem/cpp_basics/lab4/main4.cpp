#include "hexagon.h"
#include "ellips.h"

#include <iostream>


using namespace std;


int main()
{
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