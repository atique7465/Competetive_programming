class Solution_02 {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return points.size();
        int res = 2;
        for(int i = 0; i < points.size(); i++){
            unordered_map<double, int> mp;
            for(int j = 0; j < points.size(); j++) 
                if(j!=i) mp[atan2(points[j][1]-points[i][1], points[j][0]-points[i][0])]++;
            for(auto [k,v]:mp) res = max(res, v+1);   
        }   
        return res;
    }
};


class Solution_01 {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2) return points.size();
        int lineCnt = 0, mxLineCnt = 0;
        for(int i = 0; i < points.size()-2; i++){
            for(int j = i+1; j < points.size()-1; j++){
                lineCnt = 2;
                for(int k=j+1; k < points.size(); k++){
                    if((points[j][1]-points[i][1])*(points[k][0]-points[i][0]) == (points[j][0]-points[i][0])*(points[k][1]-points[i][1]))
                      lineCnt++;
                }
                mxLineCnt = max(mxLineCnt, lineCnt);
            }
        }
        return mxLineCnt;
    }
};