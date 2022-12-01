class Solution {
public:
    bool halvesAreAlike(string s) {
        int hlf=s.size()/2, cnt1=0,cnt2=0;
        if(s.size()%2==0) hlf--;
        
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                if(i<=hlf)
                    cnt1++;
                else
                    cnt2++;
            }
          
        }
       
        return cnt1==cnt2;
    }
    
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
};