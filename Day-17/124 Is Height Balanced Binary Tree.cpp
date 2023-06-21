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

int height(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, int> &ht){

    int lh = 0, rh = 0;

    if(root->left){
        if(ht.count(root->left)<1){
            ht[root->left] = height(root->left, ht);
            lh = ht[root->left];
        }else{
            lh = ht[root->left];
        }
            
    }

    if(root->right){
        if(ht.count(root->right)<1){
            ht[root->right] = height(root->right, ht);
            rh = ht[root->right];
        }else{
            rh = ht[root->right];
        }
            
    }

    ht[root] = 1 + max(lh, rh);
    return 1 + max(lh, rh);
    
}

bool isBT(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, int> &ht){

    int lh = 0, rh = 0;
    if(!root) return true;

    if(root->left){
        if(ht.count(root->left)<1){
            ht[root->left] = height(root->left, ht);
            lh = ht[root->left];
        }else{
            lh = ht[root->left];
        }
            
    }

    if(root->right){
        if(ht.count(root->right)<1){
            ht[root->right] = height(root->right, ht);
            rh = ht[root->right];
        }else{
            rh = ht[root->right];
        }
            
    }

    if(isBT(root->left, ht) && isBT(root->right, ht) && abs(lh -rh)<2) return true;
    return false;

}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(!root) return true;
    unordered_map<BinaryTreeNode<int>*, int> ht;


    return isBT(root, ht);

    
}
