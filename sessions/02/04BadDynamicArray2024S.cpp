#include <iostream>
#include <cstdint>
#include <unistd.h>
using namespace std;

/*
    Author: Dov Kruger
    cite: helped by the whole class!
     Some even typed in vscode


    BadDynamicArray with copy constructor
    this list can copy itself

*/
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
    BadDynamicArray(const BadDynamicArray& orig) : data(new int[orig.size]), size(orig.size) {
 //       data = new int[orig.size];
 //       size = orig.size;
        for (int i = 0; i < size; i++)
          data[i] = orig.data[i];
    }
    BadDynamicArray& operator =(const BadDynamicArray& orig) {
        if (this != &orig) {
            delete [] data;
            data = new int[orig.size];
            size = orig.size;
            for (int i = 0; i < size; i++)
                data[i] = orig.data[i];
        }
        return *this;
    }
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
    void removeEnd() {
        size--;
    }    
    void removeStart() {
        
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
    BadDynamicArray b = a;
    BadDynamicArray c; // create an empty list
    c.addEnd(9);
    c = a;
    a = a;
    cout << c;

}