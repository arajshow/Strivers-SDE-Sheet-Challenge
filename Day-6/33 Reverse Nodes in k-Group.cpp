#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

pair<Node*, Node*> reverseNode(Node * &head, int n){


	if(head->next==NULL) return {head, head};

	Node *root = head->next;
	head->next = NULL;
	Node* end = head;
	n--;

	while(n-- && root){
		Node *temp = root;
		root = root->next;
		temp->next = head;
		head = temp;
	}

	Node *temp = root;
	root = head;
	head = temp;

	return {root, end};
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.

	if(!head) return head;

	Node *root = NULL;
	Node *temp= NULL;

	if(b[0]==0){
		root = NULL;
	}else if(b[0]==1){
		root= head;
		head = head->next;
		temp = root;
		temp->next = NULL;
	}else{
		pair<Node*, Node*> p = reverseNode(head, b[0]);
		root = p.first;
		temp = p.second;
	}

	for(int i=1; i<n; i++){

		if(!head) break;

		if(b[i]==0) continue;
		else if(b[i]==1){
			temp->next = head;
			temp = head;
			head = head->next;
			temp->next = NULL;
			continue;
		}
		pair<Node*, Node*> p = reverseNode(head, b[i]);
		if(!root){
			root = p.first;
			temp = p.second;
		}else{
			temp->next = p.first;
			temp = p.second;
		}

	}

	if(!root){
		return head;
	}

	if(head){
		temp->next = head;
	}

	return root;

	
}
