#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool solve(TreeNode<int> *root, int x, vector<int> &ans){

	if(root->data==x){
		ans.push_back(x);
		return true;
	}
	
	if(root->left){
		bool value = solve(root->left, x, ans);
		if(value){
			ans.insert(ans.begin(), root->data);
			return true;
		}
	}
	
	if(root->right){
		bool value = solve(root->right, x, ans);
		if(value){
			ans.insert(ans.begin(), root->data);
			return true;
		}
	}

	return false;
}


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	
	vector<int> ans;

	solve(root, x, ans);

	return ans;
}
