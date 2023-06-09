/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    // Write your code here.
    int n = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        n++;
    }

    temp = head;
    int tar = n - k-1;

    // case when 1st element will be removed
    if(tar==-1){
        return head->next;
    }
    while(tar--){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;

}
