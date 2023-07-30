#include <bits/stdc++.h> 

bool solve(int n, int k, int st, int sm, vector<int> arr){

    if(st>=n){
        return sm==k;
    }

    if(sm==k) return true;

    if(solve(n, k, st+1, sm, arr)) return true;

    if(solve(n, k, st+1, sm+arr[st], arr)) return true;

    return false;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    return solve(n, k, 0, 0, arr);
}
