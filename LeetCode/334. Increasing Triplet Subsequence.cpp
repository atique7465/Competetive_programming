#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int len = nums.size();

        if (len < 3) {
            return false;
        }

        int mn = nums[0];
        int mx = nums[len - 1];
        vector<int> hasMin;

        for (int i = 0; i < len; i++) {
            if (nums[i] > mn) {
                hasMin.push_back(1);
            } else {
                hasMin.push_back(0);
            }

            mn = min(mn, nums[i]);
        }

        for (int i = len - 2; i > 0; i--) {
            if (nums[i] < mx && hasMin[i]) {
                return true;
            }

            mx = max(mx, nums[i]);
        }

        return false;
    }
};