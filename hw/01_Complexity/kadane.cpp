#include <iostream>
#include <cstdlib>
using namespace std;

int kadane(const int x[], int n) {
    int maxSumSoFar = x[0];
    int maxSumEndingHere = x[0];
    for(int i = 1; i < n; i = i+1) {
      maxSumEndingHere = max(maxSumEndingHere + x[i], x[i]);
      if(maxSumSoFar < maxSumEndingHere)
        maxSumSoFar = maxSumEndingHere;
    }
    return maxSumSoFar;
}