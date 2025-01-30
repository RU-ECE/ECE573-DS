#include <iostream>
/*
    floating point data types...
    IEEE754 standard
*/
int main() {
    float a = 1.0f;
    float b = 1.2345678f;
    float c = 12345.678f;
    float d = 6.022e+23; // decimal 23 places to the right
    float e = -1.2345678e-38; // decimal place 38 places to the left

    double f = 1.23456789012345; 
    double g = 1.23456789012345e+308;
    double h = 1.23456789012345e-308;
    return 0;
}