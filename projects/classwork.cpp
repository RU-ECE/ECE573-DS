CATS to MICE (4 steps)
CATS
MATS
MATE
MITE
MICE


blag
bag
brag


ababababababababababababababababababab = n
abababaa = m
  abababaa
    abababa

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaab
worst case complexity of brute force search

O(mn)

k=9
testing testing avenue avalanche.
                        =      =


avalanche
a  4
b  9
c  2
d  9
e  0
f  9
g  9
h  1
i  9
j  9
k  9
l  5
m  9
n  3
o  9
p  9
q  9
r  9
s  9
t  9
u  9
v  7
w  9
x  9
y  9
z  9



boyerMoore(const char text[], const char pattern[]) {
  int offsets[256];
  int k = strlen(pattern);
  for (int i = 0; i < 256; i++)
    offsets[i] = k;
  for (int i = 0; i < k; i++)
    offsets[pattern[i]] = k - 1 -  i;
  
}