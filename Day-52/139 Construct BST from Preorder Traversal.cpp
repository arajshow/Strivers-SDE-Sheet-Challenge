#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* solve(vector<int> &pre, int st, int n)
{
    if(st>n) return NULL;
    TreeNode<int>* root = new TreeNode<int>(pre[st]);

    if(st==n) return root;
    
    int rt = pre[st];
    
    for(int i=st+1; i<=n; i++){
        if(pre[i]>rt){
            root->right = solve(pre, i, n);
            root->left = solve(pre, st+1, i-1);
            return root;
        }
    }
    
    root->left = solve(pre, st+1, n);
    return root;
}


TreeNode<int>* preOrderTree(vector<int> &pre){
    // Write your code here.139
    // root left right
    
    return solve(pre, 0, pre.size()-1);

    
    
}
