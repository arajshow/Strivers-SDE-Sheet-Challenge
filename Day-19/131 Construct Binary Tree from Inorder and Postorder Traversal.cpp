/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

 TreeNode<int>* solve(vector<int>& post, int st1, int en1, vector<int>& ino, int st2, int en2){

      if(st1>en1 || st2>en2) return NULL;
     int rt = post[en1];
     TreeNode<int> *root = new TreeNode<int>(rt);

      for(int i=st2; i<=en2; i++){
           if(ino[i]==rt){
                rt = i;
                break;
           }
      }

      root->left = solve(post, st1, st1 + (rt - st2)-1, ino, st2, rt-1);
      root->right = solve(post, st1 + (rt - st2), en1-1, ino, rt+1, en2);

     
 } 

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// post => left right root
     // ino => left root right

     int n = postOrder.size();

     return solve(postOrder, 0, n-1, inOrder, 0, n-1);
}
