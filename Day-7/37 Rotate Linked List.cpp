/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     Node *temp = head;
     int n = 0;
     while(temp){
          temp = temp->next;
          n++;
     }
     k%=n;
     if(k==0) return head;

     n-=k;
     n--;
     temp = head;

     while(n--){
          temp = temp->next;
     }
     Node *root = temp->next;
     temp->next = NULL;
     temp = root;

     while(root->next){
          root = root->next;
     }

     root->next = head;
     return temp;

}
