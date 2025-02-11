#include <iostream>
using namespace std;

struct Box {
    float x, y, w, h; //x,y are top-left corner, y positive going down
    bool contains(Point p) { //O(1)
        return p.x >= x && p.x <= x + w && p.y >= y && p.y <= y+h;
    }
    friend ostream& operator<<(ostream& os, Box b) {
        return os << '{' << b.x << ' ' << b.y << ' ' << b.w << ' ' << b.h << '}';
    }
};
struct Point {
    float x, y;
};


class BoxSorter {
private:

public:
   BoxSorter() {}
   void add(Box b) {}
   bool contains(Point p) //O(?)
   {

   }
   uint32_t countContains(Point p) {

   }
};

void testLinkedList() {
    Box b = {1, 2, 3, 4};
    Box b2 = {3, 4, 1, 2};
    LinkedList a;
    for (int i = 0; i < 10; i++)
      a.addFirst(b); // b b b b b b b b b b
    for (int i = 0; i < 3; i++)
      a.addLast(b2);   //b b b b b b b b b b b2 b2 b2 b2
    a.removeFirst();   //b b b b b b b b b b2 b2 b2 b2
    cout << a << '\n';
    // don't forget to write the destructor to give back all the memory
#if 0 // the next section is chopped out. Do for extra credit + 10%
    LinkedList a2(a); 
    a2.addFirst(b2);
    cout << a2 << '\n'; // b2 b b b b b b b b b b2 b2 b2 b2
    cout << a << '\n'; // b b b b b b b b b b2 b2 b2 b2
#endif
}

int main() {
    testLinkedList();
 
    BoxSorter boxes;
    boxes.add({2.0, 3.0, 5.0, 4.0});
    boxes.add({2.5, 3.0, 5.0, 4.0});
    cout << boxes.contains({2.7, 3.5}) << '\n'; // true!
    cout << boxes.countContains({2.7, 3.5})
}