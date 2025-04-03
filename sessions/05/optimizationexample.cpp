#include <iostream>
using namespace std;
int f(int x);

int h(int x, int y) {
  return x * y;
}
void g() {
    
}
int main() {
    int y = f(2); // 4
    cout << y << '\n';
    h(2,3);
}


int f(int x) {
    return x*x;
}