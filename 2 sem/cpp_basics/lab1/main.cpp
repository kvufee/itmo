#include <iostream>
#include <cmath>
#include "header.h"

using namespace std;


int main()
{
    double value_double;
    int value_int;

    cin >> value_double >> value_int;

    round(&value_double);
    round(value_double);

    return 0;
}