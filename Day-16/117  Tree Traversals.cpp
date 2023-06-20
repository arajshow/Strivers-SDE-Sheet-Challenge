#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

void inOrder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root->left){
        inOrder(root->left, ans);
    }

    ans.push_back(root->data);

    if(root->right){
        inOrder(root->right, ans);
    }
}

void preOrder(BinaryTreeNode<int> *root, vector<int> &ans){

    ans.push_back(root->data);


    if(root->left){
        preOrder(root->left, ans);
    }

    

    if(root->right){
        preOrder(root->right, ans);
    }
}

void postOrder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root->left){
        postOrder(root->left, ans);
    }

    

    if(root->right){
        postOrder(root->right, ans);
    }

    ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.

    if(!root) return {};

    vector<int> in;
    inOrder(root, in);


    vector<int> pre;
    preOrder(root, pre);


    vector<int> post;
    postOrder(root, post);



    return {in, pre, post};
}
