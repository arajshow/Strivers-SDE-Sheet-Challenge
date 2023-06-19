#include <bits/stdc++.h> 
int romanToInt(string s) {
    // Write your code here
    unordered_map<char, pair<int, int>> mp;

    mp['I'] = {1, 0};
    mp['V'] = {5, 1};
    mp['X'] = {10, 2};
    mp['L'] = {50, 3};
    mp['C'] = {100, 4};
    mp['D'] = {500, 5};
    mp['M'] = {1000, 6};

    int pre = mp[s[0]].second, n = s.size();
    int ans = mp[s[0]].first;
    int pre_value = ans;

    for(int i=1; i<n; i++){
        char c = s[i];

        if(pre>=mp[c].second){
            pre = mp[c].second;
            pre_value = mp[c].first;
            ans+=mp[c].first;
        }else{
            int value = mp[c].first;
            ans-=pre_value;
            ans+= value -pre_value;
            pre = mp[c].second;
            pre_value = value;
        }
    }

    return ans;


}
