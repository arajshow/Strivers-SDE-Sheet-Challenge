#include <bits/stdc++.h> 

bool isPalindrom(string s, int st, int en){

    while(st<en){
        if(s[st]==s[en]){
            st++;
            en--;
        }else return false;
    }

    return true;
}

void solve(int st, int n, string s, vector<vector<string>> &ans, vector<string> &temp){

    if(st==n){
        ans.push_back(temp);
    }

    for(int i=st; i<n; i++){
        temp.push_back(s.substr(st, i-st + 1));
        if(i==st){
            solve(i+1, n, s, ans, temp);
        }else if(isPalindrom(s, st, i)){
            solve(i+1, n, s, ans, temp);
        }
        temp.pop_back();
    }
}


vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    int n = s.size(), st = 0;

    vector<vector<string>> ans;
    vector<string> temp;

    solve(st, n, s, ans, temp);

    return ans;


}
