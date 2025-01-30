#include <iostream>

class BadDynamicArray {
private:
    int* data;
    uint32_t len;
public:
    BadDynamicArray() { //O(1)
        data = nullptr;
        len = 0;
    }

    ~BadDynamicArray() {
        delete [] data;
    }

    BadDynamicArray(const BadDynamicArray& orig) = delete;

    void addEnd(int v) { //O(len)
        const int* old = data;
        data = new int[len+1];
        for (int i = 0; i < len; i++)
          data[i] = old[i];
        data[len] = v;
        delete [] old;
        len++;
    }

    void addStart(int v) { //O(len)
        const int* old = data;
        data = new int[len+1];
        for (int i = 0; i < len; i++)
          data[i+1] = old[i];
        data[0] = v;
        delete [] old;
        len++;
    }

    void removeEnd() { //O(len)
        const int* old = data;
        len--;
        data = new int[len];
        for (int i = 0; i < len; i++)
          data[i] = old[i];
        delete [] old;
    }

    void fastremoveEnd() { //O(1)
        len--;
    }

    void removeStart() {
        len--;
        for (int i = 0; i < len; i++)
          data[i] = data[i+1];
    }
    uint32_t getSize() const { //O(1)
        return len;
    }
};
int main() {
    BadDynamicArray a;
    for (int i = 0; i < 1'000'000; i++)
        a.addEnd(i);

    DynamicArray a;
    for (int i = 0; i < 1'000'000; i++)
      a.addEnd(i);
}