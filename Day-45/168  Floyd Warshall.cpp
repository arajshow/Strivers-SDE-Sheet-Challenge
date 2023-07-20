int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // flloyd warshall's algo 168

    // technique is to go through one node to another with each node come between them

    vector<vector<int>> dis(n+1, vector<int>(n+1, 1000000000));

    for(int i=1; i<=n; i++){
        dis[i][i] = 0;
    }

    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        dis[u][v] = wt;
    }

    for(int i=1; i<=n; i++){

        for(int a=1; a<=n; a++){
            if(a==i) continue;
            for(int b=1; b<=n; b++){
                if(b==i || b==a) continue;

                if(dis[a][i]==1e9 || dis[i][b]==1e9) continue;

                if(dis[a][b]> dis[a][i] + dis[i][b]){
                    dis[a][b] = dis[a][i] + dis[i][b];
                }
            }
        }
    }

    // if(dis[src][dest]>1e8) return 1000000000;
    return dis[src][dest];
}
