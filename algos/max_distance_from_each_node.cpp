#include <bits/stdc++.h>
using namespace std;

/*
    What to do? -> calculate max distance from each node in a tree

    WHat i did->
    I calculated the diamter of the tree and goot the 2 end points

    then i calculated the distance from 2 endpoints to the node and return the max distance

    node ->p , endpts -> a,b

    maxi = max(dist from a, dist from b)
*/

void dfs(int node, int par, unordered_map<int, vector<int>> &adj, int dis, int &maxi, int &maxi_node, vector<int> &ans)
{
    ans[node] = dis;
    if (dis > maxi)
    {
        maxi = dis;
        maxi_node = node;
    }
    for (auto it : adj[node])
    {
        if (it != par)
        {
            dfs(it, node, adj, dis + 1, maxi, maxi_node, ans);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    unordered_map<int, vector<int>> adj;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxi_node = 0, maxi = 0;
    vector<int> ans(n + 1);

    // First DFS: Find the farthest node (a) from node 1
    dfs(1, -1, adj, 0, maxi, maxi_node, ans);

    int a = maxi_node;
    maxi_node = 0;
    maxi = 0;
    vector<int> dist_from_a(n + 1);

    // Second DFS: Find the farthest node (b) from a
    dfs(a, -1, adj, 0, maxi, maxi_node, dist_from_a);

    int b = maxi_node;
    vector<int> dist_from_b(n + 1);

    // Third DFS: Get distances from b
    dfs(b, -1, adj, 0, maxi, maxi_node, dist_from_b);

    // Compute max diameter for each node
    for (int i = 1; i <= n; i++)
    {
        cout << max(dist_from_a[i], dist_from_b[i]) << " ";
    }

    cout << endl;
    return 0;
}
