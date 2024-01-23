#include <iostream>
using namespace std;
void g() {
    const int n = 1000;
    int* a = new int[n*n*n];

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                a[i*n*n + j*n + k] = c++;
            }
        }
    }
    for (int i = 0; i < n*n*n; i++)
      a[i] = i;
}

uint64_t factorial(uint64_t n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    for (int i = 0; i < 30; i++)
        std::cout << i << '\t' << factorial(i) << std::endl;
    return 0;
}
// n! = n * (n-1)!
