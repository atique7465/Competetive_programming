class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCnt = 0, dCnt = 0; 
        for(int i = 0; i < senate.size(); i++){
            if(senate[i] == 'R') rCnt++;
            else dCnt++;
        }

        while(rCnt > 0 && dCnt > 0){
           for(int i = 0; i < senate.size(); i++){
               if(senate[i] == '*') continue;
               else {
                   char next = senate[i] == 'R' ? 'D' : 'R';
                   int j = i;
                   while(senate[j] != next) j = (j + 1) % senate.size();
                   senate[j] = '*';
                   if(next == 'R') rCnt--; else dCnt--;
               }
               if(rCnt == 0 || dCnt == 0) break;
            }
        }

        return rCnt > 0 ? "Radiant" : "Dire";
    }
};