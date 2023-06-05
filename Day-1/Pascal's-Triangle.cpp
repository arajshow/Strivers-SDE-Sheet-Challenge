#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> ans;
  if(n==0) return ans;

  if(n==1){
    ans.push_back({1});
    return ans;
  }else if(n==2){
    ans.push_back({1});
    ans.push_back({1,1});
    return ans;
  }

  ans = printPascal(n-1);
  vector<long long int> pre = ans[n-2];
  vector<long long int> cur;
  cur.push_back(1);

  for(int i=1; i<pre.size(); i++){
    cur.push_back(pre[i]+pre[i-1]);
  }
  cur.push_back(1);

  ans.push_back(cur);



  return ans;
}
