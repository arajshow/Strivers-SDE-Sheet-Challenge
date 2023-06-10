#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int k) {
	// Write your code here.
	vector<vector<int>> ans;
	// for unique answer let store them in sorted form
	sort(arr.begin(), arr.end());

	int st=0, j = 1, en = n-1;

	while(st<j && j<en){
		int sm = arr[st] + arr[j] + arr[en];
		int cur;
		while(j<en){
			int rem = k - arr[st];
			sm = arr[j] + arr[en];

			if(sm>rem){
				cur = arr[en];
				while(en>=0 && arr[en]==cur) en--;
			}else if(sm<rem){
				cur = arr[j];
				while(j<n && arr[j]==cur) j++;
			}else{
				ans.push_back({arr[st], arr[j], arr[en]});
				cur = arr[j];
				while(j<n && arr[j]==cur) j++;

				cur = arr[en];
				while(en>=0 && arr[en]==cur) en--;
			}
		}
		cur = arr[st];
		while(st<n && arr[st]==cur) st++;
		j = st+1;
		en = n-1;
	}

	return ans;
}
