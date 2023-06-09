#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(!first) return second;
    else if(!second) return first;

    Node<int>* root;
    Node<int>* node;
    if(first->data<second->data){
        root = first;
        node = root;
        first = first->next;
    }else{
        root = second;
        node = root;
        second = second->next;
    }

    while(first && second){
        if(first->data<second->data){
            root->next = first;
            root = first;
            first = first->next;
        }else{
            root->next = second;
            root = second;
            second = second->next;
        }       
    }

    while(first){
        root->next = first;
        root = first;
        first = first->next;        
    }

    while(second){
        root->next = second;
        root = second;
        second = second->next;        
    }

    root->next = NULL;
    return node;
}
