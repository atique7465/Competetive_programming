#include<bits/stdc++.h>

using namespace std;

class Solution {

    int inf = 999999;

public:
    int threeSumClosest(vector<int> &nums, int target) {

        sort(nums.begin(), nums.end());

        int len = nums.size();
        int closest = inf;

        for (int k = 0; k < len - 2; k++) {
            int i = k + 1, j = len - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;
                }

                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }

        return closest;
    }
};