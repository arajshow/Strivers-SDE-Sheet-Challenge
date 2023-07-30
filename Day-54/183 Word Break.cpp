#include <bits/stdc++.h> 
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.

    unordered_map<string, bool> mp;

    for(auto it: arr) mp[it] = true;

    int pre = 0;

    for(int i=0; i<target.size(); i++){
        string temp = target.substr(pre, i+1-pre);
        if(mp[temp]){
            pre = i+1;
        }
    }

    if(pre == target.size()) return true;
    return false;
}
