#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here. 178

    int n= grid.size(), m= grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0 ) continue;
            int a = (i-1>=0)? dp[i-1][j] : INT_MAX;
            int b = (j-1>=0)? dp[i][j-1] : INT_MAX;
            dp[i][j] = grid[i][j] + min(a, b);
        }
    }

    return dp[n-1][m-1];

}
