/*
    Steps:
    1. Find topo sort ordering of graphs
    2. start iterating on it from begining
    3. perform dfs on reverse graph
    4. mark nodes vis

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

void topoSort(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;

    for (auto x : adj[node])
    {
        if (!vis[x])
            topoSort(x, adj, vis, ans);
    }
    ans.push_back(node);
}
void comp_in_revgraph(int node, vector<int> &vis, unordered_map<int, vector<int>> &revAdj, int comp, vector<int> &col)
{
    vis[node] = 1;
    col[node] = comp;

    for (auto it : revAdj[node])
    {
        if (!vis[it])
        {
            comp_in_revgraph(it, vis, revAdj, comp, col);
        }
    }
}
void solve()
{
    int n;
    cin >> n;

    // making graph and rev graph
    unordered_map<int, vector<int>> adj, revAdj;

    for (int i = 0; i < n; i++)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, ans);
        }
    }
    // topo sorted vector
    reverse(ans.begin(), ans.end());
    // for (auto &it : ans)
    //     cout << it << " ";

    // resetting vis array
    fill(vis.begin(), vis.end(), 0);
    vector<int> col(n + 1);
    int comp = 1;
    for (auto i : ans)
    {
        if (!vis[i])
        {
            comp_in_revgraph(i, vis, revAdj, comp++, col);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << i << " " << col[i] << endl;
    cout << comp - 1;
}

int main()
{
    solve();
}