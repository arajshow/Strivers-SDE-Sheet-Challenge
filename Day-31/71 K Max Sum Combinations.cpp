#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.

	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(k-->0){
				q.push(a[i] + b[j]);
				continue;
			}

			if(q.top()<a[i]+b[j]){
				q.pop();
				q.push(a[i] + b[j]);
			}
		}
	}

	vector<int> ans;
	while(!q.empty()){
		ans.push_back(q.top());
		q.pop();
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
