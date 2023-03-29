class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int mxRes = 0;
        for(int i = 0; i < satisfaction.size(); i++){
            int locRes = 0;
            for(int j = i; j < satisfaction.size(); j++) locRes += satisfaction[j] * (j-i+1);
            mxRes = max(mxRes, locRes);
        }
        return mxRes;
    }
};