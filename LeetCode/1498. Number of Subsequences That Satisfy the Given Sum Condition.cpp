class Solution {
    int mod = 1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> twoPow = {1}; int pow = 1;
        for(int i = 1; i < nums.size(); i++){
           pow = (pow * 2) % mod;
           twoPow.push_back(pow);
        }

        int res = 0;
        int s = 0, e = nums.size() - 1;
        while(s <= e){
            while(s <= e && nums[s] + nums[e] > target) e--;
            if(s <= e) res = (res + twoPow[e-s]) % mod;
            s++;
        }

        return res;
    }
};