#include <bits/stdc++.h> 
// int solve(int nums[], int i, int prev_i, vector<vector<int>> &dp, int n) {
//     if(i >= n) return 0;
//     if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
//     int take = 0, dontTake = solve(nums, i + 1, prev_i, dp, n);
//     if(prev_i == -1 || nums[i] > nums[prev_i]) take = 1 + solve(nums, i + 1, i, dp, n); // try picking current element if no previous element is chosen or current > nums[prev_i]
//     return dp[i][prev_i+1] = max(take, dontTake);
// }



int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // vector<vector<int>> dp(n, vector<int>(n+1, -1));
    // return solve(arr, 0, -1, dp, n);


    vector<int>a;
    a.push_back(arr[0]);
    for(int i=1;i<n;i++){
        int in=lower_bound(a.begin(),a.end(),arr[i])-a.begin();
        if(in>=a.size())a.push_back(arr[i]);
        else a[in]=arr[i];
    }
    return a.size();
}



    
