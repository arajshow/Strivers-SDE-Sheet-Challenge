#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dis(n+1, 1000000000);
    dis[src] = 0;

    for(int i=0; i<n-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dis[v] > dis[u] + wt){
                dis[v] = dis[u] + wt;
                // cout<<v<<"node weight "<<dis[v]<<endl;
            }
        }
    }
    if(dis[dest]>1e8){
        return 1000000000;
    }
    return dis[dest];
}
