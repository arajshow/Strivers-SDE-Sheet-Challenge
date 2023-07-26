#include <bits/stdc++.h> 

int solve(int p, vector<int> pos, int md){

	int count  = 1, pre=pos[0];

	for(int i=1; i<pos.size(); i++){
		if(pos[i]-pre>=md){
			count++;
			pre = pos[i];
		}
	}

	return count;

}

int chessTournament(vector<int> pos , int n ,  int c){
	// Write your code here 68
	sort(pos.begin(), pos.end());

	int low = 0, high = pos[n-1] - pos[0], ans=0;

	while(low<=high){
		int md = low + (high-low)/2;

		int plr = solve(c, pos, md);

		if(plr<c){
			high = md-1;
		}else{
			ans = md;
			low = md+1;
		}
	}

	return ans;
}
