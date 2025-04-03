/*
    HW: Unix diff utility in reverse
    LCS with hashing tricks

    Show all lines in common between two files

1. hash each line of each file (32-bit or 64-bit number)
and generate a vector<uint64_t> 
(64-bits is better, but won't matter if you have a bad hash function!)




*/

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;
/*
    int EditDistance(a, b)
    insert char
    delete char
    replace char
*/
void LCS(...) {
    // m is the number of lines in a, n is the number of lines in b
    uint32_t* counts = new uint32_t[m*n];
    // index using [i * n + j]
    // fill in the table
    // find LCS

    // print out original strings...


    delete [] counts;
}


int main() {
    string atext = ""; // load along.txt into this string
    string btext = ""; // load blong.txt into this string
    vector<uint64_t> a = hash(atext);
    vector<uint64_t> b = hash(btext);
    LCS(a, b, atext, btext); // do LCS on the two files
    // LCS should print all lines in common
}