#include <regex>
#include <string>

void f(const string& s) {
    regex r(
        R"(
        \d{3}[)\-\.]\d{3}[)\-\.]\d{4}
        )"
        );
                  smatch m;
            regex_search(s, m, r);
            for (auto x : m) {
                cout << x << endl;
            }
        
}
int main() {
    string s = "hello there 123 my 987.1234 phone number is (212)859-1314 test";
}