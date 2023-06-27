#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       while(k--){
           q.push(arr[k]);
       }
    }

    void add(int num) {
        // Write your code here.
        if(q.top()<num){
            q.pop();
            q.push(num);
        }
    }

    int getKthLargest() {
       // Write your code here.
       return q.top();
    }

};
