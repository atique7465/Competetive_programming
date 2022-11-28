class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        map<int, int> mp;
        for (int i = 0; i < matches.size(); i++) {
            if (mp.find(matches[i][0]) == mp.end())
                mp[matches[i][0]] = 0;

            if (mp.find(matches[i][1]) == mp.end())
                mp[matches[i][1]] = 0;

            mp[matches[i][1]]++;
        }

        vector<int> zeroRes;
        vector<int> oneRes;
        for (auto const &[k, v]: mp) {
            if (v == 0)
                zeroRes.push_back(k);
            if (v == 1)
                oneRes.push_back(k);
        }

        return {zeroRes, oneRes};
    }
};