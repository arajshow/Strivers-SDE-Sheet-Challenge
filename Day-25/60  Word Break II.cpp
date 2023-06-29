#include <bits/stdc++.h> 

void solve(int st, string s, string &str, vector<string> &ans, unordered_map<string, bool> mp, int n, int sm){

    if(st==n){
        ans.push_back(str);
        return;
    }

    for(int i= st; i<n; i++){
        string cur = s.substr(st, i-st + 1);

        if(mp[cur]){
            string temp = str;
            temp.insert(i+sm, " ");
            sm++;
            solve(i+1, s, temp, ans, mp, n, sm);
            sm--;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here 60

    vector<string> ans;

    unordered_map<string, bool> mp;

    for(auto str : dictionary){
        mp[str] = true;
    }

    string str = s;

    solve(0, s, str, ans, mp, s.size(), 1);

    return ans;

}
