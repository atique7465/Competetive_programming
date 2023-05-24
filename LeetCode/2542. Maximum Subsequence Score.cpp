class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int, int>> items;
        for(int i = 0; i < nums1.size(); i++) items.push_back({nums2[i], nums1[i]});
        sort(items.begin(), items.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for(int i = items.size() - k; i < items.size(); i++){
            pq.push(items[i].second);
            sum += items[i].second;
        }

        long long res = sum * items[items.size() - k].first;
        int i = items.size() - k - 1;
        while(i >= 0){
            sum -= pq.top(); pq.pop();
            sum += items[i].second; pq.push(items[i].second);
            res = max(res, sum * items[i].first);
            i--;
        }

        return res;
    }
};