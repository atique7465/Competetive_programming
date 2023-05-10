class Solution {
    int r, c, cnt = 1;
    vector<vector<int>> res;
public:
    vector<vector<int>> generateMatrix(int n) {
        r = n; c = n;
        res.resize(n, vector<int>(n, 0)); 
        solve(0, 0, 'r', res);
        return res;
    }
    
    void solve(int i, int j, char ch, vector<vector<int>>& matrix){
        
        if(matrix[i][j] == 0) matrix[i][j] = cnt++;
        
        if(ch == 'r'){
            if(j+1 < c && matrix[i][j+1] == 0)
                solve(i, j+1, 'r', matrix);
            else if(i+1 < r && matrix[i+1][j] == 0)
                solve(i+1, j, 'd', matrix);
            
        }else if(ch == 'd'){
            if(i+1 < r && matrix[i+1][j] == 0)
                solve(i+1, j, 'd', matrix);
            else if(j-1 >= 0 && matrix[i][j-1] == 0)
                solve(i, j-1, 'l', matrix);
            
        }else if(ch == 'l'){
            if(j-1 >= 0 && matrix[i][j-1] == 0)
                solve(i, j-1, 'l', matrix);
            else if(i-1 >= 0 && matrix[i-1][j] == 0)
                solve(i-1, j, 'u', matrix);
            
        }else if(ch == 'u'){
            if(i-1 >= 0 && matrix[i-1][j] == 0)
                solve(i-1, j, 'u', matrix);
            else if(j+1 < c && matrix[i][j+1] == 0)
                solve(i, j+1, 'r', matrix);
        }
    }
};