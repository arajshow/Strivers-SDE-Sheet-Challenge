#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    // long long int ans = 0, mx = 0;

    // // maine approach min(leftMax, rightMax) - arr[i];

    // vector<int> preffix(n, 0);
    // vector<int> suffix(n, 0);
    
    // for(int i=0; i<n; i++){
    //     if(mx<arr[i]){
    //         mx = arr[i];
    //     }

    //     preffix[i] = mx;
    // }
    // mx = 0;
    
    // for(int i=n-1; i>=0; i--){
    //     if(mx<arr[i]){
    //         mx = arr[i];
    //     }

    //     suffix[i] = mx;
    // }


    // // ittrate over each index
    // for(int i=0; i<n; i++){
    //     mx = min(preffix[i], suffix[i]) - arr[i];

    //     if(mx>0){
    //         ans+=mx;
    //     }
    // }

    // return ans;

    long long int ans = 0, lt=0, rt= n-1, leftMax=0, rightMax = 0;

    while(lt<rt){

        if(arr[lt]<=arr[rt]){
            if(arr[lt]>=leftMax){
                leftMax = arr[lt];
                
            }else{
                ans+= leftMax - arr[lt];
            }
            lt++;
        }else{
            if(arr[rt]>=rightMax){
                rightMax = arr[rt];
                
            }else{
                ans+= rightMax - arr[rt];
            }
            rt--;
        }
    }

    return ans;

}
