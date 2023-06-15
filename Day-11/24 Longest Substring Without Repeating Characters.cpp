#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.size(), l =  0, r = 0, ans = 0;
    
    vector<bool> vis(26, 0);

    while(r<n && r>=l){
        int c = input[r] - 97;
        if(!vis[c]){
            vis[c] = true;
            r++;
        }else{
            ans = max(ans, r - l);
            c = input[l] - 97;
            vis[c] = false;
            l++;
        }
    }

    ans = max(ans, r-l);

    return ans;
}
