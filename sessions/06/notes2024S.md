O(n^2)  omega(n)

int a = 3, b = 4;

a = a + b; //a=7
b = a - b; // b = 3
a = a - b; // a = 4

A  B   A XOR B
0  0   0
0  1   1
1  0   1
1  1   0

a = 3, b = 5;
011       101

a = a ^ b     011
             ^101
	     =110 = 6
b = a ^ b =   011 = 3
a = a ^ b


O(n) + O(n-1) + O(n-2) + ... + 1

n elements
2 "swaps" out of order  O(n)

1 2 3 4 7 6 5 8 10 9
1 2 3 4 6 7
          5 7 8 10
	        9  10
1 2 3 4 6 5 7 8 9  10
1 2 3 4 6
        5 6 7 8 9  10
1 2 3 4 5 6 7 8 9  10





given n elements, and n/2 pairs each out of order by only 1 position
2 1 4 3 6 5 8 10 9
1 2 3 4 5 6 8 9 10

1..52

51  1 15 13  52 ... 3
for (int i = 0; i < 52; i++)
a[i] = i+1;

n=10^9 elements, each 0 or 1

1 0 0 1 0 0 0 0 0 1 1 1 1 0 1 0 1 ....

000000000000000000000000000000000000000000000000111111111111111111111

n = 10^12
1000000000000! = ???
1000000000000! MOD 10 =
1*2*3*4*5 = 120
*6 = 720
*7 = 4940
*10     00
n! MOD 10 =  0

userid =  cs.dov.kruger





