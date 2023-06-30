double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n = a.size(), m = b.size();
	if(n>m) return median(b, a);

	int md = (n+m)/2;

	int low = 0, high = n;

	while(low<=high){
		int cut1 = low + (high - low)/2;
		int l1 = INT_MIN, l2=INT_MIN, r1=INT_MAX, r2=INT_MAX;
		if(cut1>0)
			l1 = a[cut1-1];

		if(cut1<n)
			r1= a[cut1];

		int cut2 = md - cut1;

		if(cut2>0)
			l2 =b[cut2-1];
		
		if(cut2<m)
			r2 = b[cut2];

		if(l1<=r2 && l2<=r1){

			if((n+m)%2!=0){
				return min(r1, r2);
			}else{
				return (max(l1, l2) + min(r1, r2))/2.0;
			}
		}else if(l1>r2){
			high = cut1-1;
		}else{
			low = cut1 + 1;
		}
	}

}
