class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(string token:tokens){
            if(token.size() == 1 && (token[0] == '+' || token[0] == '-'  || token[0] == '*' || token[0] == '/')){
                long long b = st.top(); st.pop(); long long a = st.top(); st.pop();
                st.push(calc(a,b,token[0]));
            }else{
                long long val = 0, base = 1; int lo = token[0]=='-' ? 1 : 0;
                for(int i = token.size()-1; i>=lo; i--){
                    val += (token[i] - '0') * base;
                    base *= 10;
                }
                st.push(token[0]=='-' ? -1 * val : val);
            }
        }
        return st.top();
    }

    long long calc(long long a, long long b, char op){
        if(op == '+') return a+b;
        else if(op == '-') return a-b;
        else if(op == '*') return a*b;
        else return a/b;
    }
};