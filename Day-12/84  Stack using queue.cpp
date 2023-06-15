#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q1;
    queue<int> q2;
    int n1, n2;

   public:
    Stack() {
        // Implement the Constructor.
        n1 = 0;
        n2 = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        if(n1==0) return n2;
        return n1;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return (n1==0 && n2==0);
    }

    void fill(queue<int> &q1, queue<int> &q2){

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void push(int element) {
        // Implement the push() function.
        if(n1==0){
            q1.push(element);
            fill(q1, q2);
        }else{
            q2.push(element);
            fill(q2, q1);
        }

        n1 = q1.size();
        n2 = q2.size();
    }

    int pop() {
        // Implement the pop() function.
        int cur = -1;
        if(n1!=0){
            cur = q1.front();
            q1.pop();

        }else if(n2!=0){
            cur = q2.front();
            q2.pop();
        }


        n1 = q1.size();
        n2 = q2.size();
        return cur;
    }

    int top() {
        // Implement the top() function.
        int cur = -1;
        if(n1!=0){
            cur = q1.front();

        }else if(n2!=0){
            cur = q2.front();
        }

        return cur;
    }
};
