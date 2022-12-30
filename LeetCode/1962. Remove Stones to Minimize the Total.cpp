class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int res = accumulate(piles.begin(), piles.end(), 0);
        while(k--){
            int curr = pq.top(); pq.pop();
            res -= curr/2;
            curr = curr - curr/2;
            pq.push(curr);
        }
        return res;
    }
};