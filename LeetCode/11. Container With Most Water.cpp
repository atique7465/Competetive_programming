class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int totNums = height.size();
        int i = 0, j = totNums - 1;
        
        int result = 0;
        while(i<j){
            int len = min (height[i], height[j]);
            
            int currRes = len * (j-i);
            
            if(currRes > result){
                result = currRes;
            }
            
            while(i < totNums && height[i] <= len){
                    i++;
            }
            
            while(j >=0 && height[j] <= len){
                    j--;
            }
        }
        
        return result;
    }
};