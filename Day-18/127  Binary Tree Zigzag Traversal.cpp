#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(!root) return ans;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool value = false;

    while(!q.empty()){
        int n = q.size();

        value = (value)? false : true;
        vector<int> v;
        
        while(n--){
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            v.push_back(node->data);

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }

        if(value){
            ans.insert(ans.end(), v.begin(), v.end());
        }else{
            ans.insert(ans.end(), v.rbegin(), v.rend());
        }
    }

    return ans;

    
}
