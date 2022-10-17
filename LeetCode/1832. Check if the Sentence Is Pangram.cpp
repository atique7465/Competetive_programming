#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> freq;
        int cnt = 0;
        for (char c: sentence) {
            if (freq.find(c) == freq.end()) {
                freq[c] = 1;
                cnt++;
            }

            if (cnt == 26) {
                return true;
            }
        }

        return false;
    }
};