#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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


vector <int> findLeaf(TreeNode<int> *root, vector <int> &l, unordered_map<TreeNode<int> *, bool> &map){
    if(root->left==NULL && root->right==NULL){
        if(map.count(root)<1)
        l.push_back(root->data);
        map[root] = true;
        return l;
    }
    
    if(root->left!=NULL)
    l = findLeaf(root->left, l, map);
    if(root->right!=NULL)
    l = findLeaf(root->right, l, map);
    
    return l;
}


vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.

        unordered_map<TreeNode<int> *, bool> visited;
        vector<int> leftNode;
        vector<int> leafNode;
        stack<int> rightNode;
        // bool left = true;
        vector<int> ans;
        if(root==NULL) return ans;
        
        TreeNode<int> *temp = root;
        while(temp!=NULL){
            if(visited.count(temp)<1)
            leftNode.push_back(temp->data);
            visited[temp] = true;
            if(temp->left!=NULL)
            temp = temp->left;
            else{
                if(temp!=root)
                temp = temp->right;
                else break;
            }
            if(temp==NULL) break;
            if(temp->left==NULL && temp->right==NULL) break;

        }
        
        leafNode = findLeaf(root, leafNode, visited);
        
        temp = root->right;
        
        while(temp!=NULL){
            if(visited.count(temp)<1)
            rightNode.push(temp->data);
            if(temp->right!=NULL)
            temp = temp->right;
            else{
                temp= temp->left;
            }
            if(temp==NULL) break;
            if(temp->right==NULL && temp->left==NULL) break;
            
        }
        
        // int size = leftNode.size() + leafNode.size() + rightNode.size();
        
        for(int i=0; i<leftNode.size(); i++){
            ans.push_back(leftNode[i]);
        }
        
        
        for(int i=0; i<leafNode.size(); i++){
            ans.push_back(leafNode[i]);
        }
        
        while(rightNode.size()>0){
            ans.push_back(rightNode.top());
            rightNode.pop();
        }
        
        return ans;
}
