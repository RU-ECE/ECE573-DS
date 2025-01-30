#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    for (int n = 1000; n <= 1000'000'000; n *= 10) {
    auto t0 = std::chrono::high_resolution_clock::now();
      vector<int> a;
      a.reserve(n);
      for (int i = 0; i < n; i++)
        a.push_back(i);
      auto t1 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> elapsed_seconds = t1-t0;

      cout << "n=" << n << " " << elapsed_seconds.count() << '\n';
    }
}