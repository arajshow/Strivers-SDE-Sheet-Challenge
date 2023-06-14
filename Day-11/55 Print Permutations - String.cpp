#include <bits/stdc++.h> 

void solve(string s, int st, int n, vector<string> &ans){
    if(st==n){
        ans.push_back(s);
        return;
    }
    
    for(int i=st; i<=n; i++){
        string cur  = s;
        if(i==st){
            solve(cur, st+1, n, ans);
            continue;
        }else{
            char temp = cur[i];
            cur[i] = cur[st];
            cur[st] = temp;
            solve(cur, st+1, n, ans);
        }
    }
}

vector<string> findPermutations(string &S) {
    // abcd

    if(S.size()==1) return {S};
    vector<string> ans;
    int n = S.size(), st = 0;

    solve(S, st, n-1, ans);
    
    return ans;


}
