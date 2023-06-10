/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
 Node *mergeSort(Node* head, Node* root){

	 if(!head) return root;
	 else if(!root) return head;

	 Node *res;
	 Node *ans;
	 if(head->data<root->data){
		 res = head;
		 ans = res;
		 head = head->child;
		 res->next = NULL;
	 }else{
		 res = root;
		 ans = res;
		 root = root->child;
		 res->next = NULL;
	 }

	 while(head && root){
		if(head->data<root->data){
			res->child = head;
			res = head;
			head = head->child;
			res->next = NULL;
		}else{
			res->child = root;
			res = root;
			root = root->child;
			res->next = NULL;
		}
	 }

	 while(head){
		 res->child = head;
		 res = head;
		 head = head->child;
		 res->next = NULL;
	 }

	 while(root){
			res->child = root;
			res = root;
			root = root->child;
			res->next = NULL;
	 }

	return ans;
 }

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(!head) return head;
	Node *root = head->next;
	while(root){
		Node *temp = root->next;
		root = mergeSort(head, root);
		head = root;
		root = temp;
	}

	return head;
}
