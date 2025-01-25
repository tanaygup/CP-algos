#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findMaximumSubarraySum() {
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long currentSum = 0, maximumSum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        currentSum += a[i];
        if (currentSum > maximumSum) {
            maximumSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    cout << maximumSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        findMaximumSubarraySum();
    }

    return 0;
}
