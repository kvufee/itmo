#include "header.h"
#include <cmath>


//round v1
double round(double& value)
{
    floor(value);
}

//round v2
double round(double* value)
{
    if (value) floor(*value);
}


//negate v1
int negate(int& value)
{
    return value * -1;
}

//negate v2
int negate(int* value)
{
    return *value * -1;
}