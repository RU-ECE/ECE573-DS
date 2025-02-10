#include "a linked list implementation"
#include "a linkedlist 2 implementation"

class stack {
private:
  LinkedList impl;
public:
    stack() {}
    void push(int v) { //O(1)
        impl.addStart(v); //O(1)
    }
    void pop() { //O(1)
        impl.removeFirst(); //O(1)
    }
    bool isEmpty() const { //O(1)
        return impl.isEmpty(); //O(1)
    }
};

class queue {
private:
  LinkedList2 impl;
public:

    void enqueue(int v) { //O(1)
        impl.addStart(v); //O(1)
    }

    void dequeue(int v) {
        impl.removeEnd();
    }

    bool isEmpty() const {
        impl.isEmpty();
    }
}