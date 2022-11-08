class Solution_stack {
public
    string makeGood(string s) {

        stackcharst;
        for(auto cs){
            if(!st.empty() && abs(c-st.top()) == 32) st.pop();
            else st.push(c);
        }
        
        string res = ;
        while(!st.empty()){
            res.push_back(st.top()); st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution_2P {
public:
    string makeGood(string s) {

        int end = 0, len = s.size();
        for(int i = 0; i < len; i++){
            if(end > 0 && abs(s[i] - s[end-1]) == 32) 
                end--;
            else {
                s[end] = s[i];
                end++;
            }
        }
        
        return s.substr(0, end);
    }
};