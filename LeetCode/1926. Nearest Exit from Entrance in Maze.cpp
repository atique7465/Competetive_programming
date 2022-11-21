class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size(), c = maze[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {1,0}, {0,1}, {0,-1}};
        
        queue<vector<int>>q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        
        while(!q.empty()){
            vector<int> root = q.front(); q.pop();
            for(auto d : dir){
                int dx = root[0] + d.first, dy = root[1] + d.second;
                if(dx >=0 && dx < r && dy >= 0 && dy < c && maze[dx][dy]=='.'){
                    if(dx == 0 || dx == r-1 || dy == 0 || dy == c-1){
                        return root[2]+1;
                    }
                    q.push({dx,dy,root[2]+1});
                    maze[dx][dy] = '+';
                }
            }
        }
        
        return -1;
    }
};