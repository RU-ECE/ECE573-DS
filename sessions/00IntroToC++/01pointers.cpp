#include <iostream>
using namespace std;

void allocme(int n) {
    int* p = new int[n];
}

int main() {
    uint32_t a = 2;
    uint32_t* p = &a; // p is a pointer to a 32-bit int. initialize to address of a
    cout << *p << '\n';
    cout << p << '\n';
 //   delete p; // crash! (segfault?)
    *p = 3;
    cout << a << '\n';

    const uint32_t* q = &a; // q is a read-only pointer to a 32-bit int. initialize to address of a
    a = 5;
    *p = 19;

    uint32_t* const r = &a; // r is a const pointer to a 32-bit int which can be written
    *r = 99;

    int* x = new int[100]; // x is a pointer to an array of 100*4 bytes
    double* y = new double[100]; // y is a pointer to an array of 100*8 bytes

    delete[] x;
    delete[] y;


    x = (int*)malloc(1024*sizeof(int)); // 1024*4 bytes
    free(x);
    for (int i = 0; i < 10000; i++)
        allocme(1000);

    

}