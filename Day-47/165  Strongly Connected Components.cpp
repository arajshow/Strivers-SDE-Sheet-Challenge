
void dfs2(int node, vector<bool> &vis, vector<int> &st, vector<int> adj[]){

    vis[node] = true;

    for(auto it : adj[node]){

        if(!vis[it]){
            dfs2(it, vis, st, adj);
        }
    }

    st.push_back(node);
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here. 165
    vector<int> adj[n];
    vector<vector<int>> ans;

    for(auto it: edges){
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }

    vector<bool> vis(n, false);
    vector<int> st;

    for(int i=0; i<n; i++){

        if(!vis[i]){
            dfs2(i, vis, st, adj);
        }
    }

    vector<int> adjT[n];
    for(int i=0; i<n; i++){
        vis[i] = false;
        for(auto it: adj[i]){
            adjT[it].push_back(i);
        }
    }

    int id=n;
    while(id--){
        int node = st[id];

        if(!vis[node]){
            vector<int> res;

            dfs2(node, vis, res, adjT);
            ans.push_back(res);
        }
    }

    return ans;

}
