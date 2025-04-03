// 8 7 6 5 4 3 2 1 9 10


//O(n^2)  omega(n)

// 1 2 3 4 5 6 7 8 9 10
void bubblesort(int a[], int n) {

   for (int j = 0; j < n-1; j++) { //O(n)
     bool areWeDoneYet = true;
     for (int i = 0; i < n-1-j; i++) { //O(n) n-1 + ... + 1
        if (a[i] > a[i+1]) {
          swap(a[i], a[i+1]);
          areWeDoneYet = false;
        }
      }
      if (areWeDoneYet)
         return;
   }
}
//O(n^2) omega(n^2)
void selectionsort(int a[], int n) {

    for (int i = n-1; i > 0; i--) {
        // find the biggest one and put into [i]
        int max = a[0];
        int maxpos = 0;
        for (int j = 1; j <= i; j++) //O(n)
          if (a[j] > max) {
            max = a[j];
            maxpos = j;
          }
        // maxpos has the biggest value
        swap(a[i],a[maxpos]);
    }

}

// 1 2 3 4 5 2
// 1 2 2 3 4 5