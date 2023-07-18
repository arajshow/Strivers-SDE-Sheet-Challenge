#include<vector>
int solve(int st, string s, int n, int tt, string t, int m, vector<vector<int>> &dp){

	if(st>=n || tt>=m) return 0;

	if(dp[st][tt]!=-1) return dp[st][tt];

	if(s[st]==t[tt]){
		dp[st][tt] =  1 + solve(st+1, s, n, tt+1, t, m, dp);
		return dp[st][tt];
	}

	dp[st][tt] =   max(solve(st+1, s, n, tt, t, m, dp), solve(st, s, n, tt+1, t, m, dp));
	return dp[st][tt];
}

int lcs(string s, string t)
{
	//Write your code here 173

	vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));

	return solve(0, s, s.size(), 0, t, t.size(), dp);
}
