#include <iostream>
#include <cstdlib>
using namespace std;

void insertionsort(int a[], int n) {
    int temp;
    for (int i = 1; i < n; i++) {
        temp = a[i]; // remember this one
//        if (temp >= a[i-1])
//          continue;
        // temp must be inserted somewhere in the middle
        for (int j = i - 1; j > 0; j--) {
          if (temp > a[j]) {
            a[j+1] = temp;
            goto doneinserting;
          }
          a[j+1] = a[j];
        }
        a[0] = temp;
doneinserting: ;
    }
}
//n = 100
//n=50
//n=25

//pathological choice of pivot!
// 1 2 3 4 5 6 7 8  pivot = a[0]
// 1 | 2 3 4 5 6 7 8 pivot = a[1]
// 1 2 || 3 4 5 6 7 8

// pivot = (a[first] + a[last])/2 still pathological case...
// 7  5   4   1  2  3    6  
//pivot = a[first] + a[last] + a[(first+last)/2]) / 3

//1          3             2

//1  4  3  2  5
//   ij

// 8 7 6 5 4 3 2 1
// 1 2 3 4  5   6  7   8

// 1st iteration n = 1'000'000 1 function call
//last iteration n = 1 1 million function calls, NOTHING TO DO
// last few times:

//    1 3 2

// pivot = a[random] is the best one!!!
void quicksort(int a[], int L, int R) {
    int i = L, j = R;
    int pivot = a[L+rand()%(R-L+1)];
    while (i < j) {
        while (i < j && a[i] < pivot)
            i++;
        while (i < j && a[j] >= pivot)
            j--;
        // we found two numbers to swap!!!
        if (i < j) {
            swap(a[i], a[j]);
            i++, j--; // move to the next elements, these are DONE!
        }
    }
    // i = j = 1
    if (i-1 > L)
        quicksort(a,L, i-1); // check edge conditions!!!
    if (R > i)
        quicksort(a, i, R);
}

void partial_quicksort(int a[], int L, int R) {
#if 0
if (i-1 > L + 100)
    partial_quicksort(a,L, i-1); // check edge conditions!!!
if (R > i + 100)
    partial_quicksort(a, i, R);
#endif
}

void knuth_optimized_quicksort(int a[], int n) { //O(n log n)
    // about 30% less than quicksort
    partial_quicksort(a, 0, n-1); //
    insertionsort(a, n); //O( ???  )
}

void testcase(int a[], int n) {
    insertionsort(a, n);
    for (int i = 0; i < n; i++)
      cout << a[i] << '\t';
    cout << '\n';
}

int main() {
    int a1[] = {1, 2, 3, 4, 5, 6};
    int a2[] = {1, 2, 3, 4, 5, 6, 7};
    int a3[] = {5, 4, 3, 2, 1};
    int a4[] = {1, 3, 2, 5, 19, 2, 1};
#if 0
    testcase(a1, sizeof(a1)/sizeof(int));
    testcase(a2, sizeof(a2)/sizeof(int));
    testcase(a3, sizeof(a3)/sizeof(int));
    testcase(a4, sizeof(a4)/sizeof(int));
#endif
    quicksort(a3, 0, 4);
    for (int i = 0; i < 5; i++)
      cout << a3[i] << '\t';
    cout << '\n';
}
