#include <bits/stdc++.h> 

vector<int> mergeIt(vector<int> temp, vector<int> arr){

    vector<int> ans;

    int a1=0, a2=0,n1 = temp.size(), n2= arr.size();

    while(a1<n1 && a2<n2){
        if(temp[a1]<arr[a2]){
            ans.push_back(temp[a1]);
            a1++;
        }else{
            ans.push_back(arr[a2]);
            a2++;
        }
    }

    while(a1<n1){
        ans.push_back(temp[a1]);
        a1++;        
    }

    while(a2<n2){
        ans.push_back(arr[a2]);
        a2++;        
    }

    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans(kArrays[0]);

    for(int i=1; i<k; i++){
        ans = mergeIt(ans, kArrays[i]);
    }

    return ans;
}
