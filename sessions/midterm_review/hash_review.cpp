#include <iostream>
using namespace std;

class LinearChaining {
private:
    struct node {
        int key;
        int val;
        node* next;
    };
    node** table;
    uint32_t capacity;
    uint32_t size;
public:
    LinearChaining(uint32_t initial_capacity : capacity(initial_capacity) {
        table = new node*[capacity];
        for (int i = 0; i < capacity; i++)
          table[i] = nullptr;
    }
    ~LinearChaining() {
        for (int i = 0; i < capacity; i++) {}
          
    }
    void hist() {
        int counts[10] = {0};
        for (int i = 0; i < capacity; i++) {
            node* p = table[i]; // head
            int count = 0;
            while (p != nullptr) {
                count++;
                p = p->next;
            }
            counts[count]++;
        }
          
    }
};

class LinearProbing {
private:
    int* keys;
    int* val;
    uint32_t capacity;
    uint32_t size;
    uint32_t counts[10];
    int hash(int key) {
        return ???;
    }
public:
    LinearProbing() {
        for (int i = 0; i < 10; i++)
            counts[i] = 0;

    }
    void add(int key, int val) {
        int bin = hash(key);
        int count = 0;
        while (keys[bin] != key) {
            if (keys[bin] == 0) {
                keys[bin] = key;
                counts[count]++;
                return;
            }
            bin++:
            if (bin >= capacity)
              bin = 0;
            count++;
        }
    }

    int get(int key) {
        int bin = hash(key);
        int count = 0;
        while (keys[bin] != key) {
            if (keys[bin] == 0) {
                keys[bin] = key;
                counts[count]++;
                return;
            }
            bin++:
            if (bin >= capacity)
              bin = 0;
            count++;
        }
    }


    void hist() {
        for (int i = 0; i < 10; i++)
            cout << i << ": " << counts[i] << endl;
    }
};