/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool mirror(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){

    if(!root1 && !root2) return true;
    else if(!root1 || !root2) return false;

    if(root1->data!=root2->data) return false;

    if(mirror(root1->left, root2->right) && mirror(root1->right, root2->left)) return true;
    return false;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(!root) return true;

    return mirror(root->left, root->right); 
}
