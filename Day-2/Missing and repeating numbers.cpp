#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<bool> vis(n, false);

	int m= -1, r = -1;

	for(auto it : arr){
		if(!vis[it-1]){
			vis[it-1] = true;
		}else{
			r = it;
		}
	}

	for(int i=0; i<n; i++){
		if(!vis[i]){
			m = i+1;
			break;
		}
	}

	return {m, r};

	
}
