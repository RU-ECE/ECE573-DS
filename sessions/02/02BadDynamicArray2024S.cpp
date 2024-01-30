#include <iostream>
#include <cstdint>
#include <unistd.h>
using namespace std;

class BadDynamicArray {
private:
    int* data;
    uint32_t size;
public:
    BadDynamicArray() : data(nullptr), size(0) {
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

    void insert(int ind, int v) {
        const int* old = data;
        data = new int[size+1];
        for (int i = 0; i < ind; i++)
          data[i] = old[i];    
        data[ind] = v;
        for (int i = ind; i < size; i++)
          data[i+1] = old[i];
        delete [] old;
        size++;
    }
    
    void addStart(int v) {
        int* old = data;
        data = new int[size+1];
        data[0] = v; 
        for (int i = 0; i < size; i++)
            data[i+1] = old[i];
        delete [] old;
        size++;
    }
    
    friend ostream& operator <<(ostream& s, const BadDynamicArray& list) {
        for (int i = 0; i < list.size; i++)
          s << list.data[i] << ' ';
        return s;
    }
};

int main() {
    BadDynamicArray a;
    const int q = 10;
    for (int i = 0; i < q; i++)
        a.addEnd(i);
    a.addEnd(3);
    a.addEnd(1);
    a.addEnd(4);
    a.addStart(9);
    a.insert(2, 8); //9 0 8 1 2 3 4 5 6 7 8 9 3 2 1 4
    cout << a;
}