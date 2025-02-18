#include <map>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
int main() {
    map<string, int> dict;
    dict["hello"] = 1;
    dict["apple"] = 3;
    dict["bear"] = 19;
    dict["zebra"] = -1;
    dict["rush"] = 5;

    for (auto x : dict) {
        cout << x.first << "==>"  << x.second << '\n';
    }


}