#include <bits/stdc++.h>

using namespace std;

class MY_Solution {
public:
    int trap(vector<int> &height) {

        int ln = height.size();
        unordered_map<int, int> mp;

        int i = 0;
        while (i < ln) {
            int j = i + 1;
            while (j < ln && height[i] > height[j]) {
                j++;
            }

            if (j < ln) {
                mp[i] = j;
            }

            i = j;
        }

        i = ln - 1;
        while (i >= 0) {

            int j = i - 1;
            while (j >= 0 && height[i] > height[j]) {
                j--;
            }

            if (j >= 0) {
                mp[j] = i;
            }

            i = j;
        }

        vector<int> cumSum;
        cumSum.push_back(height[0]);
        for (int k = 1; k < ln; k++) {
            cumSum.push_back(cumSum[k - 1] + height[k]);
        }

        int res = 0;
        for (auto const &[k, v]: mp) {
            res += (v - k - 1) * min(height[k], height[v]);
            res -= cumSum[v - 1] - cumSum[k];
        }

        return res;
    }
};

class Ed_4_Solution {
public:
    int trap(vector<int> &height) {

        int res = 0;

        int left = 0, leftMax = 0, right = height.size() - 1, rightMax = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= leftMax ? (leftMax = height[left]) : res += (leftMax - height[left]);
                left++;
            } else {
                height[right] >= rightMax ? (rightMax = height[right]) : res += (rightMax - height[right]);
                right--;
            }
        }

        return res;
    }
};