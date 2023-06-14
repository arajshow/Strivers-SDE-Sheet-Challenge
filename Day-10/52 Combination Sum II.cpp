#include <bits/stdc++.h> 

void solve(int st, int sm, int n, int k, vector<int> arr, vector<vector<int>> &ans, vector<int> &v){

    if(sm==k){
        ans.push_back(v);
		return;
    }else if(sm>k) return;

	if(st==n) return;

    for(int i=st; i<n; i++){
		if(i>st && arr[i]==arr[i-1]) continue;
        v.push_back(arr[i]);
        solve(i+1, sm + arr[i], n, k, arr, ans, v);

        v.pop_back();

    }
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(), arr.end());

	vector<vector<int>> ans;

	vector<int> v;
	int st = 0, sm = 0;

	solve(st, sm, n, target, arr, ans, v);

	return ans;
}
