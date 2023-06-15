#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> arr;
    int l, r, n, size;

    Queue() {
        // Implement the Constructor
        n = 10;
        l = 0;
        r = 0;
        size = 0;
        arr.resize(n, 0);
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void exchange(int data){
        vector<int> newarr;
        for(int i=l; i<n; i++){
            newarr.push_back(arr[i]);
        }

        for(int i=0; i<l; i++){
            newarr.push_back(arr[i]);
        }

        r = n;
        n*=2;
        l = 0;
        arr.resize(n);

        for(int i=l; i<r; i++){
            arr[i] = newarr[i];
        }
        arr[r] = data;
        r++;
        size++;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(size<n){
            r%=n;
            arr[r++] = data;
            size++;
        }else{
            exchange(data);
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(size>0){
            l%=n;
            int cur = arr[l++];
            size--;
            return cur;
        }else return -1;
    }

    int front() {
        // Implement the front() function
        if(size>0){
            l%=n;
            return arr[l];
        }
        return -1;
    }
};
