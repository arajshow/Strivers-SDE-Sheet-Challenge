#include <bits/stdc++.h> 

// void solve(vector<int> &rack, int st, vector<int> &vis, int n, int &ans){

// 	if(st>=n){
// 		int temp = accumulate(vis.begin(), vis.end(), 0);
// 		ans = max(ans, temp);
// 		return;
// 	}

// 	if(vis.size()==0 || vis.back()<rack[st]){
// 		vis.push_back(rack[st]);
// 		solve(rack, st+1, vis, n, ans);
// 		vis.pop_back();
// 	}

// 	solve(rack, st+1, vis, n, ans);
// }

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here176
	// increasing subsequence problem

	// vector<int> vis;
	// int ans= 0;

	// solve(rack, 0, vis, n, ans);

	// return ans;

	vector<pair<int, int>> dp(n+1, {0, 0});  //pre_elm, total_sum
	int ans =0;

	for(int i=1; i<=n; i++){
		for(int j=i-1; j>=0; j--){
			if(dp[j].first<rack[i-1]){
				if(dp[i].second<dp[j].second + rack[i-1]){
					dp[i] = {rack[i-1], dp[j].second + rack[i-1]};
				}
			}
		}

		ans = max(ans, dp[i].second);
	}

	return ans;

	

}
