#include <bits/stdc++.h> 

class Queue {
    // Define the data members(if any) here.

    public:
    stack <int> s1; //0
    stack <int> s2; //1
    int n;

    Queue() {
        n = 0;
    }

    void change(stack<int> &s1, stack<int> &s2){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);

    }

    int deQueue() {
        // Implement the dequeue() function.
        int ans = -1;
        if(s2.empty()){
            change(s1, s2);
            if(!s2.empty()){
                ans = s2.top();
                s2.pop();
            }
        }else{
            ans = s2.top();
            s2.pop();
        }

        return ans;
    }

    int peek() {
        // Implement the peek() function here.
        int cur = -1;
        if(s2.empty()){
            change(s1, s2);
            if(!s2.empty()){
                cur = s2.top();
            }
        }else{
            cur = s2.top();
        }       

        return cur;

    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (s1.size()==0 && s2.size()==0);
    }
};
