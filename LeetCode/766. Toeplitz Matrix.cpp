class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i = 0; i < r; i++){
            for(int j=0; j<c; j++){
                int di = i - 1;
                int dj = j - 1;
                if(di>=0 && dj>=0 && matrix[i][j]!=matrix[di][dj])
                    return false;
            }
        }
        return true;
    }
};