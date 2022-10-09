#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int> &pref) {
        vector<int> result = {pref[0]};
        int len = pref.size();
        for (int i = 1; i < len; i++) {
            result.push_back(pref[i] ^ pref[i - 1]);
        }
        return result;
    }
};