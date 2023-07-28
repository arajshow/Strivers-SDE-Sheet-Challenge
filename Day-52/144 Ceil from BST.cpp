#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int solve(BinaryTreeNode<int> *node, int x){

    int ans = INT_MAX;

    if(x==node->data) return x;
    else if(x<node->data){
        ans= min(node->data, ans);
        if(node->left){
            ans = min(ans, solve(node->left, x));
        }
    }else{
        if(node->right){
            ans = min(ans, solve(node->right, x));
        }
    }

    
    return ans;    
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.144

    int ans = solve(node, x);

    if(ans==INT_MAX) return -1;
    return ans;

}
