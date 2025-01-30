#include <iostream>
#include <chrono>
use namespace std;

class DynArray {
private:
    // grow should at least DOUBLE the capacity of the array
    // if you start with capacity=0, 2*0 is STILL ZERO!!
    void grow() {


    }
    void addStart(int v) {
        //if (size >= capacity)
        //  grow();
        // add the value to your list which should now be big enough
    }
};

void test_does_it_work() {
    DynArray a(1000); // create an array with capacity 1000
    for (int i = 0; i < 10; i++)
      a.addEnd(i); // 0 1 2 3 4 5 6 7 8 9
    for (int i = 0; i < 3; i++)
      a.addStart(i);  3 2 1 0 0 1 2 3 4 5 6 7 8 9
    a.insert_after(2, 99); // 3 2 1 99 0 0 1 2 3 4 5 6 7 8 9
    cout << "size=" << a.size() << '\n';
    cout << a << '\n';
//or you can write this:    a.print();
}
    
void test_add_to_end() {
    for (int n = 1000; n < 10'000'000; n *= 10) {
    auto t0 = chrono::high_resolution_clock::now();
    GrowArray a;
    for (int i = 0; i < n; i++)
        a.addEnd(i);
    auto t1 = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = t1-t0;
    cout << "n=" << n << " " elapsed_seconds.count() << '\n';
}
void test_remove_end(int n) {
    DynArray a(n);
    for (int i = 0; i < n; i++)
       a.addEnd(i);
    auto t0 = chrono::high_resolution_clock::now();    
    for (int i = 0; i < n; i++)
       a.removeEnd();
    auto t1 = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = t1-t0;
    cout << "removing from end n=" << n << " " elapsed_seconds.count() << '\n';
}
// a= 1 2 3 4 5 6 7 8 9 10 11 12
// test_insert_middle(a, 3, 5)
// a = 1 2 3 4 5 6 7 8 9 5 6 7 8 9 10 11 12
void test_insert_middle(DynArray& a, int pos, int len) {
    for (int i = middle; i < middle + len; i++)
       a.insert(i, i);
}

int main() {
    test_does_it_work();
    test_add_to_end();
    test_remove_end();

    // torture test: create n elements and insert m in the middle
    const int n = 100'000'000; 
    DynArray a(n);
    for (int i = 0; i < n; i++)
      a.addEnd(i);
    const int len = 1'000'000;
    test_insert_middle(a, 50, len);
}