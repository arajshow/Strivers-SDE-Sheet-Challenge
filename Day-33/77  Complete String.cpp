#include <bits/stdc++.h> 

class Node{

    public:
    Node *links[26];
    bool flag = false;


    bool isConsist(char c){
        if(this->links[c - 'a']!=NULL) return true;
        return false;
    }

    Node *get(char c){
        return this->links[c - 'a'];
    }

    void put(char c, Node *node){
        this->links[c -'a'] = node;
    }

    void setEnd(){
        this->flag = true;
    }

    bool getEnd(){
        return this->flag;
    }


};


class Trie{

    public:
    Node *root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        int n =  word.size();

        Node *temp = root;
        for(int i=0; i<n; i++){

            if(!temp->isConsist(word[i])){
                temp->put(word[i], new Node());
            }  

            temp = temp->get(word[i]);

        }

        temp->setEnd();
    }

    bool checkCompleteString(string word){
        int n = word.size();

        Node *temp = root;

        for(int i=0; i<n; i++){

            if(temp->isConsist(word[i])){
                temp = temp->get(word[i]);

                if(temp->getEnd()==false){
                    return false;
                }

            }else{
                return false;
            }
        }

        return true;
    }
};

// string minS(string s1, string s2){
//     int n = s1.size();

//     for(int i=0; i<n; i++){
//         if(s1[i]<s2[i]) return s1;
//         else if(s2[i]<s1[i]) return s2;
//     }

//     return s1;
// }

string completeString(int n, vector<string> &a){
    // Write your code here.

    Trie *root = new Trie();
    string ans = "";

    for(int i=0; i<n; i++){
        
        root->insert(a[i]);
        // cout<<i<<endl;
    }

    

    for(int i=0; i<n; i++){
        string word = a[i];
        if(word.size()<ans.size()) continue;

        if(root->checkCompleteString(word)){
            if(word.size()>ans.size()) ans = word;
            else{
                ans = (word<ans)? word : ans;
            }
        }

    }

    if(ans.size()==0) return "None";
    return ans;
}
