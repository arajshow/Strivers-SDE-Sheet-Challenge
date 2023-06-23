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

TreeNode<int> *build(vector<int> ino, int st1, int en1, vector<int> pre, int st2, int en2){

    if(st1>en1 || st2>en2) return NULL;

    int rt = pre[st2];

    TreeNode<int> *root = new TreeNode<int>(pre[st2]);

    for(int i=st1; i<=en1; i++){
        if(ino[i]==rt){
            rt = i;
            break;
        }
    }

    root->left = build(ino, st1, rt-1, pre, st2+1, (rt-st1+st2));
    root->right = build(ino, rt+1, en1, pre, (rt-st1+st2+ 1), en2);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    in => left root right
    // pre => root left right
    int n = preorder.size();
    if(n==0) return NULL;

    return build(inorder, 0, n-1, preorder, 0, n-1);
}
