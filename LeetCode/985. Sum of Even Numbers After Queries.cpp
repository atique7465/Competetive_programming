#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                sum += nums[i];
            }
        }

        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            int currValue = nums[queries[i][1]];
            if (currValue % 2 == 0) {
                if (queries[i][0] % 2 == 0) {
                    sum += queries[i][0];
                } else {
                    sum -= currValue;
                }
            } else {
                if (queries[i][0] % 2 != 0) {
                    sum += currValue + queries[i][0];
                }
            }

            result.push_back(sum);
            nums[queries[i][1]] += queries[i][0];
        }

        return result;
    }
};