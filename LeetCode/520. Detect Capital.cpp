class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCnt=0, smCnt=0;
        for(int i = 0; i < word.size(); i++){
            if(word[i] >='a' && word[i] <='z') smCnt++;
            else capCnt++;
        }
        
        if(smCnt==0 || capCnt==0) return true;
        if(capCnt==1 && word[0] >= 'A' && word[0] <= 'Z') return true;
        return false;
    }
};