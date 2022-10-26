#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp = {{0, 0}};
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if (mp.find(rem) != mp.end()) {
                if (mp[rem] < i) {
                    return true;
                }
            } else {
                mp[rem] = i + 1;
            }
        }

        return false;
    }
};