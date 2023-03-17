class Node{
    public: 
        char ch;
        Node* next[26]={};
        bool complete = false;
        Node(char _ch){
        this->ch = _ch;
        }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node('_');
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            int pos = word[i] - 'a';
            if(curr->next[pos] == NULL){
                curr->next[pos] = new Node(word[i]);
                curr = curr->next[pos];
            }else
                curr = curr->next[pos];
        }
        curr->complete = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            int pos = word[i] - 'a';
            if(curr->next[pos] == NULL){
                return false;
            }else
                curr = curr->next[pos];
        }
        return curr->complete;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i = 0; i < prefix.size(); i++){
            int pos = prefix[i] - 'a';
            if(curr->next[pos] == NULL){
                return false;
            }else
                curr = curr->next[pos];
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