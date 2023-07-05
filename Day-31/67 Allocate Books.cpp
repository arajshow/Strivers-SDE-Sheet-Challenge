#include <bits/stdc++.h> 

long long int maxday(vector<int> arr, long long int md){
	
	long long int ans = 1, sm = 0;
	
	for(int i=0; i<arr.size(); i++){
		
		if(sm + arr[i]<=md){
			sm+=arr[i];
		}else{
			if(arr[i]>md) return INT_MAX;
			sm = arr[i];
			ans++;
		}
	}

	return ans;
	
	
}


long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here. 67
	long long int low = *max_element(time.begin(), time.end()), high = 1e18, ans = 1e18;

	while(low<=high){
		long long int md = low + (high -low)/2;

		long long int count = maxday(time, md);

		if(count>n){
			low = md + 1;
		}else{
			high = md - 1;
			ans = md;
		}
	}

	return ans;
}
