bool solve(int st, vector<bool> &vis, vector<int> adj[], int par){

    vis[st] = true;

    for(auto it : adj[st]){
        if(!vis[it]){
            if(solve(it, vis, adj, st)) return true;
        }else{
            if(it==par) continue;
            else return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here. 160
    vector<int> adj[n+1];

    for(auto it : edges){
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(solve(i, vis, adj, -1)) return "Yes";
        }
    }

    return "No";
}
