class Solution {
    int r, c, inf = 9999;
    vector<int>res;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        solve(0, 0, 'r', matrix);
        return res;
    }
    
    void solve(int i, int j, char ch, vector<vector<int>>& matrix){
        
        if(matrix[i][j] != inf) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = inf;
        }
        
        if(ch == 'r'){
            if(j+1 < c && matrix[i][j+1] != inf)
                solve(i, j+1, 'r', matrix);
            else if(i+1 < r && matrix[i+1][j] != inf)
                solve(i+1, j, 'd', matrix);
            
        }else if(ch == 'd'){
            if(i+1 < r && matrix[i+1][j] != inf)
                solve(i+1, j, 'd', matrix);
            else if(j-1 >= 0 && matrix[i][j-1] != inf)
                solve(i, j-1, 'l', matrix);
            
        }else if(ch == 'l'){
            if(j-1 >= 0 && matrix[i][j-1] != inf)
                solve(i, j-1, 'l', matrix);
            else if(i-1 >= 0 && matrix[i-1][j] != inf)
                solve(i-1, j, 'u', matrix);
            
        }else if(ch == 'u'){
            if(i-1 >= 0 && matrix[i-1][j] != inf)
                solve(i-1, j, 'u', matrix);
            else if(j+1 < c && matrix[i][j+1] != inf)
                solve(i, j+1, 'r', matrix);
        }
    }
    
};