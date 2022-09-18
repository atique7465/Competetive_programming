#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int mx = 1, mxStart = 0, mxEnd = 0;
        int ln = s.size();
        for (int i = 0; i < ln; i++) {

            int j = i;
            while (j < ln - 1 && s[j] == s[j + 1]) {
                j++;
            }

            int start = i, end = j;
            while (start >= 0 && end <= ln && s[start] == s[end]) {
                start--;
                end++;
            }
            if (mx < end - 1 - start) {
                mx = end - 1 - start;
                mxStart = start + 1;
                mxEnd = end - 1;
            }
        }

        return s.substr(mxStart, mxEnd - mxStart + 1);
    }
};