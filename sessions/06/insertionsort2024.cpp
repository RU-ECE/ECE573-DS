void insertionsort(int x[], int n) {
	// first step x[0] is sorted
	// pass 1 x[1]
	// if (x[1] < x[0]

	// 1 2 3 4 5
	// 2 1 3 4 5
	// temp= 1
	// x 2 3 4 5

	// 1 2 4 3
	// temp = 3
	// 1 2   4

	
	// 10 1 2 3 4 5 6 7 8 9
	// 10
	// 1  10
	// 1  2 10
	// 1  2 3 10
  // 10 9 8 7 6 5 4 3 2 1
	
	for (int i = 1; i < n; i++) {
		int temp = x[i]; // store x[i] out of the array
		for (int j = i-1; j >= 0; j--)
			if (temp < x[j])
				x[j+1] = x[j];
		  else {
				x[j] = temp;
				break; // GET OUT!!!
			}

}
