/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class Node{

    public:
    Node *child[26];
    bool flag;

    Node(){
        this->flag = false;
    }

    Node *put(char c, Node *node){
        child[c- 'a'] = node;
        return node;
    }

    void setEnd(){
        this->flag = true;
    }

    bool getEnd(){
        return this->flag;
    }

};

class Trie {

public:

    /** Initialize your data structure here. */
    Node *root;
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */


    void insert(string word) {
        // cout<<1<<endl;
        int n = word.size();
        Node *node = root;
        
        for(int i=0; i<n; i++){
            if(node->child[word[i]-'a']){
                node = node->child[word[i] - 'a'];
            }else{
                node = node->put(word[i], new Node());
            }
        }

        node->setEnd();
    }

    /** Returns if the word is in the trie. */

    bool search(string word) {
        // cout<<2<<endl;
        int n = word.size();
        Node *node = root;
        
        for(int i=0; i<n; i++){
            if(node->child[word[i]-'a']){
                node = node->child[word[i] - 'a'];
            }else{
                return false;
            }
        }

        return node->getEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        // cout<<3<<endl;
        int n = word.size();
        Node *node = root;
        
        for(int i=0; i<n; i++){
            if(node->child[word[i]-'a']){
                node = node->child[word[i] - 'a'];
            }else{
                return false;
            }
        }

        return true;
    }
};
