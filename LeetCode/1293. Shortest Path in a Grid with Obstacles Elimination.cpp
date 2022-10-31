class Sqr{
    public:
    int x,y,k,d;
    Sqr(int x, int y, int d, int k){this->x = x;this->y = y;this->d = d;this->k = k;}
};

class Solution {
    int visited[41][41], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1}, inf = 1e9,r,c;;
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        r = grid.size(); c = grid[0].size();
        if(r == 1 && c == 1) return 0;
        memset(visited, -1, sizeof(visited));
        int res = BFS(k, grid);
        return res == inf ? -1 : res;
    }
    
    int BFS(int k, vector<vector<int>>& grid){
        int res = inf;
        queue<Sqr*>q;
        q.push(new Sqr(0,0,0,k));
        visited[0][0]=k;
        while(!q.empty()){
            Sqr *sqr = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int tx = sqr->x + dx[i], ty = sqr->y + dy[i];
                if((tx>=0 && tx<r) && (ty>=0 && ty<c)){
                    int d = sqr->d, k = sqr->k;
                    if(tx == r-1 && ty == c-1) res = min( res, d+1);
                    else if(visited[tx][ty] != -1 && visited[tx][ty] >= k) continue; //if any path already visited with more k no need to override
                    else if(grid[tx][ty]){
                        if(k) {
                            q.push(new Sqr(tx, ty, d+1, k-1));
                            visited[tx][ty]=k;
                        }
                    }else{
                        q.push(new Sqr(tx, ty, d+1, k));
                        visited[tx][ty]=k;
                    }
                }
            }
        }
        return res;
    }
}; 