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

class BSTiterator
{
    public:
    int st, n;
    vector<int> ans;
    BSTiterator(TreeNode<int> *root)
    {
        if(root)
            updateArray(ans, root);
        st = 0;
        n = ans.size();
    }

    void updateArray(vector<int> &ans, TreeNode<int> *root){
        if(root->left){
            updateArray(ans, root->left);
        }

        ans.push_back(root->data);

        if(root->right){
            updateArray(ans, root->right);
        }
    }

    int next()
    {
        // write your code here
        if(st>=n)return -1;

        return ans[st++];
    }

    bool hasNext()
    {
        // write your code here
        if(st==n) return false;
        return true;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
