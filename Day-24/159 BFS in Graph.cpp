#include <bits/stdc++.h> 

void solve(int st, vector<bool> &vis, set<int> adj[], vector<int> &ans){

    vis[st] = true;

    queue<int> q;
    q.push(st);


    while(!q.empty()){
        int ft = q.front();
        q.pop();
        ans.push_back(ft);

        for(auto it : adj[ft]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here 159
    set<int> adj[vertex];

    for(auto it : edges){
        int u = it.first;
        int v = it.second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> ans;
    vector<bool> vis(vertex, false);

    for(int i=0; i<vertex; i++){
        if(!vis[i]){
            solve(i, vis, adj, ans);
        }
    }

    return ans;
    
}
