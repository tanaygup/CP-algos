#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define sz(x) ((int)(x).size())

multiset<long long> low, high;

void remove(long long ele) {
    auto iter = low.find(ele);
    if (iter != low.end()) {
        low.erase(iter);
        if (!high.empty()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    } else {
        iter = high.find(ele);
        if (iter != high.end()) {
            high.erase(iter);
        }
    }
}

void update(long long ele, int low_size) {
    low.insert(ele);
    if (sz(low) > low_size) {
        long long ele = *low.rbegin();
        low.erase(low.find(ele));
        high.insert(ele);
    }
}

vector<int> medianSlidingWindow(vector<int>& nums, int k) {
    long long low_size = 0;
    long long n = nums.size();
    if (k & 1) {
        low_size = k / 2 + 1;
    } else {
        low_size = k / 2;
    }

    for (int i = 0; i < k; i++) {
        low.insert(nums[i]);
        if (sz(low) > low_size) {
            int ele = *low.rbegin();
            low.erase(low.find(ele));
            high.insert(ele);
        }
    }

    vector<int> res;

    if (k & 1) {
        res.push_back(*low.rbegin());
    } else {
        res.push_back(*low.rbegin());
    }

    for (int i = 0; i < n - k; i++) {
        remove(nums[i]);
        update(nums[i + k], low_size);

        if (k & 1) {
            res.push_back(*low.rbegin());
        } else {
            res.push_back(*low.rbegin());
        }
    }

    return res;
}


int main() {
    fastio();
    int k = 3;
    vi a;
    for(int i = 1; i <= 8; i++) a.push_back(i);
    
    vi res = medianSlidingWindow(a, k);

    for (auto it : res) {
        cout << it << " ";
    }

    return 0;
}
