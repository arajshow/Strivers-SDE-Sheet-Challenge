#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int ans = 0;
    int value = (str[0]=='-')? -1: 1;
    for(auto c : str){
        if(c>57 || c<48) continue;
        else{
            ans*=10;
            ans+= (c-48);
        }
    }

    return ans*value;
}
