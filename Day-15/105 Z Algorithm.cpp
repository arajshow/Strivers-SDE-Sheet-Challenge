int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here

	if(m>n) return 0;

	
	int sm = 0, count = 0;

	while(s.find(p)<n){
		int cur = s.find(p);
		s = s.substr(cur + 1);
		count++;
		sm+=(cur + 1);
	}

	return count;
}
