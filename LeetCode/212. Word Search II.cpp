class Trie{
public:
    string fullWord;
    bool isFullWord = false;
    Trie* next[26] = {};
    void add(string &word){
        Trie *curr = this;
        for(char c:word){
            if(curr->next[c-'a'] == NULL) curr->next[c-'a'] = new Trie();
            curr = curr->next[c-'a'];
        }
        curr->isFullWord = true; curr->fullWord = word;
    }
};

class Solution {
    int r,c;
    vector<string> result;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        r = board.size(), c = board[0].size(); 
        Trie* trie = new Trie();
        
        for(string word:words) trie->add(word);
                
        for(int p = 0; p < r; p++)
            for(int q = 0; q < c; q++)
                findWord(p, q, trie, board);
        
        return result;
    }
    
    void findWord(int p, int q, Trie *curr, vector<vector<char>>& board){
        
        if(p < 0 || q < 0 || p >= r || q >= c || board[p][q] == '*' || curr->next[board[p][q]-'a'] == NULL) return;
        
        curr = curr->next[board[p][q]-'a'];
        if(curr->isFullWord){
            result.push_back(curr->fullWord);
            curr->isFullWord = false; // ignore duplicate, as single word need to be identified once
        }
        
        char ch = board[p][q];
        board[p][q] = '*'; //visited
        
        findWord(p-1, q, curr, board); //up
        findWord(p, q+1, curr, board); //right
        findWord(p, q-1, curr, board); //left
        findWord(p+1, q, curr, board); //down
                
        board[p][q] = ch;
    }
};

/*
[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]
["oath","pea","eat","rain","i","jj","krvl","krvi"]
*/