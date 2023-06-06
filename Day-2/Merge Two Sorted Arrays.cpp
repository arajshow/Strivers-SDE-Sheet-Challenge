#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.

	int a = m + n -1, i1 = m-1, i2= n-1;

	while(i2>=0){
		if(arr1[i1]>=arr2[i2]){
			arr1[a] = arr1[i1];
			i1--;
			a--;
		}else{
			arr1[a] = arr2[i2];
			i2--;
			a--;
		}
	}

	return arr1;
}
