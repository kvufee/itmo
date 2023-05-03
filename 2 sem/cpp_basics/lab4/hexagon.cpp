#include "hexagon.h"

#include <bits/stdc++.h>

using namespace std;


//BaseCObject
const char* hexagon::classname()
{
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
bool hexagon::operator== (const IPhysObject& ob)
{
    //ТУТ КАРОЧИ СРАВНИ ДВЕ ШТУКИ
}
bool hexagon::operator< (const IPhysObject& ob)
{
    //ТУТ КАРОЧИ СРАВНИ ДВЕ ШТУКИ
}

//IPrintable
void hexagon::draw() {}