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

int lengthNode(Node *n){
    int ans = 0;
    while(n){
        n = n->next;
        ans++;
    }
    return ans;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int l1 = lengthNode(firstHead);
    int l2 = lengthNode(secondHead);

    int d;
    Node *p1;
    Node *p2;

    if(l1>l2){
        p1 = firstHead;
        d = l1 -l2;
        p2 = secondHead;
    }else{
        p1 = secondHead;
        p2 = firstHead;
        d = l2 - l1;
    }

    while(d--){
        p1 = p1->next;
    }

    while(p1 && p2){
        if(p1==p2) return p1;

        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;

    
}
