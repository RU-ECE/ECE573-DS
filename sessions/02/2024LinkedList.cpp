
class LinkedList {
private:
    struct Node { // LinkedList::Node
        int val;
        Node* next;
        // in java this has an extra pointer to outer class
    };
    Node* head; // linkedlist contains one pointer to a node
public:
//    LinkedList() { head = nullptr; }
    LinkedList() : head(nullptr) {}
    void addFirst(int v) {
        Node* temp = new Node();
        //(*temp).val = v;
        temp->val = v;
        temp->next = head;
        head = temp;
    }
};

int main() {
    LinkedList a;
    a.addFIrst(3);
    a.addFirst(1);  // head-> 1 --> 3 --> null
}