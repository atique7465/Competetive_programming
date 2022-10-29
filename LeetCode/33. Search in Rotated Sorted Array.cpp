class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), left = 0, right = len - 1;
        while(right - left > 1){
            int mid = (left+right) / 2;
            if(nums[mid] < nums[left]){
                right = mid;
            }else{
                left = mid;
            }
        }
        
        int start, end;
        if(target >= nums[0] && target <= nums[left]){
            start = 0; end = left;
        }else{
            start = right; end = len - 1;
        }
        
        while(start <= end){
            int mid = (start+end)/2;
            if(target == nums[mid]) return mid;
            if(target > nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        
        return -1;
    }
};