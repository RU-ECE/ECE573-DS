# Matrix notes

## underdetermined system of equations

1 2  0 5        x + 2y + 0z + 5w = ?
2 -1 2 1        2x - y + 2z + w = ?
3 2  4 1        3x + 2y + 4z + w = ?

## overdetermined system of equations

1 2  3  = 4
2 -1 1  = 5
3 1  2  = 7
2 2  -1 = 0
2 2.1 -1.2 = 1

least squares
PCA is based on SVD  which is based on Gram-Schmidt 


## matrix multiple is O(mnp)
  A (m x n)   B (n x p) 
3 2 1    *     1  2  9   -4
1 2 -1         5  4  1    8
               7  -3  0   3


if m=n=p
O(n^3)



a * a^-1 = 1
5 * 1/5 = 1

0* ? = 1



## Splines

A spline is a piece of wood

A numeric spline is a piecewise polynomial simulating the wood
t is a parameter between 0 and 1

$f_0 = a_0t^3 + b_0t^2 + c_0t + d_0$

$f_0(0) = X_0$

$f_0(1) = X_1$

$f'_0 = 3a_0t^2 + 2b_0t + c_0$


$f_1 = a_1t^3 + b_1t^2 + c_1t + d_1$
$f_1(0) = X_1$
$f_1(1) = X_2$

$f'_1 = 3a_1t^2 + 2b_1t + c_1$
$f''_1 = 6a_1t + 2b_1$
$f''_0(1) = f''_1(0)$

$f_0(1) = f_1(0)$
$f'_0(1) = f'_1(0)$


$f''_0(0) = 0$
$f''_2(0) = 0$

### Diagonal Matrix
*  0  0  0  0  0
0  *  0  0  0  0
0  0  *  0  0  0
0  0  0  *  0  0
0  0  0  0  *  0
0  0  0  0  0  *

### End up with a tridiagonal matrix

n x n matrix.  How big is the diagonal? n 
off diagonals (adjacent) = n-1
n + n-1 + n-1 = 3n-2

   *  *  0  0  0  0
   *  *  *  0  0  0
   0  *  *  *  0  0
   0  0  *  *  *  0
   0  0  0  *  *  *
   0  0  0  0  *  * 

m(r, c) = mem[3r + (c - r) + 1] = mem[2r + c + 1]

int get(int r, int c) {
    if (abs(r-c) > 1)
      return 0;
    return mem[2r + c + 1];
}

O(n)

a  b  0  0  0       a  b  0  0  0       2 +   
c  d  e  0  0       c  d  e  0  0       2
0  f  g  h  0   x   0  f  g  h  0       1
0  0  *  *  *       0  0  *  *  *       0
0  0  0  *  *       0  0  0  *  *       0



## Gram-Schmidt

Make a matrix orthogonal (perpendicular) and all vectors unit (normal)

orthonormal

x   5  2
y   0  6

(5,0) ==> unit vector? 
calculate length of vector (sqrt(5^2 + 0^0)) = 5

mag(v) = O(n)
subtract components of vector from each other O(n^2)


## Mapping For matrices
   nxn matrix
a b c d
e f g h
i j k l
m n o p


// row major order
int get(int r, int c) {
    return mem[r*n + c];
}

// col major order
int get(int r, int c) {
    return mem[c*n + r];
}

## Least Squares
Time    y
0       0
1       1.1
2       1.95
3       3.22
4       3.99


## What is Gram-Schmidt for?

Singular Value Decomposition (SVD)


## PCA (Principal Component Analysis)


