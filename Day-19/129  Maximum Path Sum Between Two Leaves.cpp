#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int solve(long long int &ans, TreeNode<int> *root){
    long long int lft = -1, rit = -1;

    if(root->left){
        lft = solve(ans, root->left);
    }

    if(root->right){
        rit = solve(ans, root->right);
    }

    if(lft==-1 && rit==-1) return root->val;
    else if(lft==-1 || rit==-1){
        return max(lft, rit) + root->val;
    }

    long long int cur = lft + rit + root->val;
    if(cur>ans){
        ans = cur;
    }

    return max(lft, rit) + root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.

    long long ans  = -1;

    if(!root) return -1;

    solve(ans, root);

    return ans;
}
