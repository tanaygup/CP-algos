// using binary lifting and sparse table

#include <bits/stdc++.h>
using namespace std;
// M = log N
const int N = 1e5 + 1, M = 20;

vector<vector<int>> parent(N, vector<int>(M));
// parent sc = o (n * log n)
vector<int> depth(N);
unordered_map<int, vector<int>> adj;

// tc = o(n*m)
void dfs(int node, int par)
{
    parent[node][0] = par;
    for (int j = 1; j < M; j++)
    {
        parent[node][j] = parent[parent[node][j - 1]][j - 1];
    }

    depth[node] = depth[par] + 1;
    for (auto it : adj[node])
    {
        if (it != par)
        {

            dfs(it, node);
        }
    }
}

// tc = o(m) = o(logn)
int LCA(int u, int v)
{
    if (u == v)
        return u;

    // i want u > v a;ways
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];

    for (int i = M - 1; i >= 0; i--)
    {
        if ((diff >> i) & 1)
        {
            u = parent[u][i];
        }
    }
    // now u and v are on same level

    for (int i = M - 1; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    // we climb up from both such that we reach that parent which is not equal and just below their LCA

    return parent[u][0];
}

// o(1)
int Length_From_U_to_V(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << LCA(9, 11) << endl;
    cout << Length_From_U_to_V(9, 12);
}