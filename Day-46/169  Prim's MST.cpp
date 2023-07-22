#include <bits/stdc++.h> 
#define pi pair<int, pair<int, int>> //weight node parent

vector<pair<pair<int, int>, int>> 
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.169
    vector<pair<pair<int, int>, int>> ans;
    priority_queue<pi, vector<pi>, greater<pi>> q;

    vector<vector<int>> adj[n+1];
    for(auto it : g){
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<bool> vis(n+1, false);

    q.push({0, {1, -1}});
    vis[1] = true;
    int idx = 0;

    while(!q.empty()){
        pi p = q.top();
        q.pop();

        int wt = p.first;
        int u = p.second.first;
        int par = p.second.second;

        // cout<<wt<<" wt "<<u<<" u "<<par<<endl;

        if(!vis[u]){
            ans.push_back({{par, u}, wt});
            vis[u] = true;
        }

        for(auto it : adj[u]){

            int v = it[0];
            int adj_wt = it[1];

            if(!vis[v]){
                q.push({adj_wt, {v, u}});
            }
        }
    }

    return ans;
}
