#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

class FenwickTree {
public:
    vector<ll> bit;
    int n;
    FenwickTree(int size) : n(size) {
        bit.assign(n + 1, 0);
    }
    void update(int ind, ll x) {
        while (ind <= n) {
            bit[ind] += x;
            ind += ind & -ind;
        }
    }
    ll query(int ind) {
        ll sum = 0;
        while (ind > 0) {
            sum += bit[ind];
            ind -= ind & -ind;
        }
        return sum;
    }
    ll range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int subsize(int node, vector<vector<int>> &adj, vector<int> &sizes, int parent) {
    sizes[node] = 1;
    for (int x : adj[node]) {
        if (x != parent) {
            sizes[node] += subsize(x, adj, sizes, node);
        }
    }
    return sizes[node];
}

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &euler, vector<int> &start, vector<int> &end, int &timer) {
    start[node] = ++timer;
    euler[timer] = node;
    for (int x : adj[node]) {
        if (x != parent) {
            dfs(x, node, adj, euler, start, end, timer);
        }
    }
    end[node] = timer;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> sizes(n + 1, 0);
    subsize(1, adj, sizes, 0);
    
    vector<int> euler(n + 1), start(n + 1), end(n + 1);
    int timer = 0;
    dfs(1, 0, adj, euler, start, end, timer);
    
    FenwickTree bit(n);
    for (int i = 1; i <= n; i++) {
        bit.update(start[i], v[i]);
    }
    
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            bit.update(start[s], x - v[s]);
            v[s] = x;
        } else {
            int s;
            cin >> s;
            cout << bit.range_query(start[s], end[s]) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
