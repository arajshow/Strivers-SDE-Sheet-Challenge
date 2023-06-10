/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    // use flyod's method

    if(!head || head->next==NULL) return NULL;
    Node *root = head->next->next;
    Node *temp = head->next;

    while(root && root->next && root->data!=temp->data){
        root = root->next->next;
        temp = temp->next;
    }

    if(!root || root->next==NULL) return NULL;

    while(temp->data!=head->data){
        temp = temp->next;
        head = head->next;
    }

    return head;
}
