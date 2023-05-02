class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for(int num:nums){
            if(num == 0) {
               res = 0;
               break;
            }else if(num < 0){
                res *= -1;
            }
        }
        return res;
    }
};