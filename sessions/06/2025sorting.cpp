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

// 7 9 8 10 6 5 4 1 2 3
// pivot = random =4
// put pivot to one side
// 7 9 8 10 6 5 3 1 2 4
// i                j p
// 4                  7
// p i              j
// 2                4
//   i            j p
//   4              9
//   p i          j
//   1            4
//     4          8
//     3        4
//       4      10
// 2 1 3 4 6 5 10 8 9 7
//[2 1 3] [6 5 10 8 9 7]           
void quicksort_lomuto(int a[], int L, int R) {
    int i = L, j = R;
    int pivot = a[L+rand()%(R-L+1)];
// partition lomuto...

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

/*

1 2 3 4 5 6 7 8 9 3


                1
        2                3
      4    5           6   7 
     8 9  3


                9
        8                7
      4    5           6   3 
     2 1  3

     9 8 7 4 5 6 3 2 1 3

                7
        5                6
      4   3           1   3 
     2   
n = 9

n=8
                      7  8  9

*/

// merge 2 arrays a,b of size n into c[2n]
//                   1 3   2 5
//                   i     j
// c=1 2 3 5
//   k

// 
//   a = [1 2]   b = [3 4]
//        i           j
void merge(intc[], const int a[], const int b[], int c[], int n) {
  int i = 0, j = 0, k = 0;
  while (i < n && j < n) {
    if (a[i] > b[j]) {
        c[k++] = b[j++];
    } else {
        c[k++] = a[i++];
    }
  }
  while (i < n)
    c[k++] = a[i++];
  while (j < n)
    c[k++] = b[j++];  
//  c[k++] = a[i] > b[j] ? b[j++] : a[i++];
}

// 2 1   3 4    6 4    9 8
// 1 2   3 4    4 6    8 9
// 1 2   3 4


// n bits
// 0 0 1 0 1 1 0 1 1 0 0 0 1 0 1
// 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1
void radix(int a[], int n) {
  int hist[10] = {0};
  for (int i = 0; i < n; i++)
    hist[a[i]]++;

}