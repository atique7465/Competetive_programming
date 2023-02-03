class Solution {
public:
    string convert(string s, int numRows) {
       vector<vector<char>> grid(numRows, vector<char>(s.size(), '_'));
       int i = 0, row = 0, col = 0;
       while(i < s.size()){
           if(row == 0){
               int cnt = 0;
               while(i < s.size() && cnt < numRows){
                  grid[row++][col] = s[i++]; cnt++;
               }
               row-=1;
               if(row != 0) row--;
               col++;
           }else 
              grid[row--][col++] = s[i++];
       }

       string res = "";
       for(int i = 0; i < numRows; i++){
           for(int j = 0; j < col; j++){
               if(grid[i][j] != '_') res+=grid[i][j];
           }
       }

       return res;
    }
};