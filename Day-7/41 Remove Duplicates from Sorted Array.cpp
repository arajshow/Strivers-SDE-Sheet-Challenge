int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int ans = 1;
	if(n==0) return 0;

	for(int i=1; i<n; i++){
		if(arr[i]==arr[i-1]) continue;
		else{
			ans++;
		}
	}
	return ans;
}
