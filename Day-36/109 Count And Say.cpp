#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.109	
	if(n==1) return "1";

	string str = writeAsYouSpeak(n-1), ans = "";
	n= str.size();
	int count  = 1;
	char pre = str[0];

	for(int i=1; i<n; i++){
		if(str[i] == pre){
			count++;
		}
		else{
			ans = ans + to_string(count) + (pre);
			count = 1;
			pre = str[i];
		}
	}

	ans = ans + to_string(count) + (pre);

	return ans;

}
