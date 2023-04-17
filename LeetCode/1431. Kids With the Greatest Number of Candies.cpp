class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for(int c:candies) mx = max(mx, c);

        vector<bool> result(candies.size(), false);
        for(int i = 0; i < candies.size(); i++)
            if(candies[i] + extraCandies >= mx) result[i] = true;
        
        return result;
    }
};