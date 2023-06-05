#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int count0=0, count1=0, count2=0;
   for(int i=0; i<n; i++){
      if(arr[i]==0){
         count0++;
      }else if(arr[i]==1){
         count1++;
      }else count2++;
   }

   int ans = 0;
   for(int i=0; i<n; i++){
      if(count0>0){
         count0--;
         ans = 0;
      }else if(count1>0){
         count1--;
         ans = 1;
      }else{
         count2--;
         ans = 2;
      }

      arr[i] = ans;
   }
}
