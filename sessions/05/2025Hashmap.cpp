#include<iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

class HashMapLinearProbing {
private:
    struct Node {
        string key;
        int val;
    };
    Node* table;
    uint32_t capacity;
    uint32_t size;
    uint32_t hist[10];
    static uint32_t nextpowerof2(uint32_t n) {
        // 1,000,000
        // 0000000101101100101010101
        // 0000000100000000000000000
        // 0000000100001000001100101
        // 0000000010000100000110010
        // 0000000110001100001110111
        // 0000000001100011000011101
        // 0000000111101111001111111
        // 0000000000011110111100111
        // 0000000111111111111111111
        // +                       1
        n = (n | (n >> 1));
        n = (n | (n >> 2));
        n = (n | (n >> 4));
        n = (n | (n >> 8));
        n = (n | (n >> 16));
        return n+1;
    }
    void count_hist(uint32_t count) {
        if (count >= 10)
          count = 9; // 9 means 9 or greater
    }
public:
    HashMapLinearProbing(uint32_t capacity) : capacity(nextpowerof2(capacity)), size(0) {
        // make sure capacity is a power of 2
        table = new Node[capacity];
        capacity--; // store capacity-1 so we can and...
        for (int i = 0; i < 10; i++)
          hist[i] = 0;
    }
    ~HashMapLinearProbing() {
        delete [] table;
    }
    HashMapLinearProbing(const HashMapLinearProbing& orig) = delete;
    HashMapLinearProbing& operator =(const HashMapLinearProbing& orig) = delete;

    uint32_t hash(const string& key) const {
        uint32_t hashval = 0; // 0000000000000000000000000000000000000
        for (uint32_t i = 0; i < key.length(); i++) {
            hashval ^= key[i]; //00000000000000000000000000000kkkkkkkk
            // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
            // xxxxxxxxxxxxxxxxxxx0000000000000
            // yyyyyyyyyyyyyxxxxxxxxxxxxxxxxxxx
            // xxxxxxxxxxxxxxxxxxx0000000000000
            // 0000000000000000000yyyyyyyyyyyyy
            // xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyy
            hashval = hashval ^ ((hashval << 13) | (hashval >> 19));
            hashval = hashval ^ (hashval << 17) ^ (hashval >> 15);
        }
        return hashval & capacity; // % capacity;
    }

    void add(const string& key, int val) {
        uint32_t bin = hash(key);
        int count = 0;
        while (table[bin].key.length() > 0) {
            bin++;
            count++;
            if (bin >= capacity)
              bin = 0;
        } 
        table[bin].key = key;
        table[bin].val = val;
        count_hist(count);
    }
    const int* get(const string& key) {
        uint32_t bin = hash(key);
        uint32_t count = 0;
        while (table[bin].key.length() > 0) {
            count++;
            if (table[bin].key == key) {
                count_hist(count);
               return &table[bin].val;
            }
            bin++;
            if (bin >= capacity)
                bin = 0;
        }
        count_hist(count);
        return nullptr;            
    }
    void histogram() {
        for (int i = 0; i < 10; i++) {
            cout << i << ": " << hist[i] << '\n';
        }
        // print
        // 0 = 786,000
        // 1 = 210,823
        // 2 =   2,122
        // 3 =      95
        // 4 =       8
    }
};




void test_cpp_hashmaps() {
    unordered_map<string, int> dict;
    dict["apple"] = 1;
    dict["bear"] = 2;
    dict["cat"] = 3;
    dict["axis"] = 4;

    for (unordered_map<string,int>::iterator i = dict.begin(); i != dict.end(); ++i)
        cout << i->first << "==>"  << i->second << '\n';
    cout << "\n\n";

    for (auto e : dict) {
        cout << e.first << "==>" << e.second << '\n';
    }   
    cout << "\n\n";
    dict["zebra"] = 5;
    dict["yak"] = 6;
    dict["xylophone"] = 7;
    dict["walrus"] = 8;
    cout << "Has the order changed?\n";
    for (unordered_map<string,int>::iterator i = dict.begin(); i != dict.end(); ++i)
        cout << i->first << "==>"  << i->second << '\n';
    cout << "\n\n";

    for (auto e : dict) {
        cout << e.first << "==>" << e.second << '\n';
    }   
    
    unordered_map<string,int>::iterator i = dict.find("hello");
    if (i == dict.end()) {
        cout << "not present!\n";
    }
    const string key = "hello";
    for (int i = 0; i < 100000; i++) {
        auto x = dict.find("hello"); // this allocates a temp string to hold hello, about 3x slower
        if (x == dict.end()) {
           cout << "not present!\n";
        }
    }
    // c++20    if dict.contains("hello")
}
void test_linear_probing() {
    HashMapLinearProbing dict(1'000'000);
    ifstream f("dict.txt");
    string line;
    int i = 0;
    while (getline(f, line)) {
        dict.add(line, i);
        i++;
    }
    dict.histogram();
}

int main() {
//    test_cpp_hashmaps();
    test_linear_probing();

}