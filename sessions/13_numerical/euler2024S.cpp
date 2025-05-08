#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template<typename Func>
double euler(Func f, double a, double b, int n) {
    double sum = 0;
    double h = (b-a)/n;
    double x = a+h;
    for (int i = 1; i <= n; i++, x += h) {
        sum += f(x);
    }
    return h*sum;
}
/*
    (f_a + f_a+h) / 2 

    (f_a+h + f_a+2h) / 2 


    (f_a+2h + h + f_a+3h) / 2 
    ...

     + f_b
*/

template<typename Func>
double trapezoidal(Func f, double a, double b, int n) {
    double sum = 0.5*(f(a) + f(b));
    double h = (b-a)/n;
    double x = a+h;
    for (int i = 1; i < n; i++, x += h) {
        sum += f(x);
    }
    return h*sum;
}


#if 0
template<typename Func>
double trapezoidal_converge(Func f, double sum, double a, double b, double eps) {
    int n = 1;

    double sum = 0.5*(f(a) + f(b));
    double h = (b-a)/n;
    double x = a+h;
    do {
        for (int i = 1; i < n; i++, x += h) {
            sum += f(x);
        }
        // h*sum

        double sum2 = sum;
        n = n * 2;
        double h2 = h/2;

        double x = a+h2;
        for (int i = 1; i < n; i++, x += h) {
            sum2 += f(x);
        }
    } while (abs(sum2 - sum) > eps);
    return h*sum2;
}
#endif


template<typename Func>
double gauss2(Func f, double a, double b, int n) {
    double sum = 0;
    const double h = (b-a)/n;
    const double h2 = h / 2;
    double x = a + h2;
    const double s = h2 * sqrt(1.0 / 3);
    for (int i = 0; i < n; i++, x += h) {
        sum += f(x - s) + f(x + s);
    }
    return h2*sum;
}


double f(double x) { return x*x; }  // x^3/3 = 1/3 - -1/3 = 2/3
double g(double x) { return x*x*x; } // int(x^3) on [-1,1]        x^4/4 = 1/4 - 1/4 = 0 

double h(double x) { return x*x*x*x; } // x^5/5 = 1/5 - -1/5 = 2/5

double hard(double x) { return x*x*x*x*x*x*x*x; }  // x^10/10 = 1/10 - -1/10 = 2/10

double asymptotic(double x) { return 1 / (x*x*x); }
// integral (asymptotic) on [1, 500000]


int main() {
    const double I = 1/3.0;
    for (int i = 1; i < 1024*1024*128; i*= 2) {
        double en = euler(f, 0, 1, i);
        double tn = trapezoidal(f, 0, 1, i);
        cout << setw(10) << i  << setw(20) << setprecision(16) <<  en << setw(20) << tn  << setw(20) << abs(en - I) << endl;
    }


    cout << "gauss 2nd order: " << gauss2(g, -1, 1, 1) << '\n';
    for (int i = 1; i < 32; i*= 2) {
        cout << "gauss 2nd order: " << i << ": " << gauss2(h, -1, 1, i) << '\n';
    }

    cout << "ROMBERG\n";
    for (int i = 1; i < 16; i*= 2) {
        double I1 = trapezoidal(hard, -1, 1, i);
        double I2 = trapezoidal(hard, -1, 1, i*2);
        double I4 = trapezoidal(hard, -1, 1, i*4);
        double I8 = trapezoidal(hard, -1, 1, i*8);

        double R1 = (4*I2 - I1) / 3;
        double R2 = (4*I4 - I2) / 3;
        double R4 = (4*I8 - I4) / 3;

        double Q1 = (16*R2 - R1) / 15;
        double Q2 = (16*R4 - R2) / 15;

        double W1 = (64*Q2 - Q1) / 63;
        cout <<  i << ": " << setw(20) << R1 << setw(20) << R2 << setw(20) << Q1 << setw(20) << W1 << '\n';
    }
}
