class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if(c == ')' || c == '}' || c == ']'){
                if(st.empty() || st.top() != getOpening(c)) return false;
                st.pop();
            }else st.push(c);
        }
        return st.empty();
    }

    char getOpening(char c){
        return c == ')' ? '(' : c == '}' ? '{' : '[';
    }
};