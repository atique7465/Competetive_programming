class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        vector<int> res_col;
        
        for(int c = 0; c < col; c++){
            int res = 1, i = 0, j = c;
            
            while(i < row){
                if(grid[i][j] == 1) 
                    if(j+1 < col && grid[i][j+1] == 1) {i++; j++;} else {res = -1; break;}
                else
                    if(j-1 >= 0 && grid[i][j-1] == -1) {i++; j--;} else {res = -1; break;}
            }
            
            res_col.push_back(res == -1 ? res : j);
        }
        
        return res_col;
    }
};