class Solution_01 {
public:
    int findMin(vector<int>& nums) {
        int mid, lo = 0, hi = nums.size() - 1, n = nums.size();
        while(lo < hi){
           mid = (lo + hi) / 2;
           if(nums[mid] < nums[(mid-1+n)%n] && nums[mid] < nums[(mid+1)%n]) return nums[mid];
           if(nums[0] <= nums[mid] && nums[nums.size()-1] < nums[mid]) lo = mid + 1;
           else hi = mid - 1;
        }
        return nums[lo];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int mid, lo = 0, hi = nums.size() - 1;
        
        while(lo < hi){
           if(nums[lo] < nums[hi]) return nums[lo];
        
           mid = (lo + hi) / 2;
           if(nums[mid] >= nums[lo]) lo = mid + 1;
           else hi = mid;
        }
        
        return nums[lo];
    }
};