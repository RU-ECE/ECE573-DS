/*
pivot = x[L]
pivot = (x[L] + x[R])/2
1 2 3 4 5 6 7 8
1 3 5 7 8 6 4 2

pivot = x[(L+R)/2]
1 2 3 4 5 6 7 8 9 10
        8 10 9







 10 9 8 7 6 5 4 3 2 1
pivot=x[5] = 6
   i                  j
   1                  10
     i              j
     2              9
       i          j
       3          8
         4      7
           5 6
    1 2 3 4 5   6 7 8 9 10


  10 8 6 4 2 0 1 3 5 7 9
pivot=1
  i                    j
               j
  1            10
     i       j
     0       8
       i   j
       ij
  1  0 6 4 2 8 10 3 5 7 9
       i
 */

int partition(int x[], int L, int R) {
	int r = random(L, R);
	int pivot = x[r];
	int i = L, j = R;
	while (i < j) {
		while (x[i] < pivot)
			i++;
    while (x[j] > pivot)
			j--;
		if (i < j) {
      swap(x[i], x[j]);
			i++; // ignore the ones we just swapped, move on 
			j--;
		}
	}
	return i-1;
}


// sort array x between positions L and R
void quicksort(int x[], int L, int R) {
	int m = partition(x, L, R);
	if (m>L)
		quicksort(x, L, m);
	if (R > m+1)
		quicksort(x, m+1, R);
}

int main() {
	int[] a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	quicksort(a, 0, 9);
}

/*
	Lomuto partitioning Scheme

	10 3 8 7 5 4 6 9 2 1
pivot = x[4] = 5
  10 3 8 7 1 4 6 9 2 5
  i                  j
  5                  10
     i             j
  2                5
       i
       5           8
             j
       4     5
         i j
         5   7
         1 5
  2 3  4 1 5 7 6 9 8 10

 */
