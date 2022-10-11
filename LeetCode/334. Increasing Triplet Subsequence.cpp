#include <bits/stdc++.h>

using namespace std;

/**
 * Maintain two bigger number as small & big, update them on demand, as soon as we found a value bigger than both of them return true. <br>
 * false otherwise <br>
 * T -> O(n)
 */
class Solution_From_Discuss {
public:
    bool increasingTriplet(vector<int> &nums) {

        int small = INT_MAX, big = INT_MAX;

        for (int n: nums) {
            if (n <= small) small = n;
            else if (n <= big) big = n;
            else return true;
        }

        return false;
    }
};

/**
 * If we found a position j where there exist a smaller and bigger value in its left & right we can return true. <br>
 * Track the position in range of [start+1, end-1]
 */
class Solution_Mine {
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