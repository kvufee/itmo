#include "hexagon.h"

#include <bits/stdc++.h>

using namespace std;


hexagon::hexagon(double fig_side, double fig_square,
                 double fig_perimeter, double fig_mass) :
                 fig_side(fig_side), fig_square(fig_square),
                 fig_perimeter(fig_perimeter), fig_mass(fig_mass) {}

hexagon::hexagon()
{
    this->hexagon::InitFromDialog();
}


//BaseCObject
const char* hexagon::classname()
{
    return "Hexagon";
}

unsigned int hexagon::size()
{
    return sizeof(*this);
}

//IDialogInitiable
void hexagon::InitFromDialog()
{
    cout << "Enter side: " << "\n";
    cin >> fig_side;
    cout << "Enter weight: " << "\n";
    cin >> fig_mass;
}

//IGeoFig
double hexagon::square()
{
    fig_square = (sqrt(3)/2) * pow(fig_side, 2);
    return fig_square;
}
double hexagon::perimeter()
{
    fig_perimeter = fig_side * 6;
    return fig_perimeter;
}

//IPhysObject
double hexagon::mass()
{
    return fig_mass;
}

bool hexagon::operator==(IPhysObject& ob)
{
    return mass() == ob.mass();
}

bool hexagon::operator<(IPhysObject& ob)
{
    return mass() < ob.mass();
}

//IPrintable
void hexagon::draw()
{
    cout << "Figure name is: Hexagon" << "\n";
    cout << "Fig perimeter: " << hexagon::perimeter() << "\n";
    cout << "Fig square: " << hexagon::square() << "\n";
    cout << "Fig mass: " << hexagon::mass() << "\n";
    cout << "Fig size: " << hexagon::size() << "\n";
}

