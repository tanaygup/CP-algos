// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> cycleNodes;
    unordered_map<int, int> parent; // To track parents of nodes

    bool dfs(int node, int par, vector<int>& vis, vector<vector<int>>& adjls) {
        vis[node] = 1;

        for (int neighbor : adjls[node]) {
            if (neighbor == par) continue; // Skip the parent node
            
            if (vis[neighbor]) { // Cycle detected
                cycleNodes.push_back(neighbor);
                int curr = node;
                
                // Backtrack to get all nodes in the cycle
                while (curr != neighbor) {
                    cycleNodes.push_back(curr);
                    curr = parent[curr];
                }
                cycleNodes.push_back(neighbor);
                return true;
            }
            
            parent[neighbor] = node;
            if (dfs(neighbor, node, vis, adjls)) return true;
        }

        return false;
    }

    vector<int> findCycle(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjls(n + 1);

        // Building adjacency list
        for (auto& edge : edges) {
            adjls[edge[0]].push_back(edge[1]);
            adjls[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n + 1, 0);

        // Run DFS from any node (assuming the graph is connected)
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adjls)) break;
            }
        }

        return cycleNodes;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}, {3,4}, {4,5}, {5,6}, {6,3}};
    
    vector<int> cycle = sol.findCycle(edges);
    
    cout << "Cycle Nodes: ";
    for (int node : cycle) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
