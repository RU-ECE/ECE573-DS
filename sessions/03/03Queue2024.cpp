class Queue {
private:
    LinkedList2 impl;
public:
    void enqueue(int v) {
        impl.addEnd(v);

    }
    int dequeue() {
        return impl.removeStart();
    }

    bool isEmpty() const {


    }
}