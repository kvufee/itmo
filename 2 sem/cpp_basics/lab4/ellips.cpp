#include "ellips.h"

#include <bits/stdc++.h>

using namespace std;


ellips::ellips(double fig_radius, double fig_mass,
               double fig_diag1, double fig_diag2,
               double fig_square, double fig_perimeter) :
        fig_radius(fig_radius), fig_mass(fig_mass),
        fig_diag1(fig_diag1), fig_diag2(fig_diag2),
        fig_square(fig_square), fig_perimeter(fig_perimeter) {}

ellips::ellips()
{
    this->ellips::InitFromDialog();
}


//BaseCObject
const char* ellips::classname()
{
    return "Ellips";
}

unsigned int ellips::size()
{
    return sizeof(*this);
}

//IDialogInitiable
void ellips::InitFromDialog()
{
    cout << "Enter first diag: " << "\n";
    cin >> fig_diag1;
    cout << "Enter second diag: " << "\n";
    cin >> fig_diag2;
    cout << "Enter radius: " << "\n";
    cin >> fig_radius;
    cout << "Enter weight: " << "\n";
    cin >> fig_mass;
}

//IGeoFig
double ellips::square()
{
    fig_square = 3.14 * fig_diag1 * fig_diag2;
    return fig_square;
}
double ellips::perimeter()
{
    fig_perimeter = 4 * 3.14 * fig_diag1 * fig_diag2 +
            abs(fig_diag1 - fig_diag2) * 2 * fig_diag1 + fig_diag2;
    return fig_perimeter;
}

//IPhysObject
double ellips::mass()
{
    return fig_mass;
}

bool ellips::operator==(IPhysObject& ob)
{
    return mass() == ob.mass();
}

bool ellips::operator<(IPhysObject& ob)
{
    return mass() < ob.mass();
}

//IPrintable
void ellips::draw()
{
    cout << "Figure name is: Ellips" << "\n";
    cout << "Fig perimeter: " << fig_perimeter << "\n";
    cout << "Fig square: " << fig_square << "\n";
    cout << "Fig mass: " << fig_mass << "\n";
    cout << "Fig size: " << ellips::size() << "\n";
}