#include <iostream>
#include <cmath>

using namespace std;
constexpr double phi = (1 + sqrt(5)) / 2; // 1.618...
constexpr double invphi = 1 / phi;
uint32_t golden_mean_search(const int a[], int n) {
    uint32_t L = 0, R = n-1;

    int S = int((R - L + 1) * invphi);

    int X = R - S;
    int Y = L + S;
    do {
        cout << "L=" << L << "X=" << X << " Y=" << Y << " R=" << R << '\n';
        if (a[X] > a[Y]) {
            R = Y;
            Y = X;
            S = int((R - L + 1) * invphi);
            X = R - S;
        } else {
            L = X;
            X = Y;
            S = int((R - L + 1) * invphi);
            Y = L + S;    
        }
    } while (L < R);
    return L;
}

double f(double x) {
    return 40 - (x-4.5)*(x-4.5);
}


template<typename Func>
double golden_mean_continuous(Func f, double L, double R, const double eps) {
    double S = (R - L) * invphi;
    double X = R - S, Y = L + S;
    double fx = f(X), fy = f(Y);

    do {
        if (fx > fy) {
            R = Y;
            S = (R - L) * invphi;
            Y = X;
            fy = fx;
            X = R - S;
            fx = f(X);
        } else {
            L = X;
            S = (R - L) * invphi;
            X = Y;
            fx = fy;
            Y = L + S;
            fy = f(Y);    
        }
        cout << "L=" << L << "\tX=" << X << "\tY=" << Y << "\tR=" << R << '\n';
    } while (R - L > eps);    
    return X;
}

int main() {
    cout << "answer=" <<    golden_mean_continuous(f, 2, 80, .1) << '\n';

}