#include <iostream>
using namespace std;

/*
 Compute the combinations of n things taken r at a time
    n! / ((r!)(n-r)!)
*/
uint64_t nCr(uint32_t n, uint32_t r) {
  //TODO: students do this...
}

uint64_t fact(uint32_t n) {
    //TODO: return n!
}


int main() {
    cout << nCr(52, 6) << '\n'; // 52! 
    cout << nCr(6, 3) << '\n'; // 6!/(3!3!) = 6*5*4*3*2*1/(3*2*3*2) = 6*5*4/(3*2) 
    return 0;
}