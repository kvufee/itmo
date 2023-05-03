#include "hexagon.h"

#include <bits/stdc++.h>

using namespace std;


hexagon::hexagon() = default;

hexagon::hexagon(const char* fig_name,
                 unsigned int fig_size,
                 double fig_square,
                 double fig_perimeter,
                 double fig_mass) : fig_name(fig_name),
                                    fig_size(fig_size),
                                    fig_square(fig_square),
                                    fig_perimeter(fig_perimeter),
                                    fig_mass(fig_mass) {}



int main()
{
    hexagon hexagon;

    return 0;
}