#include "hexagon.h"
#include "ellips.h"

using namespace std;


int main()
{
    ellips ellips;
    ellips.InitFromDialog();
    ellips.draw();

    hexagon hexagon;
    hexagon.InitFromDialog();
    hexagon.draw();

    return 0;
}