class Solution {
    vector<bool> visited;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size(), false);
        dfs(0, rooms);
        for(int i = 0; i < visited.size(); i++)
           if(!visited[i]) return false;
        return true;
    }

    void dfs(int i, vector<vector<int>>& rooms){
        if(visited[i]) return;
        visited[i] = true;
        for(int j = 0; j < rooms[i].size(); j++){
            dfs(rooms[i][j], rooms);
        }
    }
};