#include <bits/stdc++.h>

using namespace std;

/*
for Maximum Length of Repeated Subarray, what if we slide two nums on each other and calculate the length ?
-- 1st step nums1 slides on nums2 in --> direction
-- 2nd step, nums2 slides on nums1 <-- direction
 */
class Solution_sliding {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int res = 0;
        int ln1 = nums1.size(), ln2 = nums2.size();
        for (int i = 0; i < nums1.size(); i++) {
            int ci = i, j = 0;
            while (ci < ln1 && j < ln2) {
                if (nums1[ci] == nums2[j]) {
                    int local = 0;
                    while (ci < ln1 && j < ln2 && nums1[ci] == nums2[j]) {
                        ci++;
                        j++;
                        local++;
                    }
                    if (res < local) res = local;
                } else {
                    ci++;
                    j++;
                }
            }
        }

        for (int j = 0; j < nums2.size(); j++) {
            int cj = j, i = 0;
            while (cj < ln2 && i < ln1) {
                if (nums2[cj] == nums1[i]) {
                    int local = 0;
                    while (cj < ln2 && i < ln1 && nums2[cj] == nums1[i]) {
                        cj++;
                        i++;
                        local++;
                    }
                    if (res < local) res = local;
                } else {
                    cj++;
                    i++;
                }
            }
        }

        return res;
    }
};

int dp_lcs[1010][1010];

class Solution_Iterative_LCS {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        memset(dp_lcs, 0, sizeof(dp_lcs));
        int res = 0;
        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp_lcs[i][j] = dp_lcs[i + 1][j + 1] + 1;
                    if (res < dp_lcs[i][j]) {
                        res = dp_lcs[i][j];
                    }
                }
            }
        }

        return res;
    }

};

//------------Recursive DP Not working-------------------//
//int dp[1010][1010];
//
//class Solution_Recursive_LCS {
//
//public:
//    int findLength(vector<int> &nums1, vector<int> &nums2) {
//        memset(dp, -1, sizeof(dp));
//        return solve(0, 0, 0, nums1, nums2);
//    }
//
//public:
//    int solve(int i, int j, int count, vector<int> &nums1, vector<int> &nums2) {
//
//        if (i >= nums1.size() || j >= nums2.size()) {
//            return count;
//        }
//
//        if (dp[i][j] != -1) {
//            return dp[i][j];
//        }
//
//        if (nums1[i] == nums2[j]) {
//            count = solve(i + 1, j + 1, 1 + count, nums1, nums2);
//        }
//
//        count = max(count, max(solve(i, j + 1, 0, nums1, nums2), solve(i + 1, j, 0, nums1, nums2)));
//
//        return dp[i][j] = count;
//    }
//};

int main() {
    vector<int> nums1 = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    vector<int> nums2 = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
    Solution_Iterative_LCS s;
    cout << s.findLength(nums1, nums2);
}