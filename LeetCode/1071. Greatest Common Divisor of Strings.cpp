class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int mxLen = _gcd_(str1.size(), str2.size());
        cout<<mxLen<<endl;
        string mxGcd = "";
        while(mxLen > 0){
            string sub1 = str1.substr(0, mxLen);
            string sub2 = str2.substr(0, mxLen);
            if(sub1 == sub2 && concat(sub1, str1.size() / mxLen) == str1 && concat(sub2, str2.size() / mxLen) == str2){
                mxGcd = sub1;
                break;
            }
            mxLen--;
        }

        return mxGcd;
    }

    int _gcd_(int a, int b){
        if (a==0) return b;
        return _gcd_(b%a, a);
    } 

    string concat(string s, int n){
        string res = "";
        while(n--) res += s;
        return res;
    }
};