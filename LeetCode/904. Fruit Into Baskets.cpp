class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, type = 0, res = 0;
        while(j < fruits.size()){
            if(mp.find(fruits[j]) == mp.end() || mp[fruits[j]] == 0) type++;
            mp[fruits[j]]++;
            if(type < 3) res = max(res, j - i + 1);
            else{
                while(i < j){
                   mp[fruits[i++]]--;
                   if(mp[fruits[i-1]] == 0) {
                       type--; break;
                   }
                }
            }
            j++;
        }

        return res;
    }
};