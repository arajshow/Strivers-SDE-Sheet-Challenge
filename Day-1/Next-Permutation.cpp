#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int breakPoint = -1;

    for(int i=n-1; i>0; i--){
        if(permutation[i]>permutation[i-1]){
            breakPoint = i-1;
            break;
        }
    }

    for(int i=n-1; i>0; i--){
        if(breakPoint==-1) break;
        if(permutation[i]>permutation[breakPoint]){
            int temp = permutation[i];
            permutation[i] = permutation[breakPoint];
            permutation[breakPoint] = temp;
            break;
        }
    }

    
    if(breakPoint==-1){
        int count = 1;
        for(int i=0; i<n/2; i++, count++){
        int temp = permutation[i];
        permutation[i] = permutation[n-count];
        permutation[n-count] = temp;            
        }
        return permutation;
    }

    int count = 1;
    for(int i= breakPoint+1; i<=(n + breakPoint)/2; i++, count++){
        int temp = permutation[i];
        permutation[i] = permutation[n-count];
        permutation[n-count] = temp;
    }

    return permutation;
}
