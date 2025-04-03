class trie {
private:
  struct node {
    node* next[26]; //0=a, 1=b, ... , 25=z  26 pointers each 8 bytes 208
    bool is_word; //1 byte round up to 216 bytes
		node() {
			for (int i = 0; i < 26; i++) next[i] = nullptr;
			is_word = false;
		}
  };
  node root;
public:
  void insert(const string& s) {
    node* p = &root;
    for (int i = 0; i < s.length(); i++) {
        uint32_t offset = s[i] - 'a';
    	if (offset > 25)
      	   throw "AAAAAAAAGGGH";
    	if (p->next[offset] == nullptr) {
				p->next[offset] = new node();
			}
			// must not be null!
			p = p->next[offset];
		}
    p->is_word = true;		
  }
	bool contains(const string& s) {
    node* p = &root;
		for (int i = 0; i < s.length(); i++) {
			uint32_t offset = s[i] - 'a';
			if (p->next[offset] == nullptr)
				return false;
			p = p->next[offset]; 
		}
		return p->is_word;
	}

	bool contains_prefix(const string& s) {
    node* p = &root;
		for (int i = 0; i < s.length(); i++) {
			uint32_t offset = s[i] - 'a';
			if (p->next[offset] == nullptr)
				return false;
			p = p->next[offset]; 
		}
		return true;			    
	}
