class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hi = prices.size()-1, currMx = 0, res = 0;
        while(hi >= 0){
            currMx = max(currMx, prices[hi]);
            res = max(res, currMx - prices[hi]);
            hi--;
        }
        return res;
    }
};