#include <bits/stdc++.h> 

void dfs(int st, stack<int> &s, vector<bool> &vis, vector<int> adj[]){

    vis[st] = true;

    for(auto it : adj[st]){
        if(!vis[it]){
            dfs(it, s, vis, adj);
        }
    }

    s.push(st);

}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here 162

    vector<int> adj[v];

    for(auto it : edges){
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }

    // using dfs
    stack<int> s;

    vector<bool> vis(v, false);

    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, s, vis, adj);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;


}
