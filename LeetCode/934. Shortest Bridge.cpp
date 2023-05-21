class Solution {
    queue<vector<int>> q;
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int fx, fy;
        for(int i = 0; i < grid.size(); i++){
           for(int j = 0; j < grid.size(); j++){
            if(grid[i][j] == 1) {
                 fx = i; fy = j; break;
              }
           }
        }
             
        dfs(fx, fy, grid);

        vector<vector<int>> path = {{0,1},{1,0},{0,-1},{-1,0}}; int nx, ny;
        while(!q.empty()){
            vector<int> root = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                nx = root[0]+path[i][0]; ny = root[1]+path[i][1];
                if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid.size() || grid[nx][ny] == 2) continue;
                if(grid[nx][ny] == 0) {
                   q.push({nx,ny,root[2]+1});
                   grid[nx][ny] = 2;
                }
                else if(grid[nx][ny] == 1) return root[2]; 
            }
        }

        return 0;
    }

    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] == 0 || grid[i][j] == 2) return;
        q.push({i,j,0}); grid[i][j] = 2;
        dfs(i,j+1,grid); dfs(i+1,j,grid); dfs(i,j-1,grid); dfs(i-1,j,grid);
    }
};