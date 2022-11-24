class Solution {
    int r,c;
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        r = board.size(); c = board[0].size();  bool res = false; 
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == word[0]){
                    res = res | solve(i , j, 0, board, word); if(res) break;
                }
            }
            if(res) break;
        }
        
        return res;
    }
    
    bool solve(int i, int j, int pos, vector<vector<char>>& board, string word){
        
        if(i < 0 || j < 0 || i >=r || j >= c || board[i][j] == '*' || board[i][j] != word[pos]) return false;
        if(pos == word.size() - 1) return true;
        
        bool res = false;
        
        char c = board[i][j];
        board[i][j] = '*';
        res = res | solve(i-1, j, pos+1, board, word);
        res = res | solve(i+1, j, pos+1, board, word);
        res = res | solve(i, j+1, pos+1, board, word);
        res = res | solve(i, j-1, pos+1, board, word);
        board[i][j] = c;
        
        return res;
    }
};