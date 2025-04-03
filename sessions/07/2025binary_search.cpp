#include <iostream>

using namespace std;

//       1, 3, 19, 26, 27, 91, 92, 105, 115, 145
//       L             guess                   R  
int binary_search(const int a[], int n, int target) {
    int L = 0, R = n-1;
    if (target < a[0] || target > a[n-1])
      return -1;
    do {
        int guess = (L + R) / 2;
        if (a[guess] > target) {
            R = guess-1;
        } else if (a[guess] < target) {
            L = guess+1;
        } else {
            return guess;
        }
    } while (L <= R);
    return -1;
}


int main() {
    int a[] = {
        1, 3, 19, 26, 27, 91, 92, 105, 115, 145
    };

    int target;
    cout << "Enter number to search for: ";
    cin >> target;
    int pos = binary_search(a, sizeof(a)/sizeof(int), target);
    cout << "pos=" << pos << '\n';
}