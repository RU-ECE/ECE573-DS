/**
    Different kinds of LinkedLists

*/

class LinkedList {
private:
    struct Node { // LinkedList::Node    LinkedList.Node
        int val;
        Node* next;
        Node(int v, Node* n) { val = v; next = n; }
        Node() {}
    };

    Node* head;
public:
    LinkedList() :head(nullptr) {}
    ~LinkedList() { //O(n)
        Node* q;
        for (Node* p = head; p != nullptr; p = q){
            q = p->next;
            delete p;
        }

    }
    void addFirst(int val) { //O(1)
    //equivalent       head = new Node(val , head);
        Node* temp = new Node();
        temp->next = head;
        temp->val  = val;
        head = temp;
    }

    void addLast(int val) { //O(n)
        Node* p = head;
        if (p == nullptr) {
            head = new Node(val, nullptr);
            return;
        }
        for ( ; p->next != nullptr ; p = p->next)
            ;
        // p must be pointing to last node
//        Node* temp  = new Node();
//        temp->val = val;
//        temp->next = nullptr;
//        p->next = temp;
        p->next = new Node(val, nullptr);
    }
    void removeFirst() { //O(1)
        if (head == nullptr)
            return;
        Node* temp = head;
        head = head->next;
        delete temp; // give back the memory
    }
    void removeLast() { //O(n)
        Node* p = head;
        if (p == nullptr)
           return;
        for (  ; p->next != nullptr; p = p->next)
            ;
        // p  = nullptr
    }

};

class LinkedList2 {
private:
    struct Node { // LinkedList2::Node
        int val;
        Node* next;
        Node(int v, Node* n) { val = v; next = n; }
        Node() {}
    };
    Node* head;
    Node* tail;
public:
    LinkedList2() {
        head = nullptr;
        tail = nullptr;
    }
    void addFirst(int v) {//O(1)
        head = new Node(v, head);
        if (tail == nullptr)
          tail = head;
    }
    void addLast(int v) { //O(1)
        if (tail == nullptr) {
            head = tail = new Node(v, nullptr);
            return;
        }
        // tail must point at a node
        tail->next = new Node(v, nullptr);
        tail = tail->next; // now tail is pointing to the last one
    }
    void removeFirst() { //O(1)
        if (head == nullptr)
            return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        // guaranteed we have at least 2 nodes
        Node* p = head;
        head = head ->next;
        delete p;
    }
    void removeLast() {
        if (head == nullptr)
            return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node*p;
        for (p = head; p->next != tail; p = p->next)
            ;
        p->next = nullptr; // make the 2nd to last element, the LAST ONE
        delete tail;
        tail = p; // tail now points to 2nd to last
    }
};

int main() {
    LinkedList2 a;
    a.addFirst(3);
    a.addFirst(1);
    a.addFirst(4);
    a.addLast(9);
}