#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here
    if(!root) return NULL;
    int rt = root->data;
    int pda = p->data;
    int qda = q->data;

    if(pda==rt || qda==rt || (pda>rt && qda<rt) || (pda<rt && qda>rt) ) return root;

    if(pda<rt){
        return LCAinaBST(root->left, p, q);
    }else if(pda>rt){
        return LCAinaBST(root->right, p, q);
    }

    return NULL;
}
