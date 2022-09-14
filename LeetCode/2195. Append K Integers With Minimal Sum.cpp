class Solution {
public:
    long long minimalKSum(vector<int> &nums, int k) {

        long long minSum = 0;

        sort(nums.begin(), nums.end());

        int i = 0;
        for (; i < nums.size() && k > 0; i++) {

            long long gap = nums[i] - (i == 0 ? 0 : nums[i - 1]) - 1;

            if (gap > 0) {
                gap = gap > k ? k : gap;
                k -= gap;
                long long b = (i == 0 ? 0 : nums[i - 1]) + gap;
                long long a = i == 0 ? 0 : nums[i - 1];
                minSum += ((b * (b + 1)) / 2) - ((a * (a + 1)) / 2);
            }
        }

        if (k > 0) {
            long long b = nums[i - 1] + k;
            long long a = nums[i - 1];
            minSum += ((b * (b + 1)) / 2) - ((a * (a + 1)) / 2);
        }

        return minSum;
    }
};