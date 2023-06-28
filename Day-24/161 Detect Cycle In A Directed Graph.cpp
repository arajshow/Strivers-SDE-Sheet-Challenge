
bool solve(int st, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsvis){

  vis[st] = true;
  dfsvis[st] = true;

  for(auto it : adj[st]){

    if(vis[it] && dfsvis[it]) return true;
    else if(!vis[it]){
      if(solve(it, adj, vis, dfsvis)) return true;
    }
  }



  dfsvis[st] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.161

  // using dfs
  vector<int> adj[n+1];
  for(auto it : edges){
    int u = it.first;
    int v = it.second;

    adj[u].push_back(v);
  }

  vector<bool> vis(n+1, false);
  vector<bool> dfsvis(n+1, false);

  for(int i=1; i<=n; i++){
    if(!vis[i]){
      if(solve(i, adj, vis, dfsvis)) return 1;
    }
  }

  return 0;
}
