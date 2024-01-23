#include <vector>
using namespace std;

double shoelace(vector<pair<double, double>> v) {
    double leftSum = 0.0;
    double rightSum = 0.0;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        leftSum += v[i].first * v[j].second;
        rightSum += v[j].first * v[i].second;
    }
    return 0.5 * abs(leftSum - rightSum);
}