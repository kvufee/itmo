#include <iostream>
#include <cmath>
#include "header.h"

using namespace std;


//round v1
void round_first(double& value)
{
    floor(value);
}

//round v2
void round_second(double* value)
{
    floor(*value);
}   


//negate v1
void negate_first(int& value)
{
    value * -1;
}

//negate v2
void negate_second(int* value)
{
    *value * -1;
}


int main()
{
    double value_double;
    int value_int;

    cin >> value_double >> value_int;

    round(&value_double);
    round(value_double);

    return 0;
}