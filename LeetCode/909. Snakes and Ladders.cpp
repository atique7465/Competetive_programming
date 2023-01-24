class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pair<int, int>> levelCell(n*n + 1);
        vector<int> columns;
        for(int i = 0; i < n; i++) columns.push_back(i);
        int level = 1;
        for(int row = n-1; row >= 0; row--){
            for(int col:columns)
               levelCell[level++] = {row, col};
            reverse(columns.begin(), columns.end());
        } 
        
        vector<int> distance(n*n + 1, -1);
        distance[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int curr = q.front(); q.pop();
            for(int next = curr + 1; next <= min(curr + 6, n*n); next++){
                auto [row, col] = levelCell[next];
                int destination = board[row][col] != -1 ? board[row][col] : next;
                if(distance[destination] == -1){
                    distance[destination] = distance[curr] + 1;
                    q.push(destination);
                }
            }
        }

        return distance[n*n];
    }
};