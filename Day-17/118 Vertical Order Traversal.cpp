#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/


vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;

    if(!root) return ans;

    map<int, vector<int>> mp;

    queue<pair<TreeNode<int> *, int>> q;  //node, index
    q.push({root, 0});

    while(!q.empty()){
        TreeNode<int> *node = q.front().first;
        int idx = q.front().second;
        q.pop();

        mp[idx].push_back(node->data);

        if(node->left){
            q.push({node->left, idx-1});
        }

        if(node->right){
            q.push({node->right, idx+1});
        }
    }


    // fot(auto it : mp){
    //     vector<int> v = it->second;
    //     for(int elm : v){
    //         ans.push_back(elm);
    //     }
    // }

    map<int, vector<int>> :: iterator it = mp.begin();

    while(it!=mp.end()){
        vector<int> v = it->second;
        for(int i=0; i<v.size(); i++){
            ans.push_back(v[i]);
        }
        it++;
    }


    return ans;
}
