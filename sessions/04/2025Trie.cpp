#include <iostream>
using namespace std;

class Trie {
private:
    struct Node {
        bool isWord;
        Node* next[26];
        Node() : isWord(false) {
            for (int i = 0; i < 26; i++)
               next[i] = nullptr;
        }
        ~Node() {
            for (int i = 0; i < 26; i++)
              delete next[i];
       }
    };
    Node root;
public:
    Trie() : root() {}
    ~Trie() {
    }


// n= number of words in dictionary, and len = length of the word
// O(len)
//ex: Cat   'C' - 'a'
    void add(const char word[]) {
        Node* p = &root;
        for (int i = 0; word[i] != '\0'; i++) {
            uint32_t off = word[i] - 'a';
            if (off > 25)
               return;
            if (p->next[off] == nullptr) {
                p->next[off] = new Node();
            }
            p = p->next[off]
        }
        p->isWord = true;
    }
    bool containsPrefix(const char word[]) {
        Node* p = &root;
        for (int i = 0; word[i] != '\0'; i++)
           uint32_t off = word[i] - 'a'; // 0 .. 25
           if (off > 25)
             return false;
           p = p->next[off];
           if (p == nullptr)
             return false;
        }
        return true;
    }
    bool containsWord(const char word[]) {
        Node* p = &root;
        for (int i = 0; word[i] != '\0'; i++)
           uint32_t off = word[i] - 'a'; // 0 .. 25
           if (off > 25)
             return false;
           if (p->next[off] == nullptr)
             return false;
           p = p->next[off];
        }
        return p->isWord;
    }
};

int main() {
    trie a;
    a.add("cat");
    a.add("dog");
    a.add("cats");
    cout << a.containsWord("Dog") << '\n'; // FALSE
    cout << a.containsWord("ca") << '\n'; // FALSE
    cout << a.containsWord("cat") << '\n'; // TRUE
    cout << a.containsPrefix("d") << '\n'; // TRUE
}