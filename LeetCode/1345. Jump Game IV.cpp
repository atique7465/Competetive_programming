class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++) mp[arr[i]].push_back(i);
        vector<int>dis(arr.size(), -1); dis[0]=0;
        queue<int> q; q.push(0);
        while(!q.empty()){
           int root = q.front(); q.pop();
           if(root == arr.size()-1) return dis[root];
           if(root-1 >= 0 && dis[root-1] == -1){
              q.push(root-1);
              dis[root-1] = dis[root]+1;
           }
           if(root+1 < arr.size() && dis[root+1] == -1){
              q.push(root+1);
              dis[root+1] = dis[root]+1;
           }
           for(auto idx:mp[arr[root]]){
               if(dis[idx]==-1){
                   q.push(idx);
                   dis[idx] = dis[root]+1;
               }
           }

           mp[arr[root]].clear();
        }

        return 0;
    }
};