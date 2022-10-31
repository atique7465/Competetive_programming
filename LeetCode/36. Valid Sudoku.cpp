class Solution {
public
    bool isValidSudoku(vectorvectorchar& board) {
        vectorvectorint r(9, vectorint(10, 0));
        vectorvectorint c(9, vectorint(10, 0));
        vectorvectorint box(9, vectorint(10, 0));
        
        for(int i = 0; i  9; i++){
            for(int j = 0; j  9; j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0', k = (3  (i3)) + (j3);  
                if(r[i][val]  c[j][val]  box[k][val]) return false;
                r[i][val] = c[j][val] = box[k][val] = 1;
            }
        }
        
        return true;
    }
};