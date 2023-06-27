#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=0; i<size; i++){
		if(i<K){
			q.push(arr[i]);
			continue;
		}

		if(q.top()<arr[i]){
			q.pop();
			q.push(arr[i]);
		}
	}

	return q.top();
}
