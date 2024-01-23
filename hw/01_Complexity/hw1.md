# Complexity Homework

For questions 1-12, find the worst-case complexity

1.
```cpp
for (int i = 3; i <= n; i++) {
}
```
2.
```cpp
for (int i = 3; i <= n; i+= 5) {
}
```
3.
```cpp
for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= n; j++) {
  }
}
```
4.
```cpp
for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= i; j++) {
  }
}
```
5.
```cpp
for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= i/2; j++) {
  }
}
```
6.
```cpp
for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= i; j += 2) {
  }
}
```
7.
```cpp
for (int i = 1; i <= n; i *= 2)
{
}
```
8.
```cpp
for (int i = 1; i <= n; i *= 2) {
  for (int j = 1; j <= i; j++) {
  }
}
```
9.
```cpp
for (int i = 1; i <= n; i *= 3) {
}
```
10.
```cpp
for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= i; j *= 2) {
  }
}
```
11.
```cpp
for (int i = 1; i <= a; i++) {
  for (int j = 1; j <= b; j++) {
  }
}
```
12.
```cpp
for (int i = 3; i <= a; i += 4) {
  for (int j = 5; j <= b; j *= 2) {
  }
}
```
13.
```cpp
int f(int a) {
  for (int i = 3; i <= a; i += 4)
    if ((i * i + 3 * i + 2) % 2 == 0)
      return i;
}
```
14.
```cpp
bool isPrime1(int p) {
  for (int i = 2; i < p; i++)
    if (p % i == 0)
      return false;
  return true;
}
```
15.
```cpp
bool isPrime2(int p) {
  if (p == 2)
    return true;
  if (p % 2 == 0)
    return false;
  for (int i = 3; i < p; i += 2)
    if (p % i == 0)
      return false;
  return true;
}
```
16.
```cpp
for (int i = 3; i <= a; i += 4) {
  for (int j = 5; j <= b; j *= 2) {
  }
}
```
17. What is the complexity of the following code?

| Program |  |  |
| :--- | :--- | :--- |
|[Kadane](kadane.cpp)|O(________)|&Omega;(__________)|
|[Mandelbrot](mandel.cpp)|O(________)|&Omega;(__________)|
|[Shoelace Area](shoelace.cpp)|O(________)|&Omega;(__________)|
|[Floyd Warshall](floydwarshall.cpp)|O(________)|&Omega;(__________)|
|[Intersecting Boxes](intersectingboxes.cpp)|O(________)|&Omega;(__________)|

