#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int result = 0;
        unordered_map<char, int> mp;
        int last = 0, j = 0;

        for (j = 0; j < s.length(); j++) {

            if (mp.find(s[j]) != mp.end() && mp[s[j]] >= last) {
                result = max(result, j - last);
                last = mp[s[j]] + 1;
            }

            mp[s[j]] = j;
        }

        return max(result, j - last);
    }
};