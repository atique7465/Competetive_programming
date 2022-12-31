class Solution {
    int sx,sy,obsCount=0,row,col,pathLen,totPath=0;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size(); col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]==1){sx=i;sy=j;}
                else if(grid[i][j]==-1)obsCount++;
            }
        }
        pathLen = (row * col) - obsCount;
        dfs(sx,sy,0,grid);
        return totPath;
    }

    void dfs(int i, int j, int len, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j]==-1 || grid[i][j] == 3) return;
        if(grid[i][j]==2){        
            if(len+1 == pathLen) totPath++;
            return;
        }
        grid[i][j] = 3;
        dfs(i-1, j, len+1, grid);
        dfs(i, j+1, len+1, grid);
        dfs(i+1, j, len+1, grid);
        dfs(i, j-1, len+1, grid);
        grid[i][j] = 0;
    }
};