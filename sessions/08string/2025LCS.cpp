#include <iostream>
#include <string>

using namespace std;
//given two strings, find the longest common subsequence of characters
// in common between them

// ex: a="hello", b="world", return 1
// ex: a="hello", b="ohexll", return 4
uint32_t LCS(string a, string b) {
    if (a.length() == 0 || b.length() == 0)
      return 0;
    if (a[0] == b[0])
      return 1 + LCS(a.substring(1), b.substring(1));
    return max(LCS(a.substring(1), b), LCS(a, b.substring(1)));
}

uint32_t LCS2(const string& a, uint32_t i, 
                const string& b, uint32_t j) {
    if (i == a.length() || j == b.length() )
      return 0; // if no letters, no match 
    if (a[i] == b[j])
      return 1 + LCS(a, i+1, b, j+1);
      // this is still O(2^n) OUCH!
    return max(LCS(a, i+1, b, j), LCS(a, i, b, j+1));
}

