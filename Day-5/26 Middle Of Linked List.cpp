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

Node *findMiddle(Node *head) {
    // Write your code herehead
    if(!head || head->next==NULL) return head;
    Node *temp = head->next;

    while(temp && temp->next){
        head = head->next;
        temp = temp->next->next;
    }

    if(temp){
        head = head->next;
    }

    return head;

}

