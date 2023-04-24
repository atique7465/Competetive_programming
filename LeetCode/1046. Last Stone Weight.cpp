class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; int x, y;
        for(int stone:stones) pq.push(stone);
        while(!pq.empty() && pq.size() >= 2){
            x = pq.top(); pq.pop(); y = pq.top(); pq.pop();
            if(x != y) pq.push(abs(x-y));
        }
        return pq.empty() ? 0 : pq.top();
    }
};