#include <iostream>
#include <fstream>
using namespace std;

/*
	dict.txt is located in the data directory of the repo
	load all the words into the trie

	


 */
class Trie {
public:
	Trie(const char dict[]) {

	}
	bool is_word(const char word[]) {
		return true;
	}
	bool is_prefix(const char word[]) {
		return true;
	}
};

int main() {
	Trie t("dict.txt"); // load dict.txt from the current directory
	
	ifstream f("triespellcheck.txt");
	char word[256];
	int count = 0;
	while (f.getline(word, sizeof(word))) {
		if (!t.is_word(word))
			cout << word << '\n';
		if (t.is_prefix(word))
			cout << "startswith: " << word << '\n';
	}
	return 0;
}
