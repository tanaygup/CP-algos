// find farthest distance node from root
// then dfs and find farthest node from this root
// that will be answer

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MAX= 2e5+5;
vector<vector<int>>adj(MAX);
vector<int>dist(MAX);

void dfs(int node,int parent){
    for(int x:adj[node]){
        if(x!=parent){
            dist[x]= dist[node]+1;
            dfs(x,node);
        }
    }
}




int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>g(n-1);
    for(int i=0;i<n-1;i++)cin>>g[i].first>>g[i].second;
    for(auto& p:g){
        int u=p.first,v=p.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[1]=0;
    dfs(1,0);
    int maxi=0,node=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>maxi){
            maxi=dist[i];
            node=i;
        }
        
    }
    
    for(int i=1;i<=n;i++){
        dist[i]=0;
    }
    dfs(node,0);
    maxi=*max_element(dist.begin(),dist.end());
    cout<<maxi<<endl;
    

}
