#include "header.h"
#include <iostream>
#include <cmath>

using namespace std;


//round
void roundFirst(float& value)
{
    round(value);
}

void roundSecond(float* value)
{
    round(*value);
}   


//negate
void negateFirst(int& value)
{
    value *= -1;
}

void negateSecond(int* value)
{
    *value *= -1;
}


//square moving
void moveSquareFirst()
{
    
}

void moveSquareSecond()
{
    
}


int main()
{
    float value_first, value_second;
    cin >> value_first >> value_second;

    roundFirst(value_first);
    roundSecond(&value_second);

    cout << "round reference: " << value_first << "\n";
    cout << "round pointer: " << value_second << "\n";


    int num_first, num_second;
    cin >> num_first >> num_second;

    negateFirst(num_first);
    negateSecond(&num_second);

    cout << "negate reference: " << num_first << "\n";
    cout << "negate pointer: " << num_second << "\n";




    return 0;
}