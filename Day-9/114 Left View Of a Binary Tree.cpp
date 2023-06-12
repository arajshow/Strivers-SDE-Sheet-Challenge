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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    we have to find node at each level for left view
    vector<int> ans;
    queue<TreeNode<int> *> q;
    if(!root) return ans;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        bool first = true;

        while(n--){
            TreeNode<int> *node = q.front();
            q.pop();

            if(first){
                first = false;
                ans.push_back(node->data);
            }

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }
    }

    return ans;
}
