int main() {
	for (int i = 0; i < n; i += n/2) { //O(1)

	}

	n=2000
	for (int i = 0; i < n; i += n/1000) { //O(1)

	}
n = 100 50 25 12 6 3 1
	for (int i = n; i > 1; i /= 2) { //O(logn)
	}

	for (int i = 1; i <n; i *= 2) { //O(logn)
	}

	for (int i = 0; i <n; i *= 2) { // INFINITE LOOP!
	}

}

/*
	1 + 2 + 4 + 8 + ... + n/2 + n
 n(1/n + 2/n + 4/n + .. + 1)


  .1
  .01
  .001
  .1111111

fact(5) = 5*fact(4)
fact(4) = 4*fact(3)
fact(3) = 3*fact(2)
fact(2) = 2*fact(1)
fact(1) = 1
 */

n=100
int f(int n) { // O(log n)
	if (n < 5)
		return 19;
	return n + f(n/2);
}
