#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void buildSegmentTree(vector<ll>& arr, vector<ll>& segTree, int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(arr, segTree, 2 * node, start, mid);
        buildSegmentTree(arr, segTree, 2 * node + 1, mid + 1, end);
        segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
    }
}

ll rangeMinQuery(vector<ll>& segTree, int node, int start, int end, int l, int r) {
    if (r < start || l > end) {
        return LLONG_MAX;
    }
    if (l <= start && end <= r) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    ll leftMin = rangeMinQuery(segTree, 2 * node, start, mid, l, r);
    ll rightMin = rangeMinQuery(segTree, 2 * node + 1, mid + 1, end, l, r);
    return min(leftMin, rightMin);
}


int main(){
    int t = 1;
    while(t--){
        vector<ll> arr = {1,2,3,4,5};

        int n = arr.size();
        vector<ll> segTree(4 * n);
        buildSegmentTree(arr, segTree, 1, 0, n - 1);
        int idx1 = 2;
        int idx2 = 4;
        cout << rangeMinQuery(segTree, 1, 0, n - 1, idx1,idx2) << "\n";
    }
    return 0;
}