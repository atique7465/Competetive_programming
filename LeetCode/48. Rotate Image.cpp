class Solution {
    //step 01: Transpose
    //step 02: reverse every row
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        int s, e;
        for(int i = 0; i < matrix.size(); i++){
            s = 0, e = matrix[0].size() - 1;
            while(s < e){
                swap(matrix[i][s], matrix[i][e]);
                s++; e--;
            }
        }
    }
};