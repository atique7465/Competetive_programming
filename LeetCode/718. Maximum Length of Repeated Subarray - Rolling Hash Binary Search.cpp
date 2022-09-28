#include <bits/stdc++.h>

using namespace std;

class RollingHash {

    const int p = 131;
    const int mod = 1e9 + 9;
    vector<long long> p_pow;
    vector<long long> hash;
    int len = 0;
    int power_len = 0;

public:
    RollingHash(vector<int> nums, int pow_len) { // separate power len to mitigate the power diff between to num vector
        len = nums.size();
        power_len = pow_len;
        for (int i = 0; i < power_len; i++) {
            p_pow.push_back(i == 0 ? 1 : (p_pow[i - 1] * p) % mod);
        }

        for (int i = 0; i < len; i++) {
            hash.push_back(((i == 0 ? 0 : hash[i - 1]) + (nums[i] * p_pow[i]) % mod) % mod);
        }
    }

    long getHash(int i, int j) {
        long long h = (hash[j] - (i == 0 ? 0 : hash[i - 1]) + mod) % mod;
        return (h * p_pow[power_len - i - 1]) % mod;
    }

    int getLen() {
        return len;
    }
};

class Solution {

public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {

        RollingHash *rHash1 = new RollingHash(nums1, max(nums1.size(), nums2.size()));
        RollingHash *rHash2 = new RollingHash(nums2, max(nums1.size(), nums2.size()));

        int lo = 0, hi = min(nums1.size(), nums2.size()) + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (hashSubArray(rHash1, rHash2, mid)) {
                lo = mid + 1;
            } else {
                if (mid == 1) {
                    lo = 1;
                }
                hi = mid;
            }
        }

        return lo - 1;
    }

    bool hashSubArray(RollingHash *rHash1, RollingHash *rHash2, int len) {

        map<long long, int> mp;

        for (int i = 0; i < rHash1->getLen() - len + 1; i++) {
            long long h = rHash1->getHash(i, i + len - 1);
            mp[h] = 1;
        }

        for (int i = 0; i < rHash2->getLen() - len + 1; i++) {
            long long h = rHash2->getHash(i, i + len - 1);
            if (mp.find(h) != mp.end()) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {10, 6, 1};
    Solution s;
    cout << s.findLength(nums1, nums2);
}