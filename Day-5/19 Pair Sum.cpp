#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;
   int n = arr.size();

   sort(arr.begin(), arr.end());
   
//   brute force approach
   for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
         if(arr[i] + arr[j] == s){
            ans.push_back({arr[i], arr[j]});
         }
      }
   }

   return ans;
}
