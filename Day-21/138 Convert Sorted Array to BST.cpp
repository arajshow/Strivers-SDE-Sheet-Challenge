#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* solve(vector<int> &arr, int st, int en){

    if(st>en) return NULL;
    int md = st + (en-st)/2;

    TreeNode<int>* root = new TreeNode<int>(arr[md]);
    root->left = solve(arr, st, md-1);
    root->right = solve(arr, md+1, en);

    return root;
}


TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return solve(arr, 0, n-1);
}
