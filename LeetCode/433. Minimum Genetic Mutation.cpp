class Solution {
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        int len = bank.size();
        unordered_map<string, int> mp;
        for(int i = 0; i < len; i++) mp[bank[i]] = 0;
        
        int res = INT_MAX;
        queue<pair<string, int>>q;
        q.push({start, 0}); mp[start] = 1;
        while(!q.empty()){
            pair<string, int> root =  q.front(); q.pop();
            for(int i = 0; i < len; i++){
                if(!mp[bank[i]] && getDiff(root.first, bank[i]) == 1){
                    if(bank[i] == end) 
                        res = min(res, root.second + 1);
                    else
                    {
                        q.push({bank[i], root.second + 1}); 
                        mp[bank[i]] = 1;
                    }
                }
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
    
    int getDiff(string &s1, string &s2){
        int diff = 0;
        for(int i = 0; i < 8; i++) if(s1[i] != s2[i]) diff++;
        return diff;
    }
};