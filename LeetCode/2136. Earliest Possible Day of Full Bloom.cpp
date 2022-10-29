class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> plants;
        int len = plantTime.size();
        for(int i = 0; i < len; i++) plants.push_back({growTime[i], plantTime[i]});
        
        sort(plants.begin(), plants.end(),
             [](const pair<int, int> &p1, const pair<int, int> &p2){return p1.first > p2.first;});
        
        int plant = plants[0].second - 1, bloom = plant + plants[0].first + 1;
        for(int i = 1; i < len; i++){
            plant += plants[i].second;
            bloom = max(bloom, plant + plants[i].first + 1);
        }
        
        return bloom;
    }
};