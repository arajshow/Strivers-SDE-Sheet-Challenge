#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    // root, hlevel, vlevel
    // if vlevle same then high hlevel win

    queue<pair<BinaryTreeNode<int> *, int>> q;  //root, hlevel, vlevel
    if(!root) return {};
    map<int, int> mp;
    vector<int> ans;

    q.push({root, 0});

    while(!q.empty()){
        BinaryTreeNode<int> *node = q.front().first;
        int vlevel = q.front().second;
        q.pop();

        mp[vlevel] = node->data;

        if(node->left){
            q.push({node->left, vlevel-1});
        }

        if(node->right){
            q.push({node->right, vlevel+1});
        }

    }
    

    for(auto it : mp){
        ans.push_back(it.second);
    }

    return ans;
}
