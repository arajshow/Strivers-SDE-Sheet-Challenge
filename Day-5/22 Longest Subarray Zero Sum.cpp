#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n = arr.size();
  int sm = 0;
  for(int i=0; i<n; i++){
    sm+=arr[i];
    arr[i]  = sm;
  }
  sm = 0;

  unordered_map<int, int> mp;

  for(int i=0; i<n; i++){
    if(arr[i]==0){
      sm = max(sm, i+1);
      continue;
    }
    if(mp.count(arr[i])>0){
      sm = max(sm,  i - mp[arr[i]]);
    }else{
      mp[arr[i]] = i;
    }
  }

  return sm;

}
