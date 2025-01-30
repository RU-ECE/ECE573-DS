#include <iostream>
#include <cstdint>
using namespace std;

//https://code.visualstudio.com/docs/cpp/config-mingw

int main() {
    {
        int a;        // >= 16 bits, usually 32-bits on laptops
        short int b;
        long int c;
        long long int d;
        short e;
        long f;
        char g;
    }
    // all the above can be unsigned or signed

    // new portable integer types
    {
        uint8_t a = 1; // 8bit unsigned
        uint16_t b = 65535; // 16-bit unsigned 
        uint32_t c = 4294967295; // 32-bit unsigned
        uint64_t d = 18446744073709551615U; // 64-bit unsigned

        int8_t e = -128; // 8-bit signed
        int16_t f = -32768; // 16-bit signed
        int32_t g = -2147483648; // 32-bit signed
        int64_t h = -94467440737095516LL; // 64-bit signed

        cout << "sizeof(uint8_t): " << sizeof(uint8_t) << '\n';
        cout << "sizeof(uint16_t): " << sizeof(uint16_t) << '\n';
        cout << "sizeof(uint32_t): " << sizeof(uint32_t) << '\n';
        cout << "sizeof(uint64_t): " << sizeof(uint64_t) << '\n';

        cout << a << " " << b << " " << c << " " << d << '\n';
        cout << e << " " << f << " " << g << " " << h << '\n';
    }
}