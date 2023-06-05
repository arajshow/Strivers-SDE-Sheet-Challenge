#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */

    long long int ans = 0, sm = 0;

    for(int i=0; i<n; i++){
        sm+=arr[i];
        if(sm<0){
            sm = 0;
        }else{
            ans = max(sm, ans);
        }
    }

    return ans;
}
