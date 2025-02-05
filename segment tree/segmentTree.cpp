#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
struct segmenttree
{
    int n;
    vector<int> st;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int node, int start, int end, vector<int> &v)
    {

        int mid = (start + end) / 2;
        if (start == end)
        {
            st[node] = v[start];
            return;
        }

        build(2 * node + 1, start, mid, v);
        build(2 * node + 2, mid + 1, end, v);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(vector<int> &v)
    {
        build(0, 0, n - 1, v);
    }

    int query(int start, int end, int l, int r, int node)
    {

        // if no overlap
        if (start > r || end < l)
        {
            return 0;
        }

        // complete overlap

        if (start >= l && end <= r)
        {
            return st[node];
        }

        // partial overlap
        int mid = (start + end) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);

        return q1 + q2;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid)
        {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];

        return;
    }
    // update index element at index x to value y
    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
    // finding the first index with value greater than or equal to the given value
    int get_first(int node, int start, int end, int l, int r, int x)
    {
        if (start > r || end < l) // no overlap
            return -1;

        if (st[node] < x) // segment max < x, skip this segment
            return -1;

        if (start == end) // leaf node
            return start;

        int mid = (start + end) / 2;

        int left_result = get_first(2 * node + 1, start, mid, l, r, x);
        if (left_result != -1) // if found in the left subtree
            return left_result;

        return get_first(2 * node + 2, mid + 1, end, l, r, x);
    }

    int get_first(int l, int r, int x)
    {
        return get_first(0, 0, n - 1, l, r, x);
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    segmenttree tree;

    tree.init(v.size());

    tree.build(v);

    cout << tree.query(0, 4);

    // cout << tree.st[0];
}