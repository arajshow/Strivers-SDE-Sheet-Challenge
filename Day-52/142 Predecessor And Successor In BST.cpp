#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

void inOrder(BinaryTreeNode<int>* root, vector<int> &arr){
    
    if(root->left){
        inOrder(root->left, arr);
    }

    arr.push_back(root->data);

    
    if(root->right){
        inOrder(root->right, arr);
    }
       
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.142
    vector<int> in;

    inOrder(root, in);

    int n = in.size();

    for(int i=0; i<n; i++){

        if(i==0){
            if(in[i]==key){
                if(i+1<n){
                    return {-1, in[i+1]};
                }else return {-1, -1};
            }
        }else if(i==n-1){
            if(i-1<0){
              return { -1, -1 };
            }else{
                return {in[i-1], -1};
            }
        }
        
        if(in[i]==key){
            return {in[i-1], in[i+1]};
        }
    }
}
