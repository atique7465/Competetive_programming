class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int i = 0, j = 0;
        while(i < s.size() && j < s.size()){
            if(s[i] == ' '){
                i++; j++;
            }else{
                while(j+1 < s.size() && s[j+1] != ' ') j++;
                st.push(s.substr(i, j-i+1));
                j++; i = j;
            }
        }
        
        string res = "";
        while(!st.empty()){
            if(res!="") res+=' ';
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};