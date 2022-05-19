const int sz = 26;

class Node
{
public:
    Node* links[sz];
    bool flag = false;

    // Check if the reference trie is present or not
    bool containKey(char& ch){
        return this->links[ch-'a'] != NULL;
    }

    // Creating reference trie
    Node* getKey(char& ch){
        return links[ch-'a'];
    }

    // Set the end of the string 
    void setEnd(){
        flag = true;
    }

    // Check if we are at the end of string
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string str) {
        Node* curr = root;
        for(auto x : str){
            if(!curr->containKey(x)){
                curr->links[x-'a'] = new Node();
            }
            curr = curr->getKey(x);
        }
        curr->setEnd();
    }
    
    bool search(string str) {
        Node* curr = root;
        for(auto x : str){
            if(!curr->containKey(x))
                return false;
            curr = curr->getKey(x);
        }
        return curr->isEnd();
    }
    
    bool startsWith(string str) {
        Node* curr = root;
        for(auto x : str){
            if(!curr->containKey(x))
                return false;
            curr = curr->getKey(x);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */