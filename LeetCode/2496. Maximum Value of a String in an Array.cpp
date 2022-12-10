class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxRes = 0;
        for(int i = 0; i < strs.size(); i++){
            bool isNumeric = true;
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] < '0' || strs[i][j] > '9'){
                    isNumeric = false;
                    break;
                }
            }
            if(isNumeric){
                int val = 0, base = 1;
                for(int k = strs[i].size() - 1; k >=0; k--){
                    val = val + (base * (strs[i][k] - '0'));
                    base *= 10;
                }
                if(val > maxRes) maxRes = val;
            }else{
                if(strs[i].size() > maxRes) maxRes = strs[i].size();
            }
        }
        return maxRes;
    }
};