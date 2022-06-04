class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, int> m;
        
        sort(nums.begin(), nums.end());
        
        int ln = nums.size();
        for(int i = 0; i<ln; i++){
            if(m.find(nums[i]) != m.end()){
                continue;
            }else{
                m[nums[i]] = 1;
                int j = i + 1, k = ln - 1;
                while(j<k && j < ln && k>=0){
                   if(j - 1 != i && nums[j] == nums[j-1]){
                       j++;
                       continue;
                    }
                    if(k + 1 != ln && nums[k] == nums[k+1]){
                       k--;
                       continue;
                    }
                
                   if(nums[i] + nums[j] + nums[k] == 0){
                      vector<int>v;
                      v.push_back(nums[i]);
                      v.push_back(nums[j]);
                      v.push_back(nums[k]);
                      result.push_back(v);
                      j++;
                      k--;
                    }else if(nums[i] + nums[j] + nums[k] > 0){
                      k--;
                    }else{
                      j++;
                   }
               }
            }
        }
        
        return result;
    }
};