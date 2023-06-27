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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string ans = "r";
    if(!root) return ans;

    queue<TreeNode<int> *> q;
    q.push(root);
    TreeNode<int> *nl = NULL;

    while(!q.empty()){
        TreeNode<int> *rt = q.front();
        q.pop();

        if(rt==nl){
            ans+="0r";
            continue;
        }

        ans = ans + to_string(rt->data);
        ans+='r';

        if(rt->left){
            q.push(rt->left);
        }else{
            q.push(nl);
        }

        if(rt->right){
            q.push(rt->right);
        }else{
            q.push(nl);
        }
    }
    // cout<<ans<<endl;
    return ans;

}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
 
    if(serialized.size()==1) return NULL;

    int data=0, n = serialized.size();
    TreeNode<int>* root = NULL;
    queue<TreeNode<int>*> q;
    bool left = false;

    for(int i=1; i<n; i++){
        // cout<<i<<"iiii"<<endl;
        if(serialized[i]=='r'){
            // cout<<data<<endl;
            TreeNode<int>* temp = NULL;
            if(data>0)
                temp = new TreeNode<int>(data);
            
            if(root==NULL){
                root = temp;
                data = 0;
                q.push(root);
                continue;
            }

            TreeNode<int>* rt = q.front();
            if(!left){
                if(data!=0){
                    rt->left = temp;
                    q.push(temp);
                }

                left = true;
            }else{
                q.pop();
                if(data!=0){
                    rt->right = temp;
                    q.push(temp);
                }

                left = false;
            }
            data = 0;
            continue;
        }
        
        data*=10;
        data+= int(serialized[i] -48);
    }

    return root;



}



