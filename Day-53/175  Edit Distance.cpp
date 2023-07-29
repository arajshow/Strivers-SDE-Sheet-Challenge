#include<bits/stdc++.h>

int editDistance(string str1, string str2)
{
    //write you code here175
    int ans = 0, n = str1.size(), m =str2.size();
    if(n==0 || m==0) return max(n, m);

    // if(str1[0]==str2[0]) return editDistance(str1.substr(1), str2.substr(1));
    // else{
    //     if(n<m){
    //         int a = 1 + editDistance(str1, str2.substr(1));
    //         int b = 1 + editDistance(str1.substr(1), str2.substr(1));
    //         return min(a, b);
    //     }else{
    //         int a = 1 + editDistance(str1.substr(1), str2);
    //         int b = 1 + editDistance(str1.substr(1), str2.substr(1));
    //         return min(a, b);            
    //     }
        
    // }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int i=0; i<=m; i++) dp[0][i] = i;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(str1[i]==str2[j]){
                dp[i+1][j+1] = dp[i][j];
            }else{
                dp[i+1][j+1] = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i][j]));
            }
        }
    }

    return dp[n][m];
}
