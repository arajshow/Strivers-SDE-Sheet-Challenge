#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode< int > *> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();

        while(n--){
            BinaryTreeNode< int > *node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }

            if(n>0){
                node->next = q.front();
            }
        }
    }
}
