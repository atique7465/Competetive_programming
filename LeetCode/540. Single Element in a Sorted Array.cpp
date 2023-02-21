class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int mid, lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            mid = (lo + hi) / 2;
            if((mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 == 1 && nums[mid] == nums[mid-1])) 
                lo = mid + 1;
            else
                hi = mid;
        }
        return nums[lo];
    }
};