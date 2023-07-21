



// int solve(int st, int total, int ans, vector<int> &values, vector<int> &weights, int n, int w)
// {
// 	// Write your code here
// 	if(total>=w || st>=n) return ans;

// 	int ans1=0, ans2=0;

// 	if(total + weights[st]<=w){
// 		ans1 = solve(st+1, total + weights[st], ans + values[st], values, weights, n, w);
// 	}

// 	ans2 = solve(st+1, total, ans, values, weights, n, w);

// 	return max(ans1, ans2);
// }


int maxProfit(vector<int> &values, vector<int> &weights, int n, int W)
{
	// Write your code here
	// int total=0, ans = 0, st = 0;
	

	// return solve(st, total, ans, values, weights, n, w);
	
	vector<vector<int>> dp(n, vector<int>(W+1, 0));  //value, weight

        //   for base case of only one element; 174
        for(int i= weights[0]; i<=W; i++){
            if(0<=W- i)
                dp[0][i] = values[0];
        }
        
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=W; j++){
                int inc=0, exc=0;
                if(j-weights[i]>=0){
                    inc+= values[i] + dp[i-1][j-weights[i]];
                }
                
                exc = dp[i-1][j];
                
                dp[i][j] = max(inc, exc);
            }
        }
        
        return dp[n-1][W];
}
