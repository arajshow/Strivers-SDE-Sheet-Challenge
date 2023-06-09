/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/


Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.

    Node* res = NULL;
    Node* root = NULL;
    int rem  = 0;

    while(num1 && num2){
        int sm = num1->data + num2->data;
        sm+=rem;
        
        if(sm<10){
            rem = 0;
        }else{
            sm = sm%10;
            rem = 1;
        }

        Node *temp = new Node(sm);
        if(!res){
            res = temp;
            root = temp;
        }else{
            res->next = temp;
            res = temp;
        }
        num1 = num1->next;
        num2 = num2->next;
    }

    while(num1){
        int sm = num1->data + rem;

        
        if(sm<10){
            rem = 0;
        }else{
            sm = sm%10;
            rem = 1;
        }

        Node *temp = new Node(sm);
        res->next = temp;
        res = temp;

        num1 = num1->next; 
    }

    while(num2){
        int sm = num2->data + rem;

        
        if(sm<10){
            rem = 0;
        }else{
            sm = sm%10;
            rem = 1;
        }

        Node *temp = new Node(sm);
        res->next = temp;
        res = temp;

        num2 = num2->next; 
    }

    if(rem!=0){
        res->next = new Node(rem);
    }


    return root;
}
