#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // pre => root, left right
    TreeNode<int> *node = root;
    if(!root) return root;
    TreeNode<int> *temp = root->right;
    root->right = flattenBinaryTree(root->left);
    while(root->right){
        root = root->right;
    }

    root->right = flattenBinaryTree(temp);

    return node;

}
