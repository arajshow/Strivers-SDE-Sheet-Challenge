#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> s;

    for(int i=n-1; i>=0; i--){
        if(s.empty()){
            s.push(arr[i]);
            arr[i] = -1;
        }else{
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }

            if(!s.empty()){
                int temp = s.top();
                s.push(arr[i]);
                arr[i] = temp;
            }else{
                s.push(arr[i]);
                arr[i] = -1;
            }
        }
    }

    return arr;

}
