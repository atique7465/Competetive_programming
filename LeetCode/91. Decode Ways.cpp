#include <bits/stdc++.h>

using namespace std;

class Solution {

    vector<int> dp;
    vector<pair<int, int>> items;
    int itemsLen = 0;

public:
    int numDecodings(string s) {
        int strLen = s.size();
        int i = 0;
        while (i < strLen) {
            int item = s[i] - '0';
            int digit = 1;
            if (item != 0) {
                if (i + 1 < strLen && s[i + 1] - '0' == 0) {
                    item *= 10;
                    if (item < 1 || item > 26) {
                        return 0;
                    }
                    digit++;
                    i++;
                }
                items.push_back(make_pair(item, digit));
            } else {
                return 0;
            }
            i++;
        }

        itemsLen = items.size();
        dp.resize(itemsLen, -1);

        return solve(0);
    }

    int solve(int i) {

        if (i == itemsLen - 1) {
            return 1;
        } else if (i >= itemsLen) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int res = solve(i + 1);

        if (items[i].second + items[i + 1].second == 2) {
            int item = (items[i].first * 10) + items[i + 1].first;
            if (item > 0 && item < 27) {
                res += (i + 1 == itemsLen - 1) ? 1 : solve(i + 2);
            }
        }

        return dp[i] = res;
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("111111111111111111111111111111111111111111111");
}