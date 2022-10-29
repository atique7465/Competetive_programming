class Solution_01_faster {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size() - 1, left = -1, right = -1;
        while(start <= end){
            int m = (start+end)/2;
            if(target == nums[m]) {left = right = m; break;}
            else if(target > nums[m]) start = m + 1;
            else end = m - 1;
        }
                
        start = 0; end = left - 1;
        while(start <= end){
            int m = (start+end)/2;
            if(target == nums[m]){
                left = m; end = m - 1;
            }else start = m + 1;
        }
        
        start = right + 1; end = nums.size()-1;
        while(start <= end){
            int m = (start+end)/2;
            if(target == nums[m]){
                right = m; start = m + 1;
            }else end = m - 1;
        }
        
        return {left, right};
    }
};

class Solution_02 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
                
        int start = 0, end = nums.size() - 1, left = -1, right = -1;
        while(start <= end){
            int m = (start+end)/2;
            if(target == nums[m]){
                left = m; end = m - 1;
            }else if(target > nums[m]) start = m + 1;
            else end = m - 1;
        }
        
        if(left != -1){
          start = left; end = nums.size()-1;
          while(start <= end){
              int m = (start+end)/2;
              if(target == nums[m]){
                  right = m; start = m + 1;
              }else if(target < nums[m]) end = m - 1;
              else start = m + 1;
          }
        }
        
        return {left, right};
    }
};