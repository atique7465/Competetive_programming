class Solution {
public:
    string reverseVowels(string s) {

        int i = 0, j = s.size() - 1;
        while(i < j){
            while(i < j && !isVawel(s[i])) i++;
            while(j > i && !isVawel(s[j])) j--;
            if(i < j) swap(s[i++], s[j--]);
        }
        
        return s;
    }
    
    bool isVawel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};