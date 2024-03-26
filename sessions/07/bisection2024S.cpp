#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x*x - 2; }
// root = +/- sqrt(2)

// 0      1
//     0.5
//  .25
// .1010101010111000110010101010101001
// double = seeeeeeeeeeemmmmmmmmmmmmmmmmmmmmmmmmmm...
// mantissa = 52 + 11=e + 1=s = 64 bits
// actually there are 53 bits in mantissa
//     1.xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// 53 times uses all the bits EXCEPT
// a = 5, b = 5.2e+208
// a = 0, b = 3
//      1.5
//    .75



typedef double (*FuncOneVar)(double x);
double bisect(FuncOneVar f, double a, double b, double eps) {
    if (f(a)*f(b) >= 0) {
        cout << "not guaranteed to have root\n";
    }
    do {
        double x = (a + b) / 2;
        if (f(x) < 0 ) {
            a = x;
        } else if (f(x) > 0 {
            b = x;
        } else
           return x;
    } while ( abs(b-a) > eps);
    return (a+b)/2;
}


int main() {
    cout << bisect(f, 0, 3, .00001) << '\n';
    cout << bisect(cos, 0, 3, .00001) << '\n';
}

