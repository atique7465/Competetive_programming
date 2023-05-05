class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0, j = i; int cnt = 0, res = 0;
        while(j < k) if(isVowel(s[j++])) cnt++;
        res = cnt;
        j = k-1;
        while(j < s.size() - 1){
            if(isVowel(s[i++])) cnt--;
            if(isVowel(s[++j])) cnt++;
            res = max(cnt, res);
        }

        return res;
    }

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};