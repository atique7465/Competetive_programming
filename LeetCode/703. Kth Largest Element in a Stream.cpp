class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int gk;
public:
    KthLargest(int k, vector<int>& nums) {
        gk = k;
        if(nums.size() > 0){
            sort(nums.begin(), nums.end());
            int i = nums.size() - k; if(i < 0) i = 0;
            for(; i < nums.size(); i++) pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > gk) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */