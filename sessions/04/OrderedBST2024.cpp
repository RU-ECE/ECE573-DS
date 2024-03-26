#include <iostream>
using namespace std;

/* 3 1 5 2 4
    root
		   \
        3
      /   \
     1     5
      \   /
       2 4


1 2 3 4 5
    root   O(?) = 1 + 2 + 3 + .. + (n-1) + n = n(n+1)/2 = O(n^2)
      \
       1
      / \
         2
        / \
           3
          / \
             4
            / \
               5
              / \

 */
class BST {
private:
	class Node {
		public:
    int val;
		Node* left;
		Node* right;
		Node(int v) : val(v), left(nullptr), right(nullptr) {}
		void inorder() {
			if (left != nullptr)
				left->inorder();
			cout << val << ' ';
			if (right != nullptr)
				right->inorder();
		}
	};
	Node* root;

public:
	BST() : root(nullptr) {}

	void add(int v) {
		if (root == nullptr) {
			root = new Node(v);
			return;
		}

		// invariant: tree is NOT empty
		Node* p = root;
		while (true) {
			if (v > p->val) { // go right
				if (p->right == nullptr) {
					p->right = new Node(v);
					return;
				}
				p = p->right;
			} else {  // go left
				if (p->left == nullptr) {
					p->left = new Node(v);
					return ;
				}
				p = p->left;
			}
		}
	}

	void inorder() {
		if (root == nullptr)
			return;
		root->inorder();
	}
};

int main() {
  BST b;
	b.inorder(); // should print nothing!
  b.add(3);
  b.add(1);
	b.add(4);
	b.add(1);
	b.add(5);
	b.inorder();
	
}
