#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/

void solve(vector<BinaryTreeNode<int>*> &arr, BinaryTreeNode<int>* root){
    
    if(root->left){
        solve(arr, root->left);
    }

    arr.push_back(root);

    if(root->right){
        solve(arr, root->right);
    }
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<BinaryTreeNode<int>* > arr;

    solve(arr, root);
    arr.push_back(NULL);

    for(int i=0; i<arr.size()-1; i++){
        if(i==0){
            arr[i]->left = NULL;
            arr[i]->right = arr[i+1];
            continue;
        }

        arr[i]->left = arr[i-1];
        arr[i]->right = arr[i+1];
    }

    return arr[0];
    
}
