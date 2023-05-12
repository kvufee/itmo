#include "hexagon.h"

#include <bits/stdc++.h>

using namespace std;


//BaseCObject
const char* hexagon::classname()
{
    char* str;
    cin.getline(str, 100);
    fig_name = str;
}
unsigned int hexagon::size()
{
    cin >> fig_size;
}

//IDialogInitiable
void hexagon::InitFromDialog() {}

//IGeoFig
double hexagon::square()
{
    cin >> fig_square;
}
double hexagon::perimeter()
{
    cin >> fig_perimeter;
}

//IPhysObject
double hexagon::mass()
{
    cin >> fig_mass;
}
bool hexagon::operator== (IPhysObject& ob)
{
    return mass() == ob.mass();
}
bool hexagon::operator< (IPhysObject& ob)
{
    return mass() < ob.mass();
}

//IPrintable
void hexagon::draw()
{
    cout << fig_name << "\n"
         << fig_perimeter << "\n"
         << fig_square << "\n"
         << fig_size << "\n"
         << fig_mass << "\n";
}