#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int> &nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = len - 1; i >= 2; i--) {
            int c = nums[i];
            int b = nums[i - 1];
            for (int j = i - 2; j >= 0; j--) {
                if (nums[j] + b > c) {
                    return nums[j] + b + c;
                }
            }
        }

        return 0;
    }
};