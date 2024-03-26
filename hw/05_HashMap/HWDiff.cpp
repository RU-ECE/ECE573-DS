

uint32_t same(const string& s1, const string& s2) {
    if (s1[0] = s2[0]) {
        return 1+ same(s1.substr(1), s2.substr(1));

    } else {
        return max(same(s1.substr(1), s2), same(s1, s2.substr(1)));
    }
//                  30kb       40kb
    int counts[lengthFILE1][lengthFILE2];
}


int main(int argc, char* argv[]) {
    const char* file1 = argv[1];
    const char* file2 = argv[2];
    string s1 = readFile(file1);
    string s2 = readFile(file2);
    same(s1, s2);
}