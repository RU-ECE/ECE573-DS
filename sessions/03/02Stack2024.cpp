#include "01LinkedList2024.cpp"

class Stack {
private:
    LinkedList impl;
public:
    void push(int v) { // O(1)
        impl.addStart(v); //  O(1)
    }
    int pop() { //O(1) 
         return impl.removeStart();
    }

    bool isEmpty() const { //O(1)
        return impl.isEmpty();
    }
};

class Stack2 {
private:
    GrowArray impl;
public:
    void push(int v) { // O(1)
        impl.addEnd(v); //  O(1)
    }
    int pop() { //O(1) 
         return impl.removeEnd();
    }

    bool isEmpty() const { //O(1)
        return impl.getSize() == 0;
    }
};
