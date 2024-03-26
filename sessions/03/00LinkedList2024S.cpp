#include <iostream>

class LinkedList {
private:
    class Node { // name = LinkedList::Node
    public:
        int val;
        Node* next;
    };
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* temp;
        for (Node* p = head; p != nullptr; p = temp) {
            temp = p->next;
            delete p;
        }
    }
    void addStart(int v) { //O(1)
        Node* temp  = new Node();
        temp->val = v;
        temp->next = head;
        head = temp;
    }
    void addEnd(v) {
        if (head == nullptr) {
            head = new Node();
            head->val = v;
            head->next = nullptr;
            return;
        }
        // find the end of the list
        Node* p;
        Node* q;
        for (p = head, q = p->next; q != nullptr; p=q, q =q->next)
            ;
        //p = pointing to LAST NODE 
        Node* temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        p->next = temp;
    }

};

