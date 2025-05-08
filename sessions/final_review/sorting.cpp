#include <iostream>
using namespace std;
void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}


void quiksort(int a[], int left, int right) {
    int select_pivot = random(left, right); // random is the only correct choice!
    int pivot = a[select_pivot]; // AI picked REALLY STUPID pivot!
    int i = left, j = right;
    while (i <= j) { // original Hoare partition
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    // verify if [left, i-1] and [i, right] are correct bounds
    if (i < j) {
        quiksort(a, left, i-1);
    }
    if (i < right) {
        quiksort(a, i, right);
    }
}

void heapsort(int a[], int n) { //O(n log n)
    for (int i = n / 2 - 1; i >= 0; i--) { // O(n/2 log n)
        heapify(a, i, n);
    }
    for (int i = n - 1; i >= 0; i--) { //O(n log n____)
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }

}

void heapify(int a[], int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

int main() {
    int a1[] = {1, 2, 3, 4, 5, 7, 6, 8, 9, 10}; // almost sorted
    insertion_sort(a1, 10); // O(______________)
    print(a1, 10);
    int a2[] = {10, 2, 3, 4, 5, 7, 6, 8, 9, 1}; // 1st, last and one in the middle
    insertion_sort(a2, 10); // O(______________)
    print(a2, 10);


    heapsort(a1, n); // O(n log n)
}