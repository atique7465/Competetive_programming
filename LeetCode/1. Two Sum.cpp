#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        vector<int> result;
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
                break;
            } else {
                hash[nums[i]] = i;
            }
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        vector<int> res;

        vector<pair<int, int>> indexNums;
        for (int i = 0; i < nums.size(); i++) {
            indexNums.push_back(make_pair(nums[i], i));
        }

        sort(indexNums.begin(), indexNums.end());

        for (int i = 0; i < indexNums.size(); i++) {
            cout << indexNums[i].first << " ";
        }

        int i = 0, j = indexNums.size() - 1;

        while (i < j) {

            int sum = indexNums[i].first + indexNums[j].first;

            if (sum == target) {
                res.push_back(indexNums[i].second);
                res.push_back(indexNums[j].second);
                break;
            }

            if (sum < target) {
                i++;
            }

            if (sum > target) {
                j--;
            }
        }

        return res;
    }
};