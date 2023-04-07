class Solution {
    int r,c,res=0,cnt;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        r = grid.size(); c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j]==1){
                    cnt = 0;
                    if(dfs(i, j, grid)) res+=cnt;
                }
            }
        }
        return res;
    }

    bool dfs(int i, int j, vector<vector<int>>& grid){
        if(i <= 0 || i >= r-1 || j <= 0 || j >= c-1) return false;
        grid[i][j] = 0;
        cnt++;
        bool res = true;
        if(grid[i-1][j] == 1) res = res & dfs(i-1, j, grid);
        if(grid[i][j+1] == 1) res = res & dfs(i, j+1, grid);
        if(grid[i+1][j] == 1) res = res & dfs(i+1, j, grid);
        if(grid[i][j-1] == 1) res = res & dfs(i, j-1, grid);
        return res;
    }
};