#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {

        if (n == 1) return "1";

        string ret = countAndSay(n - 1);

        string result = "";

        int i = 0, len = ret.size();
        while (i < len) {
            int cnt = 1;
            while (i + 1 < len && ret[i + 1] == ret[i]) {
                cnt++;
                i++;
            }
            result.push_back('0' + cnt);
            result.push_back(ret[i]);
            i++;
        }

        return result;
    }
};