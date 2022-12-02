class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        vector<int> range(10010, -1);
        
        for(int i = 0; i < intervals.size(); i++)
            range[intervals[i][0]] = max(range[intervals[i][0]], intervals[i][1]);
        
        int i = 0;
        while(i < 10001){
            if(range[i] != -1){
                int l = i, mx = range[i], j = i;
                while(j+1 <= mx) mx = max(mx, range[++j]);
                res.push_back({l, j});
                i = j + 1;
            }else{
                i++;
            }
        }
        
        return res;
    }
};