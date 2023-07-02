#include <bits/stdc++.h> 

#define pi pair<int, int>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.166
    vector<int> ans(vertices, 2147483647);
    ans[source] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, source});

    vector<pair<int, int>> adj[vertices];

    for(auto it : vec){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    while(!q.empty()){
        int node = q.top().second;
        int wt = q.top().first;
        q.pop();

        for(auto it : adj[node]){
            int u = it.first;
            int adj_wt = it.second;

            if(ans[u]> wt + adj_wt){
                ans[u] = wt + adj_wt;
                q.push({ans[u], u});
            }
        }
    }

    return ans;
}
