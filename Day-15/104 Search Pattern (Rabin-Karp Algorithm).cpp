vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int n = text.size(), m=pattern.size();

	if(m>n) return {};

	vector<int> ans;
	int sm = 0;

	while(text.find(pattern)<n){
		int cur = text.find(pattern);
		text = text.substr(cur + 1);
		ans.push_back(cur + sm +1);
		sm+=(cur + 1);
	}

	return ans;
}
