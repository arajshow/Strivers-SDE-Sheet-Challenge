#include <bits/stdc++.h> 
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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    int lft= -1, rit = -1;

    if(root->data==x || root->data==y) return root->data;
    
    if(root->left){
        lft = lowestCommonAncestor(root->left, x, y);
    }
    
    if(root->right){
        rit = lowestCommonAncestor(root->right, x, y);
    }

    if(lft==-1 && rit==-1) return -1;
    else if((lft==x || lft==y) && (rit==x || rit==y)) return root->data;
    else if(lft==-1 || rit==-1) return max(lft, rit);

    




}
