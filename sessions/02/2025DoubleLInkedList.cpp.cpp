#include <iostream>
class DoubleLinkedList {
private:
    class node {
    public:
        int val;
        node* next;
        node* prev;
        ~node() {delete next; }
    };
    node* head;
    int size;
public:
    DoubleLinkedList() {
        head = nullptr;
        size = 0;
    }
    ~DoubleLinkedList() {
/*
        node* q;
        for (node* p = head; p != nullptr; p = q) {
            q = p->next;
            delete  p;
        }
        */
       delete head;
    }
    DoubleLinkedList(const DoubleLinkedList& orig) { //O(n)
        if (orig.head == nullptr) {
            head = nullptr;
            return;
        }
        node* prev = nullptr;
        node* q;
        // we know the list has at least one element
        for (node* p = orig.head; p != nullptr; p = p ->next) {
            q = new node();
            if (head == nullptr)
              head = q;
            q->val = p->val; // copy the value from the orig list
            q->prev = prev;
            if (prev != nullptr)
                prev->next = q;
            prev = q;
        }
        // cleanup last time???
        q->next = nullptr;
    }
    void addEnd(int v) { //O(n)
        if (head == nullptr) {
            head = new node();
            head->val = v;
            head->next = nullptr;
            head->prev = nullptr;
            size++;
            return;
        }
        node* p;
        for (p = head; p->next != nullptr; p = p->next)
           ;
        // p points to last node
        node* temp = new node();
        temp->val = v;
        p->next = temp;
        temp->prev = p;
        temp->next = nullptr;
        size++;
    }
    void set(int pos, int val) {

    }
    uint32_t len() const { //O(n)
        return size;
    }

    void addStart(int v) {
        size++;
    }
/*
TODO:
    void insertAfter(node* p) {

    }
    */
};

int main() {
    DoubleLinkedList a;
    for (int i = 0; i < 3; i++)
      a.addEnd(i);
    DoubleLinkedList b(a); // b is a copy of a (calls the copy constructor)
    DoubleLinkedList c = a; // c is a ocpy of a(calls the copy constructor)
    c.set(0, 99);
}