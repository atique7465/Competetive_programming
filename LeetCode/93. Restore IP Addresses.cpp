class Solution {
    vector<string> result;
public:
    vector<string> restoreIpAddresses(string s) {
        string ip = "";
        solve(0, s, ip, 0, 0);
        return result;
    }

    void solve(int i, string &s, string &ip, int digitCnt, int dotCnt){
        if(i >= s.size()){
            if(dotCnt == 3) {
              if(isValidIp(ip)) result.push_back(ip);
            }
            return;
        }

        if(digitCnt < 3){
         ip.push_back(s[i]); digitCnt++;
         solve(i+1, s, ip, digitCnt, dotCnt);
         ip.pop_back(); digitCnt--;
        }
        
        if(ip.size() > 0 && dotCnt < 3){
          ip.push_back('.'); ip.push_back(s[i]); dotCnt++;
          solve(i+1, s, ip, 1, dotCnt);
          ip.pop_back(); ip.pop_back(); dotCnt--;
        }
    }

    bool isValidIp(string ip){

        int i = 0, j = 0, cnt=0;

        while(i < ip.size() && j < ip.size()){
            while(j < ip.size() && ip[j] != '.') j++;
            string str = ip.substr(i, j - i);
            if((str.size() > 1 && str[0] == '0') || (str.size() > 2 && str > "255")) return false;
            j++; i = j; cnt++;
        }
        
        return cnt == 4;
    }
};