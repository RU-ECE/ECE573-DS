#include <iostream>
#include <cmath>

#include <iomanip>

using namespace std;


double trapezoidal(double (*f)(double), double a, double b, int n) // error(h^2)
{
  double h = (b - a) / n;
  double sum = 0.5 * (f(a) + f(b));
  for (int i = 1; i < n; ++i)
    sum += f(a + i * h);
  return sum * h;
}
// trapezoidal with error control, doubling n each time, comparing until two sums are close enough
double trapezoidal2(double (*f)(double), double a, double b, double eps) // error(h^2)
{
    double h = (b - a);
    double h2;
    double sum = 0.5 * (f(a) + f(b));
    double sum2;
    int n = 2;
    do {
        double start;
        h2 =  h/2;
        start = a + h2; // start halfway through each slice
        sum2 = 0;
        for (int i = 1; i < n; ++i)
        sum2 += f(start + i * h);
        h = h2;
        n *= 2;
        cout << "n=" << n << " sum = " << sum << " sum2 = " << sum2 << endl;
    } while (abs(sum2*h - sum*2*h) > eps);
  return sum2 * h;
}

double gauss2(double (*f)(double), double a, double b) {
    const double h = (b - a) / 2; // for Gauss, it's always /2
    const double mid = (a + b) / 2;
    const double s = h * sqrt(1.0 / 3);
    const double x0 = mid - s, x1 = mid + s;
    const double sum = 1.0 *f(x0) + 1.0*f(x1);
    return sum;
}

double gauss3(double (*f)(double), double a, double b) {
    const double h = (b - a) / 2; // for Gauss, it's always /2
    const double mid = (a + b) / 2;
    const double s = h * sqrt(3.0 / 5);
    const double x0 = mid - s, x1 = mid + s;
    const double sum = 8.0/9 * f(mid) + (5.0/9)*(f(x0)+f(x1));
    return sum;
}



double f(double x) { return x*x; } // X^3/3 = 8/3 - 0/3 = 8/3 2.6666

// any polynomial < x^4 can be solved exactly by gauss2, any polynomial < x^6 can be solved exactly by gauss3
double f2(double x) { return x*x*x - x*x + 3;}
double f3(double x) { return x*x*x*x*x; }

// this is not exact with Gauss3
double f4(double x) { return x*x*x*x*x*x; }

double romberg(double (*f)(double), double a, double b, int n) {
   double I1 = trapezoidal(f, a, b, n);
   double I2 = trapezoidal(f, a, b, n*2);
   return (4*I2 - I1) / 3; // O(h^4)
}

int main() {
  cout << setprecision(16) << fixed;
  for (int n = 1; n < 1024; n *= 2)
    cout << n << '\t' << trapezoidal(f, 0, 2, n) << endl;

  cout << gauss2(f, 0, 2) << endl;
  cout << gauss3(f, 0, 2) << endl;

  cout << "F2:" << gauss2(f2, 0, 2) << "\t" << gauss3(f2, 0, 2) << endl;
  cout << "F3:" << gauss2(f3, 0, 2) << "\t" << gauss3(f3, 0, 2) << endl;
  cout << "F4:" << gauss2(f4, 0, 2) << "\t" << gauss3(f4, 0, 2) << endl;
  cout << "sin:" << gauss2(sin, 0, 2) << "\t" << gauss3(sin, 0, 2) << endl;

 // cout << "trapezoidal2: " << trapezoidal2(f, 0, 2, .0001) << endl;
}