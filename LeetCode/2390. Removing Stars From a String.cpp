class Solution {
public:
    string removeStars(string s) {
        int i = s.size() - 1, star = 0;
        while(i >= 0){
            if(s[i] == '*') star++;
            else if(s[i] != '*' && star > 0) {
                   s[i] = '*';
                   star--;
            }
            i--;
        }

        string res = "";
        for(int i = 0; i < s.size(); i++){
          if(s[i]!='*') res += s[i];
        }

        return res;
    }
};