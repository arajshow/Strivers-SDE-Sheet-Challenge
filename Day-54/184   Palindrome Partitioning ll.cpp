#include <bits/stdc++.h>
int dp[104];

bool isPalindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

// int solve(int ind, int n, string str) {
//   if (ind == n)
//     return 0;

//   if (dp[ind] != -1)
//     return dp[ind];

//   int mini = INT_MAX;
//   for (int k = ind; k < n; k++) {
//     if (isPalindrome(str.substr(ind, k - ind + 1)))
//       mini = min(mini, 1 + solve(k + 1, n, str));
//   }

//   return dp[ind] = mini;
// }

// int palindromePartitioning(string str) {
//   int n = str.size();
//   memset(dp, -1, sizeof(dp));
//   return solve(0, n, str) - 1; // at last there is partition
// }

int palindromePartitioning(string str) {
  int n = str.size();
  memset(dp, 0, sizeof(dp));

  for (int i = n - 1; i >= 0; i--) {
    int mini = INT_MAX;
    for (int k = i; k < n; k++)
      if (isPalindrome(str.substr(i, k - i + 1)))
        mini = min(mini, 1 + dp[k + 1]);

    dp[i] = mini;
  }

  return dp[0] - 1;
}





//different approach


#include <bits/stdc++.h> 

bool ispalin(int i, int j,string str){

    while(i<j){

        if(str[i]!=str[j])return false;

        i++;

        j--;

    }

    return true;

}

int f(int i,int n,string str, vector<int>&dp){

    if(i==n){

        return 0;

    }

    int mincut=INT_MAX;

 

    if(dp[i]!=0)return dp[i];

    for(int j=i;j<n;j++){

        if(ispalin(i,j,str)){

            int cut=1+f(j+1, n, str, dp);

            mincut=min(mincut,cut);

        }

    }

    return dp[i]=mincut;

}

int palindromePartitioning(string str) {

    // Write your code here

    int n=str.size();

    vector<int>dp(n,0);

    return f(0,n,str,dp)-1;

}

 
