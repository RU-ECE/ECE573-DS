class doublelinkedlist {
    struct node {
        int val;
        node* next;
        node* prev;
    };
    node* head;
public:

    //write pseudocode, draw diagram, state complexity O(  )
    void insert_after(node* p, int v) {
        node temp = new node();
        temp.val = v;
        temp.next = p.next; // if nothing is after p, then nothing is after us
        temp.prev = p;
        p.next = temp;
        if (temp.next != null)
            temp.next.prev = temp;
    }

    void insert_before(node* p, int v) {
        node* q = new node();
        q->val = v;
        q->next = p;
        q->prev = p->prev;
        p->prev = q;
        if (q->prev != null) {
            q->prev->next = q;
        } else {
            head = q;
        }
          

    }


    void delete_after(node* p) {
      if (p->next == null)
        return;
      node* temp = p->next->next;
      delete p->next;
      p->next = temp;
    }
}