class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> next(s.size(), 0);
        vector<int> nextTot(s.size(), 0);
        for(int i = 0; i < s.size(); i++) nextTot[i] = s[i] == '0' ? 0 : 1;
        for(int i = nextTot.size()-2; i>=0; i--) nextTot[i] += nextTot[i+1];
        int oneIdx = s.size();
        for(int i = s.size()-1; i>=0; i--){
           if(s[i]=='1') {
              next[i] = oneIdx;
              oneIdx = i;
           }
        }
        
        int res = s.size();
        int nextOneIdx = oneIdx, carry = 0;
        while(nextOneIdx < s.size()){
            int curr = carry + s.size() - nextOneIdx - nextTot[nextOneIdx];
            res = min(res, curr);
            if(s.size() - nextOneIdx == nextTot[nextOneIdx]) break;
            carry++;
            nextOneIdx = next[nextOneIdx];
        }

        res = min(res, carry);
        return res;
    }
};