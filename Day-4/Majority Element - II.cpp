#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
	unordered_map<int, int> mp;
    int n = arr.size();

	for(int i=0; i<n; i++){
		mp[arr[i]]++;
	}

    vector<int> ans;

	int mx=0, flr = floor(n/3);

	for(auto it : mp){
		if(it.second>flr){
			ans.push_back(it.first);
		}
	}

    return ans;

}
