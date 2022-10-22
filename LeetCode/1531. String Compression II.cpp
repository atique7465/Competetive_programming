#include <bits/stdc++.h>

using namespace std;

class Solution {

    int dp[101][101];
    int inf = 99999;
    int len;

public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        len = s.size();
        return solve(0, k, s);
    }

    int solve(int start, int k, string &s) {

        cout << start << " " << k << endl;

        int inputK = k;

        if (len - start <= k) return 0;

        if (dp[start][inputK] != -1) {
            return dp[start][inputK];
        }

        int res = k ? solve(start + 1, k - 1, s) : inf;

        int count = 1;
        for (int j = start + 1; j <= len; j++) {
            res = min(res, 1 + getLen(count) + solve(j, k, s));
            if (s[start] == s[j])
                count++;
            else
                k--;

            if (k < 0) break;
        }

        return dp[start][inputK] = res;
    }

    int getLen(int cnt) {
        return cnt >= 100 ? 3 : (cnt >= 10 ? 2 : (cnt > 1 ? 1 : 0));
    }
};


int dp[101][101][27][101];

class Solution_01 {

    int len;
    string str;

public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        str = s;
        len = str.size();
        return solve(0, k, 26, 0);
    }

    int solve(int i, int k, int prev, int prevCnt) {

        if (i >= len) return 0;

        if (dp[i][k][prev][prevCnt] != -1) {
            return dp[i][k][prev][prevCnt];
        }

        int res = k > 0 ? solve(i + 1, k - 1, prev, prevCnt) : INT_MAX;

        if (prev == str[i] - 'a') {
            res = min(res, (needIncr(prevCnt) ? 1 : 0) + solve(i + 1, k, prev, prevCnt + 1));
        } else {
            res = min(res, 1 + solve(i + 1, k, str[i] - 'a', 1));
        }

        return dp[i][k][prev][prevCnt] = res;
    }

    bool needIncr(int cnt) {
        return cnt == 1 || cnt == 9 || cnt == 99;
    }
};