#include   <iostream>
using namespace std;
const int n = 256;
int hash1(const string& s) {
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        sum = sum ^ ((sum << 7) | (sum >> 25)) ^ s[i];
    }
    return sum % n;
}

int hash2(const string& s) {
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        sum = sum ^ ((sum << 7) | (sum >> 25)) ^ s[i];
    }
    return sum & (n-1);
}


int main() {
    string s = "testing";


    cout << hash1(s) << endl;
    cout << hash2(s)    << endl;
}