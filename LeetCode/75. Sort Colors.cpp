class Solution_03 {
// DNF sort
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size() - 1;
        while(mid <= hi){
            if(nums[mid] == 0){
                swap(nums[lo], nums[mid]);
                lo++; mid++;
            }else if(nums[mid] == 1) 
                mid++;
            else{
                swap(nums[mid], nums[hi]);
                hi--;
            }
        }
    }
};

class Solution_02 {
// two pointer 2 pass
public:
    void sortColors(vector<int>& nums) {
        int i = 0; 
        for(int j = 0; j < nums.size(); j++){
            if(nums[j]==0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        for(int j = 0; j < nums.size(); j++){
            if(nums[j]==1){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

class Solution_01 {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] == 0) zero++;
            else if(nums[i] == 1) one++;
            else if(nums[i] == 2) two++;
        }
        
        int i = 0;
        for(; i < zero; i++) nums[i] = 0;
        for(; i < zero + one; i++) nums[i] = 1;
        for(; i < zero + one + two; i++) nums[i] = 2;
    }
};