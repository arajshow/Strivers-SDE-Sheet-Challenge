#include <bits/stdc++.h> 

void solve(vector<int> arr, int st, vector<vector<int>> &ans, vector<int> v, int n){

    ans.push_back(v);
    if(st==n){
        return;
    }

    for(int i=st;i<n;i++){

        if(i>st && arr[i]==arr[i-1])continue;

        v.push_back(arr[i]);

        solve(arr, i + 1, ans, v, n);

        v.pop_back();

    }
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    int st = 0;
    vector<int> v;

    solve(arr, st, ans, v, n);

    return ans;
}
