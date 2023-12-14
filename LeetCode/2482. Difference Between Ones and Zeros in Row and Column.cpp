class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        map<int, vector<int>>mprow;
        map<int, vector<int>>mpcol;

        for(int i = 0; i < r; i++){
            int ones = 0, zeros = 0;
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1) ones++;
                else zeros++;
            }
            mprow[i] = {ones, zeros};
        }

         for(int j = 0; j < c; j++){
            int ones = 0, zeros = 0;
            for(int i = 0; i < r; i++){
                if(grid[i][j] == 1) ones++;
                else zeros++;
            }
            mpcol[j] = {ones, zeros};
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                grid[i][j] = mprow[i][0] + mpcol[j][0] - mprow[i][1] - mpcol[j][1];
            }
        }

        return grid;
    }
};