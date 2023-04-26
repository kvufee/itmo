#include "header.h"
#include <iostream>
#include <cmath>

using namespace std;


//round v1
void round_first(float& value)
{
    round(value);
}

//round v2
void round_second(float* value)
{
    round(*value);
}   


//negate v1
void negate_first(int& value)
{
    value *= -1;
}

//negate v2
void negate_second(int* value)
{
    *value *= -1;
}


int main()
{
    float value_first, value_second;
    cin >> value_first >> value_second;

    round_first(value_first);
    round_second(&value_second);

    cout << "round reference: " << value_first << "\n";
    cout << "round pointer: " << value_second << "\n";

    return 0;
}