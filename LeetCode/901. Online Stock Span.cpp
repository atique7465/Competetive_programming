class StockSpanner {
    vector<int> nums;
    unordered_map<int, int>mp;
public:
    StockSpanner() {}
    
    int next(int price) {
        nums.push_back(price);
        if(nums.size() == 1 || nums[nums.size() - 2] > price){
            mp[price] = nums.size() - 1;
            return 1; 
        } 
        
        int i = mp[nums[nums.size()-2]] - 1;
        while(i >= 0 && nums[i] <= price) i--;
        mp[price] = i + 1;
        return nums.size() - 1 - i;
    }
};

/**
 * Your StockSpanner obj ect will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */