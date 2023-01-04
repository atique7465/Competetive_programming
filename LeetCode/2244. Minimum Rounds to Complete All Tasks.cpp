class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < tasks.size(); i++) mp[tasks[i]]++;
        int res = 0, left;
        for(auto const&[k,v]:mp){
            if(v==1) return -1;
            else{
                left = v - ((v/3)*3);
                if(left == 0 || left == 2) res += (v/3) + left/2;
                else res += (v/3) - 1 + 2;
            }
        }
        return res;
    }
};