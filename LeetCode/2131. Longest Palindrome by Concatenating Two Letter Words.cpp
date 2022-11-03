class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int len = words.size();
        for(int i = 0; i < len; i++){
            mp[words[i]]++;
        }
        int res = 0, ck = 0;
        for(auto const&[k,v]:mp){
            if(v==-1) continue;
            int cnt = v;
            if(k[0]==k[1]){
                if(cnt%2!=0) ck = 1;
            } 
            else {
                string s = ""; s.push_back(k[1]); s.push_back(k[0]);
                if(mp.find(s) != mp.end()){
                    cnt = min(cnt, mp[s]) * 2;
                    mp[s]=-1;
                }else cnt = -1;
            }
            
            if(cnt != -1) res+=2*(cnt%2==0?cnt:cnt-1);
        }
        
        return res=ck?res+2:res;
    }
};