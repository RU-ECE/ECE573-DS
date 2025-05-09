void heapsort(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) { //O(n/2 log n) = O(n log n)
        make_heap(a, i, n); //O(log n)
    }
    // the array is a heap, a[0] is the largest element

    for (int i = n - 1; i >= 1; i--) { // O(n log n)
        swap(a[0], a[i]);
        make_heap(a, 0, i); // O(log n)
    }
}

//  1 2       3     4 5 6 7 8 9 10
//  i 2i+1   2i+2
//  0 1       2

/*
            3
        2        1    




*/




void make_heap(int a[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        make_heap(a, largest, n);
    }
}