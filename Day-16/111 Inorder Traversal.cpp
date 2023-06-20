#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void solve(TreeNode *root, vector<int> &ans){
        if(root->left){
            solve(root->left, ans);
        }

        ans.push_back(root->data);

        if(root->right){
            solve(root->right, ans);
        }
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // left root right
    vector<int> ans;

    if(!root) return {};

    solve(root, ans);

    return ans;
}
