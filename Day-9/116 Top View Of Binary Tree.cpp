#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.



    queue<pair<TreeNode<int> *, int>> q;  //root, hlevel, vlevel
    if(!root) return {};
    map<int, int> mp;
    vector<int> ans;

    q.push({root, 0});

    while(!q.empty()){
        TreeNode<int> *node = q.front().first;
        int vlevel = q.front().second;
        q.pop();

        if(mp.count(vlevel)<1)
            mp[vlevel] = node->val;

        if(node->left){
            q.push({node->left, vlevel-1});
        }

        if(node->right){
            q.push({node->right, vlevel+1});
        }

    }
    

    for(auto it : mp){
        ans.push_back(it.second);
    }

    return ans;

}
