class Node{
public:
    char ch;
    bool isFull = false;
    Node* next[26] = {};
    Node(char _ch){
        this->ch = _ch;
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node('_');
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            int pos = word[i] - 'a';
            if(curr->next[pos] == NULL)
                curr->next[pos] = new Node(word[i]);
            curr = curr->next[pos];
        }
        curr->isFull = true;
    }
    
    bool search(string word) {
        return searchDfs(0, root, word);
    }

    bool searchDfs(int i, Node* root, string &word){
        bool ans = false;
        if(i == word.size()) ans = root->isFull;
        else if(word[i] != '.'){
            int pos = word[i] - 'a';
            if(root->next[pos] != NULL) ans |= searchDfs(i+1, root->next[pos], word);
        }else{
            for(int j = 0; j < 26; j++){
                if(root->next[j] != NULL)
                   ans |= searchDfs(i+1, root->next[j], word);
            }
        }
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */