#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    unordered_map<int, int> :: iterator it;
    
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    
    priority_queue<pair<int, int>> q;
    it = mp.begin();

    while(it!=mp.end()){
        q.push({it->second, it->first});
        it++;
    }

    vector<int> ans;

    while(k--){
        ans.push_back(q.top().second);
        q.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
    
}
