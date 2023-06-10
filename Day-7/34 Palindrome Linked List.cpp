#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseNode(LinkedListNode<int> * &head, int n, bool value){
    

    LinkedListNode<int> *root = head->next;
    head->next = NULL;

    if(!value) n--;

    while(n-- && root){
        LinkedListNode<int> *temp = root;
        root = root->next;
        temp->next = head;
        head = temp;
        
    }

     if(value){
        head = head->next;
    }   

    LinkedListNode<int> *temp = root;
    root = head;
    head = temp;

    return root;
}
// 1 2 3 3 2 1
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    int n = 0;
    if(!head || head->next==NULL) return true;
    
    LinkedListNode<int> *temp = head;

    while(temp){
        temp = temp->next;
        n++;
    }

    int ans = n/2;

    temp = reverseNode(head, ans, n%2!=0);

    while(temp && head){
        if(temp->data!=head->data) return false;
        temp = temp->next;
        head = head->next;
    }
    return true;

}
