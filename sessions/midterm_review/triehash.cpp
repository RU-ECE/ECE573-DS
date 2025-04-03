/*
	combination of trie and hash can optimize storage
	trie is good for sharing prefixes, bad because each node is huge
hashmap is good for high speed, but can have collisions
  by storing only 64 words max in one hashmap, we can reduce collisions

 */

class hashmap { // starts with "cat"
private:
	string prefix;
	struct node { // store words like atonic alepsy alog
		
	};

	node* table;
};

class triehash {
private:
	struct node {
		node* next[26];
	};

	node root;
public:
	insert(const string& s) { // catatonic catalepsy catalog

	}
};
