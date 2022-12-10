class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        map<int, vector<int>>mp;
        
        for(int i = 0; i < vals.size(); i++)
            mp[i] = {};
        
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i][0]].push_back(vals[edges[i][1]]);
            mp[edges[i][1]].push_back(vals[edges[i][0]]);
        }
        
        int res = INT_MIN;
        map<int, vector<int>>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); itr++){
            sort(itr->second.begin(), itr->second.end());
            int locRes = vals[itr->first], cnt = 0;
            res = max(res, locRes);
            for(int i = itr->second.size()-1; i >=0 && cnt < k; i--){
                locRes+=itr->second[i];
                res = max(res, locRes);
                cnt++;
            }
        }
        
        return res;
    }
};