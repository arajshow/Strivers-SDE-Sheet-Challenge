#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code hereint 
    int st = 0, n = arr.size();
    vector<int> ans;
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        if(i<k){
            mp[arr[i]]++;
            continue;
        }

        int siz = mp.size();

        ans.push_back(siz);
        mp[arr[st]]--;
        if(mp[arr[st]]==0){
            mp.erase(arr[st]);
        }
        mp[arr[i]]++;
        st++;

    }

    int siz = mp.size();

    ans.push_back(siz);

    return ans;
	
}
