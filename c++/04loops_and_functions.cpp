/*
    Author: Dov Kruger
    Cite: I got MASSIVE HELP from ChatGPT. It basically rewrote everything.
    But I worked hard on this! I was just lost...
*/
#include <iostream>
#include <cstdint>
using namespace std;

//https://code.visualstudio.com/docs/cpp/config-mingw

int sum(int a, int b) {
    int sum = 0; // sum is a random value
    for (int i = a; i <= b; i++) {
      sum = sum + i;
      cout << i << ' ';
    }
    return sum;
}


int main() {
    int x = sum(1, 10); // 1 + 2 + 3 + ... + 10 = 55
    int y = sum(5, 7); // 5 + 6 + 7 = 18
    cout << x << " " << y << '\n';    
}