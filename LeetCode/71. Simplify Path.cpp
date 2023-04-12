class Solution {
public:
    string simplifyPath(string path) {
        int i = path.size() - 1; stack<string>st;
        while(i >= 0){
            if(path[i] != '/'){
                int j = i;
                while(j-1 >= 0 && path[j-1] != '/') j--;
                st.push(path.substr(j, i-j+1));
                i = j-1;
            } else{
                i--;
            }
        }

        stack<string> st2;
        while(!st.empty()){
            string s = st.top(); st.pop();
            if(s == ".") continue;
            else if (s == "..") {
                 if (!st2.empty()) st2.pop();
            } 
            else st2.push(s);
        }

        string res = ""; 
        while(!st2.empty()){
            string s = st2.top(); st2.pop();
            res = "/" + s + res;
        }

        return res == "" ? "/" : res;
    }
};