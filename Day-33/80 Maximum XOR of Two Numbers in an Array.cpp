#include <bits/stdc++.h> 

class Node{

    public:

    Node* bit[2];

    void put(int c, Node *node){
        bit[c] = node;
    }

    Node *get(int c){
        return bit[c];
    }
};

class Trie{

    public:
    Node *root;

    Trie(){
        root = new Node();
    }

    void insert(int n){

        int ans  = 0;
        Node *node = root;
        for(int i=31; i>=0; i--){
            int c = (n>>i) & 1;
            if(node->bit[c]==NULL){
                node->put(c, new Node());
            }

            node = node->get(c);
        }
    }

    int getXor(int n){

        int ans  = 0;
        Node *node = root;
        for(int i=31; i>=0; i--){
            int c = (n>>i) & 1;
            c = 1 - c; //xor needs opposite bit
            if(node->bit[c]!=NULL){
                ans = ans | (1<<i);
                if(i==0) continue;
                node = node->get(c);
            }else{
                if(i==0)  continue;
                node = node->get(1 - c);
            }
  
        }
        // cout<<"ans"<<endl;

        return ans;

    }
};

int maximumXor(vector<int> A)
{
    // Write your code here.   80

    int n = A.size(), ans = 0;

    Trie *root = new Trie();

    for(auto it: A){
        
        root->insert(it);
    }

    for(auto it: A){
        ans = max( root->getXor(it), ans);
    }

    return ans;


}
