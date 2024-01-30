#include <iostream>
#include <cstdint>
#include <unistd.h>
using namespace std;

class BadDynamicArray {
private:
    int* data;
    uint32_t size;
public:
    BadDynamicArray() {
        data = nullptr;
        size = 0;
    }
    ~BadDynamicArray(){
        delete [] data;
    }
    BadDynamicArray(const BadDynamicArray& orig) = delete;
    BadDynamicArray& operator =(const BadDynamicArray& orig) = delete;
    void addEnd(int v) {
        int* old = data;
        data = new int[size+1];
        for (int i = 0; i < size; i++)
            data[i] = old[i];
        data[size] = v;
        delete [] old;
        size++;
    }
    friend ostream& operator <<(ostream& s, const BadDynamicArray& list) {
        for (int i = 0; i < list.size; i++)
          s << list.data[i] << ' ';
        return s;
    }
};

void f() {
    BadDynamicArray a;
    a.addEnd(3);
    a.addEnd(1);
    a.addEnd(4);
    cout << a;
//    BadDynamicArray b = a;
//    BadDynamicArtay c(a);
    BadDynamicArray x;
//    x = a; //operator =
 //   int w = 2;
 //   w = 3;
}

int main() {
    f();
#if 0
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 1'000'000; i++)
            f();
        cout << "allocated\n";
        sleep(5);
    }
#endif
}