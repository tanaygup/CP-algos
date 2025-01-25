#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<int> tree;
    int n;

    int lsb(int x) {
        return x & (-x);
    }

public:
    FenwickTree(int size) {
        n = size;
        tree.resize(n + 1, 0); // Fenwick Tree is 1-based
    }

    // Update the Fenwick Tree by adding 'value' at index 'idx'
    void update(int idx, int value) {
        while (idx <= n) {
            tree[idx] += value;
            idx += lsb(idx);
        }
    }

    // Get the prefix sum from 1 to idx
    int sum(int idx) {
        int result = 0;
        while (idx > 0) {
            result += tree[idx];
            idx -= lsb(idx);
        }
        return result;
    }

    // Get the sum in the range [left, right]
    int rangeSum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

    // Lower bound: Smallest index where prefix sum >= value
    int lowerBound(int value) {
        int currentSum = 0;
        int pos = 0;
        
        for (int i = 31; i >= 0; --i) {
            int nextPos = pos + (1 << i);
            if (nextPos <= n && currentSum + tree[nextPos] < value) {
                currentSum += tree[nextPos];
                pos = nextPos;
            }
        }

        return pos + 1;
    }
};

int main() {
    int n = 10;
    FenwickTree fenwick(n);

    fenwick.update(1, 5);  // Add 5 to index 1
    fenwick.update(3, 7);  // Add 7 to index 3

    // Query examples
    std::cout << "Prefix sum up to index 3: " << fenwick.sum(3) << "\n";      // Output: 12

    std::cout << "Lower bound for prefix sum >= 8: " << fenwick.lowerBound(8) << "\n";  // Output: 3

    return 0;
}