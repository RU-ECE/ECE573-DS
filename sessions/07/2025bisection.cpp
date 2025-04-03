#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x - 2; // root = +/- sqrt(2) ~ 1.414...
}

typedef double (*FuncOneVar)(double);

double bisection(FuncOneVar f, double a, double b, double eps) {
    double ya = f(a), yb = f(b);
    if (ya*yb > 0)
        throw "die!";
    double x;
    do {        
        x = (a + b) / 2;
        cout << "x=" << x << '\n';
        double y = f(x);
        if (y > 0) {
            b = x;
        } else if (y < 0) {
            a = x;
        } else {
            return x;
        }
    } while ((b-a) > eps);
    return x;
}

int main() {
    cout << setprecision(16);
    cout << bisection(f, 0, 5, .01) << '\n';
    cout << bisection(f, 0, 5, .0001) << '\n';
    cout << bisection(f, 0, 5, .000001) << '\n';
}