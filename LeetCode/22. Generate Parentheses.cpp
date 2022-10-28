class Solution {
    vectorstring result;
public
    vectorstring generateParenthesis(int n) {
        string s = (;
        generate(1, 0, s, n);
        return result;
    }
    
    void generate(int i, int j, string &s, int n){
        
        if(i == n && j == n){
            result.push_back(s);
            return;
        }
        
        if(i  n){
            s.push_back('(');
            generate(i+1, j, s, n);
            s.pop_back();
        }
        
        if(j  i){
            s.push_back(')');
            generate(i, j+1, s, n);
            s.pop_back();
        }
    }
};