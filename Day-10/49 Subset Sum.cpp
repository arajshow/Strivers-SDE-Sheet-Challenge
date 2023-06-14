#include <bits/stdc++.h> 

void solve(vector<int> &ans, vector<int> num, int sm, int st, int n){

    if(st==n){
        ans.push_back(sm);
        return;
    }


    solve(ans, num, sm + num[st], st+1, n);

    solve(ans, num, sm, st+1, n);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    sort(num.begin(), num.end());
// 1 4 6 7 9
    vector<int> ans;
    int n = num.size(), sm = 0, st = 0;

    solve(ans, num, sm, st, n);

    sort(ans.begin(), ans.end());

    return ans;
}
