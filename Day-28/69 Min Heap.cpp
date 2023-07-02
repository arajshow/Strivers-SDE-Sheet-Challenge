#include <bits/stdc++.h> 

void insertData(vector<int> &arr, int d){
    int n = arr.size();
    arr.push_back(d);

    while(n>0){
        int par = (n-1)/2;
        if(arr[par]>d){
            int t = arr[par];
            arr[par] = d;
            arr[n] = t;
            n = par;
        }else break;
    }
}

int removedata(vector<int> &arr, int &d){
    int n = arr.size()-1;
    d = arr[0];
    arr[0] = arr[n];
    arr.pop_back();
    int t  = 0;
    while(t<n){
        int c1 = (2*t + 1<n)? arr[2*t + 1] : INT_MAX;
        int c2 = (2*t + 2<n)? arr[2*t + 2] : INT_MAX;

        if(c1<c2){
            if(arr[t]>c1){
                int temp = arr[t];
                arr[t] = c1;
                arr[2*t + 1] = temp;
                t = 2*t + 1;
            }else if(arr[t]>c2){
                int temp = arr[t];
                arr[t] = c2;
                arr[2*t + 2] = temp;
                t = 2*t + 2;                
            }else break;
        }else{
            if(arr[t]>c2){
                int temp = arr[t];
                arr[t] = c2;
                arr[2*t + 2] = temp;
                t = 2*t + 2;
            }else if(arr[t]>c1){
                int temp = arr[t];
                arr[t] = c1;
                arr[2*t + 1] = temp;
                t = 2*t + 1;                
            }else break;          
        }

    }

    return d;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.

    vector<int> heaparr;
    vector<int> ans;

    for(auto it : q){
        int c = it[0], d = 0;
        if(c==0){
            d = it[1];
            insertData(heaparr, d);
        }else{
            d = removedata(heaparr, d);
            ans.push_back(d);
        }
    }

    return ans;
}
