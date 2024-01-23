int fibo(int n) {
    int a = 1, b = 1, c;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
}

uint64_t rfibo(uint64_t n) {
    if (n <= 2)
       return 1;
    return rfibo(n-1) + rfibo(n-2);
}

int main() {
    
}