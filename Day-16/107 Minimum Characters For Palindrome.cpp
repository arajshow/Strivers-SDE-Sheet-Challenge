bool isPalindrom(string s, int st, int n){
	while(st<n){
		if(s[st]!=s[n]) return false;
		st++;
		n--;
	}
	return true;
}

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.size();
	int ans = n-1, st=0;

	for(int i=n-1; i>0; i--){
		if(str[st]==str[i] && isPalindrom(str, st+1, i-1)){
			return n - i-1;
		}
	}

	return n-1;
	
}
