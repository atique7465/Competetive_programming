#include <bits/stdc++.h>

using namespace std;

/*
 * 01. Get the position from where we start to expand on both side
 * 02. Try to expand the range
 */
class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {

        int len = arr.size();
        int pos = 0;

        if (x < arr[0]) {
            pos = 0;
        } else if (x > arr[len - 1]) {
            pos = len - 1;
        } else {
            while (pos + 1 < len && arr[pos + 1] <= x) {
                pos++;
            }

            if (arr[pos] != x) {
                int diff_L = abs(x - arr[pos]);
                int diff_R = abs(arr[pos + 1] - x);
                if (diff_L > diff_R) {
                    pos++;
                } else if (diff_R == diff_L && arr[pos] > arr[pos + 1]) {
                    pos++;
                }
            }
        }

        int i = pos, j = pos;
        k--;
        while (k--) {
            int diff_L = (i == 0) ? INT_MAX : abs(x - arr[i - 1]);
            int diff_R = (j == len - 1) ? INT_MAX : abs(arr[j + 1] - x);
            if (diff_L > diff_R) {
                j++;
            } else if (diff_R == diff_L && i != 0 && j != len - 1 && arr[i - 1] > arr[j + 1]) {
                j++;
            } else {
                i--;
            }
        }

        vector<int> result;
        for (; i <= j; i++) {
            result.push_back(arr[i]);
        }

        return result;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution s;
    vector<int> result = s.findClosestElements(arr, 4, -1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}