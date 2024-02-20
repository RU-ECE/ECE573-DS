#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class HashMap {
private:
    const static string EMPTY;
    uint32_t hash(const string& k) {
        uint32_t h = 0;
        for (char c : k) { // "abc"   h=((0*31+97)*31+98)*31+99 
            h = h*31 + c;
//            h = (h >> 15) ^ (h << 17)
        }
        return h;
    }
    int hist[10] = {0};
    struct Entry {
        string key;
        int value;
        Entry(const string& k, int v) {
            key = k;
            value = v;
        }
        Entry() : key(EMPTY), value(0) {}
    };
    Entry* table;
    uint32_t size;     // number of entries inserted into the table
    uint32_t capacity; // number of bins in the table
    void rehash() {
      //TODO: you grow, infinite loop unless you fix this....  
    }
    void countHist(int count) {
        if (count>= 10)
            count = 9;
        hist[count]++;
    }
public:
    HashMap(uint32_t c = 1024) : size(0) {
        c = c | (c >> 1);
        c = c | (c >> 2);
        c = c | (c >> 4);
        c = c | (c >> 8);
        c = c | (c >> 16);
        c++;
        capacity = c;
        //TODO: make sure c is power of 2
        // capacity =   1010111010101010
        // capacity =  10000000000000000
        // capacity = 1 << (bitfindfirstone(capacity)+1)
    //        int bits; // assume bits != 0
        // 1xxxxxxxxxxxxxx1xxxxxxxxx
        //  1xxxxxxxxxxxxxx1xxxxxxxx
        //bits = bits | (bits >> 1);
        //bits = bits | (bits >> 2);
        //bits = bits | (bits >> 4);
        //bits = bits | (bits >> 8);
        //bits = bits | (bits >> 16);
        //bits++;
        // see: Stanford Bit twiddling for more fun
        //https://graphics.stanford.edu/~seander/bithacks.html
        // 1111111111111111111111111
        

        table = new Entry[c];
    }
        
    ~HashMap() {
        delete[] table;
    }
    HashMap(const HashMap& other) =delete;
    HashMap& operator =(const HashMap& other) =delete;

    void put(const string& k, int v) {
        int count = 0;
        uint32_t index = hash(k) & (capacity - 1); //TODO: REQUIRES POWER OF 2!!!
        while (table[index].key != EMPTY) { //collision?
            if (table[index].key == k) {
                table[index].value = v;
                countHist(count);
                return;
            }
            count++;
            index = (index + 1) & (capacity - 1);
        }
        table[index] = Entry(k, v);            
        size++;
        countHist(count);
        hist[count]++;
        if (size*2 > capacity) {
            rehash();
        }
    }

    bool containsKey(const string& k) { //O(1)
        uint32_t index = hash(k) & (capacity - 1);
        int count = 0;
        while (table[index].key != EMPTY) {
            if (table[index].key == k) {
                countHist(count);
                return true;
            }
            count++;
            index = (index + 1) & (capacity - 1);
        }
        countHist(count);
        return false;
    }
#if 0
//good C++ performance trick: write code that does not require dynamic
// allocation of strings
    bool containsKey(const char*k, uint32_t len) { //O(1)
        uint32_t index = hash(k, len) & (capacity - 1);
        while (table[index].key != EMPTY) {
            if (table[index].key == k) {
                return true;
            }
            index = (index + 1) & (capacity - 1);
        }
        return false;
    }
#endif

    int* getValue(const string& k) {
        uint32_t index = hash(k) & (capacity - 1);
        while (table[index].key != EMPTY) {
            if (table[index].key == k) {
                return &table[index].value;
            }
            index = (index + 1) & (capacity - 1);
        }
        return nullptr;
    }
    void printHist() const {
        for (int i = 0; i < 10; i++) {
            cout << i << '\t' << hist[i] << "\n";
        }
    }
    uint32_t getCapacity() const { return capacity; }
};

const string HashMap::EMPTY = "";



int main() {
    HashMap m(500);
    cout << m.getCapacity() << '\n';
    m.put("hello", 1);
    m.put("bye", 2);
    m.put("hello", 3);
    cout << m.getValue("hello") << endl;
    cout << *m.getValue("hello") << endl;
    cout << m.getValue("bye") << endl;
    cout << *m.getValue("bye") << endl;
    cout << m.getValue("x") << endl;

    int* p = m.getValue("x");
    if (p != nullptr) {
        *p = 99;
    }
    m.printHist();
}