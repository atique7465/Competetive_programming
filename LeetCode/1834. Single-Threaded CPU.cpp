class Solution {
    typedef pair<int, int> pii;
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<int> res;
        
        for(int i = 0; i < tasks.size(); i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        int idx = 0; long long currTime = 0;
        while(idx < tasks.size() || !pq.empty()){
            if(pq.empty() && currTime < tasks[idx][0]) currTime = tasks[idx][0];
            
            while(idx < tasks.size() && tasks[idx][0] <= currTime){
               pq.push({tasks[idx][1], tasks[idx][2]});
               idx++;
            }
             
            auto [processTime, index] = pq.top(); pq.pop(); 
            res.push_back(index);
            currTime += processTime;
        }

        return res;
    }
};