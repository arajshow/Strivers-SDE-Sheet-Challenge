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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here

    if(!head || head->next==NULL) return head;
    LinkedListNode<int> *root = head;
    LinkedListNode<int> *nxt = head->next;

    root->next = NULL;
    while(nxt){
        LinkedListNode<int> *temp = nxt;
        nxt = nxt->next;
        temp->next = root;
        root = temp;
    }

    return root;

}
