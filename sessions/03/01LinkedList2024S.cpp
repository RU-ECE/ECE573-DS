#include <iostream>


class LinkedList {
public:
    class Node { // name = LinkedList::Node
    public:
        int val;
        Node* next;
        Node(int v, Node* n) : val(v), next(n)
         {
//            this->val = v;
//            this->next = n;
         }
    };
private:
    Node* head;
    uint64_t size;
public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList() {
        Node* temp;
        for (Node* p = head; p != nullptr; p = temp) {
            temp = p->next;
            delete p;
        }
    }
    LinkedList(const LinkedList& orig) {
        Node* p = orig.head;
        if (p == nullptr) {
            head = nullptr;
            return;
        }
        // p is pointing to first element
        Node* q = new Node(p->val, nullptr);
        head = q;
        for (p = p->next; p != nullptr; p=p->next) { // p is pointing to 2nd element
            Node* temp = new Node(p->val, nullptr);
            q->next = temp;
            q = temp;
        }
    }
    bool isEmpty() const { return head == nullptr;}
    Node* first() { return head; }
    void addStart(int v) { //O(1)
        head = new Node(v, head);
        size++;
    }
    int removeStart() { //O(1)
        Node* temp = head;
        head = head->next;
        int v = temp->val;
        delete temp;
        return v;
    }
    void removeEnd() { //O(n)
        //loop
        //by the way, if it's empty?
    }
    void addEnd(v) { //O(n)
        if (head == nullptr) {
            head = new Node(v, nullptr);
            return;
        }
        // find the end of the list
        Node* p;
        Node* q;
        for (p = head, q = p->next; q != nullptr; p=q, q =q->next)
            ;
        //p = pointing to LAST NODE
        p->next = new Node(v, nullptr);
/*
    thisis an example of corrupting the heap
    by writing the wrong value for size of the block
    DO NOT DO THIS! (CRASH)
        uint64_t*px = (int64_t*) p->next ;
        px--;
        *px = 1000000;
        */
    }
    uint64_t getSize() const {
        return size;
    }
    int get(int i) { // O(n)
        Node* p;
        for (p = head; i > 0; i--, p =p->next)
            ;
        return p->val;
    }
};

int main() {
    const int n = 10;
    LinkedList a;
    for (int i = 0; i < n; i++)
        a.addEnd(i);
    for (int i = 0; i < n; i++)
        a.addStart(i);
    a.addStart(99);
    // 99 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9

    LinkedList b;
    for (int i = 0; i < a.getSize(); i++)
      b.addEnd(a.get(i)); //O(2n^2) = O(n^2)

      //copy the list backwards?
    for (Node* p = a.first(); p != nullptr; p=p->next)
        b.addStart(p->val);

    Node* q = b.first();
}
