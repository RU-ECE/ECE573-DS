#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
mt19937 gen(0);

void fischer_yates_shuffle(std::vector<int>& arr) {
    for (int i = arr.size() - 1; i > 0; --i) {
        uniform_int_distribution<> dist(0, i);
        swap(arr[i], arr[dist(gen)]);
    }
}

void bad_shuffle(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        uniform_int_distribution<> dist(0, arr.size() - 1);
        swap(arr[i], arr[dist(gen)]);
    }
}

constexpr int num_elements = 10;
template<typename Func>
void test_shuffle(Func shuffle, uint32_t num_trials) {
    vector<int> arr(num_elements);
    uint32_t hist[num_elements][num_elements] = {0};
    for (int trial = 0; trial < num_trials; trial++) {
        for (int i = 0; i < num_elements; i++) {
            arr[i] = i;
        }
        shuffle(arr);
        for (int i = 0; i < num_elements; i++) {
            hist[i][arr[i]]++;
        }
    }
    for (int i = 0; i < num_elements; i++) {
        for (int j = 0; j < num_elements; j++) {
            cout << hist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const uint32_t num_trials = 1'000'000;
    test_shuffle(fischer_yates_shuffle, num_trials);
    cout << "\n\n--------------------------------\n\n\n";
    test_shuffle(bad_shuffle, num_trials);
    return 0;
}