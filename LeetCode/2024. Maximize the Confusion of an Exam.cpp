class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = 0, f = 0, i = 0, j = 0, ans = 0;
        while(j < answerKey.size()){
            if(answerKey[j++] == 'T') t++; else f++;
            if(k >= min(t,f)) ans = max(ans, t + f);
            else {
                while(k < min(t,f) && i < j){
                if(answerKey[i++] == 'T') t--; else f--;
              }
            }
        }
        return ans;
    }
};