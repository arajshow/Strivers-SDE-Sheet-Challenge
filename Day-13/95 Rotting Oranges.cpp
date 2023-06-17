#include <bits/stdc++.h>
#define pi pair<pair<int, int>, int>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pi> q;
    int ans = 0, fresh = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1) fresh++;
            else if(grid[i][j]==2){
                q.push({{i, j}, 0});
            }
        }
    }

    while(!q.empty()){
        pi p = q.front();
        q.pop();

        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};

        for(int i=0; i<4; i++){
            int r = p.first.first + x[i];
            int c = p.first.second + y[i];

            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1){
                grid[r][c] = 2;
                q.push({{r, c}, p.second +1});
                fresh--;
            }
        }

        ans = max(ans, p.second);
    }

    if(fresh>0) return -1;
    return ans;
}
