#include <bits/stdc++.h> 


void solve(vector<int>v, int st, int n, vector<int> &temp, vector<vector<int>> &ans){

    if(st==n){
        ans.push_back(temp);
        return;
    }

    

        solve(v, st+1, n, temp, ans);
        temp.push_back(v[st]);

        solve(v, st+1, n, temp, ans);

        temp.pop_back();
}


vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here

    vector<vector<int>> ans;

    vector<int> temp;

    int n = v.size();

    solve(v, 0,  n, temp, ans);

    return ans;
}
