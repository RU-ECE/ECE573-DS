/*
	c is not a word
  ca is not a word

  cat is a word (but also the prefix of longer words
	cata is NOT a word
	catal ...



 */
class Trie {
private:
	struct Node {
		bool is_word; // true if this node ends a word
		Node* next[52]; // upper and lowercase? ABCDEFG...Z{\} abcd.... z
	};

	Node root; // empty trie contains a root node
public:
	void add(const char s[]) { // "cat\0"
		Node* p = &root;
		for (each letter is s) {
			if (p->next[ yourletter - 'a' ] == null
					p->next[ ... ] = new Node();
					p = p->next[ ...]
						
		}
  	p->is_word = true;
			
	}

	bool isWord(const char s[]) {

	}

	bool startWith(const char s[]) {

	}
};

int main() {
	Trie dict;
	dict.add("cat");
	dict.add("catalog");


	
