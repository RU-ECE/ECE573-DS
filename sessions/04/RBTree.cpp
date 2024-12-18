#include <iostream>
using namespace std;

class RBTree {
private:
    enum color_t {RED, BLACK};
    struct Node {
        color_t color;
        int val;
        Node* parent;
        Node* left;
        Node* right;
        Node(int v) : color(RED), val(v), left(nullptr), right(nullptr) {}
        void print() {
            if (left != nullptr) left->print();
            cout << val << ' ';
            if (right != nullptr) right->print();
        }
    };

    Node* parent(Node* n) {
        return (n == nullptr) ? nullptr : n->parent;
    }
    Node* grandparent(Node* n) {
        return parent(parent(n));
    }
    Node* uncle(Node* n) {
        Node* g = grandparent(n);
        return (parent(n) == g->left) ?
            g->right : g->left;
    }
    void rotate_left(Node* n) {
        if (n->right == nullptr) return;
        Node* r = n->right;
        n->right = r->left;
        if (r->left != nullptr) r->left->parent = n;
        r->parent = n->parent;
        if (n->parent == nullptr) root = r;
        else if (n == n->parent->left) n->parent->left = r;
        else n->parent->right = r;
        r->left = n;
        n->parent = r;
    }
    void rotate_right(Node* n) {
        if (n->left == nullptr) return;
        Node* l = n->left;
        n->left = l->right;
        if (l->right != nullptr) l->right->parent = n;
        l->parent = n->parent;
        if (n->parent == nullptr) root = l;
        else if (n == n->parent->right) n->parent->right = l;
        else n->parent->left = l;
        l->right = n;
        n->parent = l;
    }
    Node* root;
    void fixup(Node* p) {
        if (parent(p) == nullptr) return; // leave root red?
        if (parent(p)->color == RED) {
            Node* u = uncle(p);
            if (u != nullptr && u->color == RED) {
                parent(p)->color = BLACK;
                u->color = BLACK;
                grandparent(p)->color = RED;
                fixup(grandparent(p));
            } else {
                if (parent(p) == grandparent(p)->left) {
                    if (p == parent(p)->right) {
                        rotate_left(parent(p));
                        p = p->left;
                    }
                    rotate_right(grandparent(p));
                    swap(p->color, grandparent(p)->color);
                } else {
                    if (p == parent(p)->left) {
                        rotate_right(parent(p));
                        p = p->right;
                    }
                    rotate_left(grandparent(p));
                }
            }
        }
    }
public:
    RBTree() : root(nullptr) {}
    void add(int v) {
        if (root == nullptr) {
            root = new Node(v, nullptr);
            return;
        }
        Node* p = root;
        while (true) {
            if (v > p->val) {
                if (p->right == nullptr) {
                    p->right = new Node(v, p);
                    break;
                }
                p = p->right;
            } else {
                if (p->left == nullptr) {
                    p->left = new Node(v, p);
                    break;
                }
                p = p->left;
            }
        }
        fixup(p);
    }
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) v->parent = u->parent;
    }
    Node* successor(Node* n) {
        if (n->right != nullptr) return min(n->right);
        Node* p = n->parent;
        while (p != nullptr && n == p->right) {
            n = p;
            p = p->parent;
        }
        return p;
    }
    Node* min(Node* n) {
        while (n->left != nullptr) n = n->left;
        return n;
    }
    void remove(int v) {
        Node* p = root;
        while (p != nullptr && p->val != v) {
            p = (v > p->val) ? p->right : p->left;
        }
        if (p == nullptr) return;
        if (p->left == nullptr) {
            transplant(p, p->right);
        } else if (p->right == nullptr) {
            transplant(p, p->left);
        } else {
            Node* s = successor(p);
            if (s->parent != p) {
                transplant(s, s->right);
                s->right = p->right;
                s->right->parent = s;
            }
            transplant(p, s);
            s->left = p->left;
            s->left->parent = s;
            s->color = p->color;
        }
    }
    void print() {
        if (root == nullptr) return;
        root->print();
    }
};

int main() {
    const int vals[] = {
        3, 10, 5, 15, 9, 20, 21, 22, 19
    };   
    RBTree t;
    for (int v : vals) {
        t.add(v);
        t.print();
    }
}