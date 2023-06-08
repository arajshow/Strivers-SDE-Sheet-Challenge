#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	unordered_map<int, int> mp;

	for(int i=0; i<n; i++){
		mp[arr[i]]++;
	}

	int ans = -1, mx=0, flr = floor(n/2);

	for(int i=0; i<n; i++){
		if(mp[arr[i]]>mx){
			mx = mp[arr[i]];
			ans = arr[i];
		}
	}

	if(mx>flr)
		return ans;
	return -1;
}
