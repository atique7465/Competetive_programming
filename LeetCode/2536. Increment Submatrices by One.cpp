class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat;
        mat.resize(n, vector<int>(n, 0));
        
        for(int i = 0; i < queries.size(); i++){
            int row1 = queries[i][0], col1 = queries[i][1], row2 = queries[i][2], col2 = queries[i][3];
            for(int j = row1; j <= row2; j++){
                mat[j][col1] += 1;
                if(col2 + 1 < n) mat[j][col2 + 1] += -1;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        
        return mat;
    }
};