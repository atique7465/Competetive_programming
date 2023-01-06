class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i = 0, res = 0;
        while(coins > 0 && i < costs.size()){
            if(coins < costs[i]) break;
            coins -= costs[i++];
            res++;
        }
        return res;
    }
};