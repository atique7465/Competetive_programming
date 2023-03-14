class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int lo = 1, hi = piles[piles.size()-1], mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int idx = upper_bound(piles.begin(), piles.end(), mid) - piles.begin();
            int leftHrs = piles[idx] == mid ? h - idx - 1 : h - idx;
            int i = piles[idx] == mid ? idx + 1 : idx;
            for(; i < piles.size(); i++)  leftHrs -= piles[i]%mid==0 ? (piles[i]/mid) : (piles[i]/mid)+1;
            if (leftHrs >= 0) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};