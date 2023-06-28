
void solve(vector<int> &ans, int st, vector<int> adj[], vector<bool> &vis){

    vis[st] = true;
    ans.push_back(st);

    for(auto it : adj[st]){
        if(!vis[it]){
            solve(ans, it, adj, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here 158
    vector<int> adj[V];
    vector<vector<int>> ans;

    for(auto nod : edges){
        int u= nod[0];
        int v = nod[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(V, false);

    for(int i=0; i<V; i++){
        vector<int> res;
        if(!vis[i]){
            solve(res, i, adj, vis);
            ans.push_back(res);
        }
    }

    return ans;
}
