#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here. 108
    unordered_map<char, int> mp;

    for(auto it : str1){
        mp[it]++;
    }

    for(auto it: str2){
        mp[it]--;
        if(mp[it]==0){
            mp.erase(it);
        }
    }

    if(mp.size()==0) return true;
    return false;
}
