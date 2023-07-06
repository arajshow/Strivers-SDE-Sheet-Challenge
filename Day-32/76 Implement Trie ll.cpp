#include <bits/stdc++.h> 
#define pn pair<Node*, int>

class Node{

    public:
    pn child[26];
    int flag;

    Node(){
        flag = 0;

        for(int i=0; i<26; i++){
            this->child[i] = {NULL, 0};
        }
    }

    Node *put(char c, Node *node){
        this->child[c -'a'] = {node, 1};
        return node;
    }

    void setEnd(){
        this->flag = this->flag + 1;
    }

    void reduceEnd(){
        this->flag = this->flag - 1;
    }

    int getEnd(){
        return this->flag;
    }
};


class Trie{

    public:
    Node *root;

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.

        int n = word.size();
        Node *temp = root;
        for(int i=0; i<n; i++){
            if(temp->child[word[i] -'a'].first!=NULL){
                temp->child[word[i] - 'a'].second++;
                temp = temp->child[word[i] - 'a'].first;

            }else{
                temp = temp->put(word[i], new Node());
            }
        }

        temp->setEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.

        int n = word.size();
        Node *temp = root;
        for(int i=0; i<n; i++){
            // cout<<word[i]<<"c"<<endl;
            if(temp->child[word[i] -'a'].first!=NULL){
                temp = temp->child[word[i] - 'a'].first;

            }else{
                return 0;
            }
        }

        return temp->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.

        int n = word.size(), ans= 0;
        Node *temp = root;
        for(int i=0; i<n; i++){
            if(temp->child[word[i] -'a'].first!=NULL){
                ans = temp->child[word[i] - 'a'].second;
                temp = temp->child[word[i] - 'a'].first;

            }else{
                return 0;
            }
        }

        return ans;
    }

    void erase(string &word){
        // Write your code here.

        int n = word.size(), ans;
        Node *temp = root;
        for(int i=0; i<n; i++){
            if(temp->child[word[i] -'a'].first!=NULL){
                ans = --temp->child[word[i] - 'a'].second;
                if(ans = 0){
                    temp->child[word[i] - 'a'].first = NULL;
                    return;
                }
                temp = temp->child[word[i] - 'a'].first;

            }else{
                return;
            }
        }

        temp->reduceEnd();

    }
};
