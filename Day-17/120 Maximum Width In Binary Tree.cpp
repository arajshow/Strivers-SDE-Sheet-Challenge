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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int ans = 0;

    if(!root) return ans;
    queue<TreeNode<int> *> q;
    q.push(root);

    while(!q.empty()){

        int n = q.size();
        int count = 0;
        while(n--){
            TreeNode<int> *node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
            count++;
        }
        ans = max(ans, count);
    }

    return ans;

}
