/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h> 


int height(TreeNode<int> *root){
    int lh =0, rh=0;

    if(root->left){
        lh = height(root->left);
    }

    if(root->right){
        rh = height(root->right);
    }

    if(lh==0 && rh==0) return 1;

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(!root) return 0;

    int lh = 0, rh = 0;

    if(root->left){
        lh = height(root->left);
    }

    if(root->right){
        rh = height(root->right);
    }

    return max(lh + rh, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));

}
