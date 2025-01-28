#include <bits/stdc++.h>
using namespace std;

/*
    How am I finding the diameter?

    This includes 2 dfs calls
    1. First dfs call is to find the maximum depth of the tree
    2. Second dfs call is to find the maximum diameter of the tree

    Run a DFS from any node p. Let a be a node whose distance from node p is maximized.
    Run another DFS from node a. Let b be a node whose distance from node a is maximized.
    a→b is a diameter.
*/
// tc is o(n);
void dfs(int node, int par, unordered_map<int, vector<int>> &adj, int dis, int &maxi, int &maxi_node, unordered_map<int, int> &parent)
{
    if (dis > maxi)
    {
        maxi = dis;
        maxi_node = node;
    }
    for (auto it : adj[node])
    {
        if (it != par)
        {
            parent[it] = node;
            dfs(it, node, adj, dis + 1, maxi, maxi_node, parent);
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
    unordered_map<int, int> parent;
    parent[1] = -1;
    dfs(1, -1, adj, 0, maxi, maxi_node, parent);

    int a = maxi_node;
    maxi_node = 0;
    maxi = 0;
    parent.clear();
    parent[a] = -1;
    dfs(a, -1, adj, 0, maxi, maxi_node, parent);

    int b = maxi_node;

    // to find the path of diameter
    vector<int> path;
    for (int node = b; node != -1; node = parent[node])
    {
        path.push_back(node);
    }

    cout << "Diameter: " << maxi << endl;
    cout << "Nodes: " << a << " -> " << b << endl;
    cout << "Path: ";
    reverse(path.begin(), path.end());
    for (int node : path)
        cout << node << " ";
    cout << endl;

    return 0;
}
