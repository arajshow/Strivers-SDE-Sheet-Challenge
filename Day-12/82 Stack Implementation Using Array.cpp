#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int> store;
    int n;
    int st;
    
    Stack(int capacity) {
        // Write your code here.
        n = capacity;
        st = 0;
        store.resize(n, 0);

    }

    void push(int num) {
        // Write your code here.
        if(st>=n) return;
        store[st++] = num;
    }

    int pop() {
        // Write your code here.
        if(st==0) return -1;
        int cur = store[--st];
        return cur;
    }
    
    int top() {
        // Write your code here.
        if(st==0) return -1;
        return store[st-1];
    }
    
    int isEmpty() {
        // Write your code here.
       if(st==0) return 1;
       return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(st==n) return 1;
        return 0;
    }
    
};
