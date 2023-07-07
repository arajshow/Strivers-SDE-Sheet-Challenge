#include <bits/stdc++.h> 
int distinctSubstring(string &word) {
    //  Write your code here.

    unordered_map<string, bool> mp;

    for(int i=0; i<word.size(); i++){
        for(int j=i; j<word.size(); j++){
            mp[word.substr(i, j-i + 1)] = true;
        }
    }

    return mp.size();
}
