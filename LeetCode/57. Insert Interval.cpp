class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        
        int i = 0, j = 0, left, right; 
        while(i < intervals.size()){
            left = intervals[i][0];
            right = intervals[i][1];
            j = i;
            while(j + 1 < intervals.size() && right >= intervals[j+1][0]){
                right = max(right, intervals[j+1][1]);
                j++;
            }
            result.push_back({left, right});
            i = j+1;
        }
        return result;
    }
};