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
        while(i >= 0 && nums[i] <= price) i = mp[nums[i]] - 1;
        mp[price] = i + 1;
        return nums.size() - 1 - i;
    }
};


class StockSpanner_Stack {
public:
    stack<pair<int,int>> stack;
    int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
        
        stack.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner obj ect will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */