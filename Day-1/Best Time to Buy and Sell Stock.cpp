#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mn = prices[0], n = prices.size(), ans = 0;

    for(int i=1; i<n; i++){
        if(prices[i]>mn){
            ans = max(ans, prices[i] - mn);
        }else{
            mn = prices[i];
        }
    }

    return ans;
}
