#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	vector<bool> vis(n, false);

	for(auto it : arr){
		if(!vis[it-1]){
			vis[it-1] = true;
		}else return it;
	}
	return 0;
}
