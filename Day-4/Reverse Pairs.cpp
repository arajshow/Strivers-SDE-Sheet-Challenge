#include <bits/stdc++.h> 

int mergeSort(vector<int> &arr, int st, int n){

	if(st>=n) return 0;

	int ans = 0, md = st + (n-st)/2;

	ans+= mergeSort(arr, st, md);
	ans+= mergeSort(arr, md+1, n);

	vector<int> arr1;
	vector<int> arr2;

	for(int i=st; i<=md; i++){
		arr1.push_back(arr[i]);
	}

	for(int i=md+1; i<=n; i++){
		arr2.push_back(arr[i]);
	}

	int n1 = arr1.size(), n2 = arr2.size(), i1=0, i2=0;

	while(i1<n1 && i2<n2){
		if(arr1[i1]>(2*arr2[i2])){
			ans+= (n1 - i1);
			i2++;
		}else{
			i1++;
		}
	}

	i1 = 0; i2 = 0;

	while(i1<n1 && i2<n2){
		if(arr1[i1]>arr2[i2]){
			arr[st] = arr2[i2];
			st++;
			i2++;
		}else{
			arr[st] = arr1[i1];
			st++; i1++;
		}
	}

	while(i1<n1){
		arr[st] = arr1[i1];
		st++; i1++;
	}

	while(i2<n2){
		arr[st] = arr2[i2];
		st++; i2++;
	}

	return ans;

}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.

	//we can do it using merge sort

	return mergeSort(arr, 0, n-1);	
}
