1. Complexity
  a. iteration
  b. recursion
  c. amortized cost (when it is not the same every time)
```c++
//probabilistic estimation
inefficient_shuffle(a, n) //O(n^2)
  list out(n)
  for i = 0 to n-1 //O(n)
    do
      r = random(0, n-1)
    while a[r] != -1 // 1, 1, 1, 1, 1, 1     n, 2n, 3n
    out[i] = r
    a[r] = -1;
  end
```

```c++
class DynamicArray {
   private:
    int* data;
    int capacity;
    int size;
  void addEnd(int v) { //O(1) amortized
    if (size >= capacity) {
      grow(); // O(size)
    }
    data[size++] = v; //O(1)

  }
}
// 1 2 3 4 
// 1 2 3 4 5 6 7 8   n + 1 + 1 + 1 + n + 1 + 1 + 1 + 1 + 1 + 1 
```

```c++
f(a, b)
  if a < 29
    return a*a
  end
  if b < 50
    return f(a*100, b-1)
  end
  return f(a-1, b-5)
end

f(1,1)
f(50,50)
f(30, 80)
g(a)
  if a < 29
    return a*a
  end
  return f(a / 3)
end

h(n)
  if n < 17
    return 110
  end
  return h(n-2) + h(n-4) + h(n-6) //O(3^n))
end


```

2. Dynamic Array
3. Linkedlist, queue, stack
4. Binary trees, Tries (No RB Tree)
  a. inorder, preorder, postorder
  b. insert into ordered BST
5. Hashing (linear probing, linear chaining, perfect hashing)

```text
function hash(x) = x mod n
example: perfect hashing: 8, 16, 24, 9, 17
n=8
table = [8,16,24, 9,17, _, _, _, _, _, _]

table = [_, _, _, _, _, _, _, _]

8 mod 3 = 2, 16 mod 3 = 1 24 mod 3 = 0
table[0] = (n=3)[24, 16, 8]

9 mod 3 = 0, 17 mod 3 = 2
table[1] = (n=3)[9, _, 17]



```
6. Sorting (insertion, quicksort, heapsort, mergesort)
   a.  Shuffling (Fischer-Yates)
   b. Binary search
7. Strings
   a. fast string search Boyer-Moore O(n/k)
   b. Finite State Machine (regex)
   c. LCS
```c++
target="encyclopedia"
this is a test. testing testing 123
           a
              a
              ___________a
                         ___a
                            _a

a=12
b=12
c=9
d=12
e=11
f=12
g=12
h=12
i=12
j=12
k=12
l=12
m=12
n=10
o=12
p=12
q=12
r=12
s=12
t=12
u=12
v=12
w=12
x=12
y=8





```
8. backtracking (2 algorithms permute, Heap's)
9. Matrices
   a. matrix multiplication
   b. Gauss-Jordan elimination
   c. Partial pivoting
   d. Know full pivoting, but you don't have to write pseudocode
   d. Gram-Schmidt
```c++
matmult(a, b, c)
  for (int k = 0; k < n; k++) {
    for (int j = 0; j < n; j++) {

      float dot = 0;
      for (int i = 0; i < n; i++)
         dot += a(k, i) * b(i, j)
      c(k,j) = dot
    }
  }
```

```c++
example: 3 variables. 3 unknowns. x is a vector
Ax = B

x = [1, 2, 3]

A = [1 4 -2    [1]    [3]
     2 0 1   *  2 =    5
     3 1 2]     3      11

     B = [3;5;11]

1 4 -2             3
2 0 1   * X =      5
3 1 2             11

partial pivoting
.001  2    -1      3
2     -1    2      5
3     1     2     11

.001  2       -1      3
0     -4001    2002   -5995    // the second row is almost a linear multiple of the first (ill-conditioned)
3     1        2     11

partial pivoting: swap the biggest number to use as the pivot
3     1     2     11
.001  2    -1      3
2     -1    2      5

3     1            2     11
0     2-1/3000    -1-2/3000      3-11/3000   (much more numerically stable)
2     -1    2      5


know what full pivoting is, but you will not have to write pseudocode

3      1  2
.001   5  6
2     -2  3

1. find the biggest number in the matrix O(n^2)
2. swap rows

.001   5  6
3      1  2
2     -2  3

3. swap columns (and keep track of columns:
0      1  2   // these numbers track which column is originally which
.001   5  6
3      1  2
2     -2  3

2      1  0   // these numbers track which column is originally which
6      5  .001
2      1  3
3     -2  2


6      5      .001
0      1-5/3  3-.001/3
0     -2-5/2  2-.001/2

```

10. Graph theory
   a. DFS/BFS (iterative)
   b. Bellman-Ford
   c. Floyd-Warshall
   d. Prim/Kruskal
11. Number-theoretic
   a. gcd (Euclid)
```c++
gcd(a,b)
  if b == 0
    return a
  end
  return gcd(b, a mod b)
end

gcd(12,18) = gcd(18, 12) = gcd(12, 6) = gcd(6, 0) = 6

```
   b. power, powermod
   c. sieve of Eratosthenes
   d. Miller-Rabin
   e. Know what a Carmichael number is
     (square-free, not prime, acts  like a prime for the purpose of Fermat's test)  powermod(a, p-1, p) = 1
     false positive for Fermat's theorem

     1st Carmichael number 561 = 3 * 11* 17
     powermod(2, 560, 561) = 1 prime?
     powermod(3, 560, 561) != 1 (3 is one of the factors of 561)
     powermod(13, 560, 561) = 1
12. Numerical
   a. root finding (bisection)
   b. newton's method
   c. trapezoidal
