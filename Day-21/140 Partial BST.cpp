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

int maxi(BinaryTreeNode<int> *root){

    if(!root) return INT_MIN;

    int ans = root->data;
    ans = max(maxi(root->left), max(maxi(root->right), ans));
    return ans;
}

int mini(BinaryTreeNode<int> *root){

    if(!root) return INT_MAX;

    int ans = root->data;
    ans = min(mini(root->left),min(ans, mini(root->right)));
    return ans;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here

    if(!root) return true;

    if(validateBST(root->left) && validateBST(root->right)){
        int lft = maxi(root->left);
        int rit = mini(root->right);

        if(lft<=root->data && root->data<=rit) return true;
        return false;
    }

    return false;
}
