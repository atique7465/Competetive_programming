class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            int pos = getPos(spells[i], success, potions);
            spells[i] = potions.size() - pos;
        }
        return spells;
    }

    int getPos(long long a, long long success, vector<int>& potions){
        int lo = 0, hi = potions.size(), mid;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(potions[mid] * a >= success) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};