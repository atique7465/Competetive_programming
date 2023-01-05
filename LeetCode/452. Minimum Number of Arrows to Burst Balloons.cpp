class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>&v1, vector<int>&v2){return v1[1]<v2[1];});
        int arrowCnt = 1, arrowPos = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0]<=arrowPos) continue;
            else {
              arrowCnt++;
              arrowPos = points[i][1];
            }
        }
        return arrowCnt;
    }
};